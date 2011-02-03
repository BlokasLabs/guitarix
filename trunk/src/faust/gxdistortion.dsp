declare name 		"gxdistortion";
declare version 	"0.01";
declare author 		"brummer";
declare license 	"BSD";
declare copyright 	"(c)brummer 2008";


import("math.lib");
import("music.lib");
import("effect.lib"); 
import("filter.lib");
import("guitarix.lib");
import("maxmsp.lib");

F = 300; //nentry("split_low_freq", 250, 20, 600, 10);
F1 = 1200; //nentry("split_middle_freq", 650, 600, 1250, 10);
F2 = 3200; //nentry("split_high_freq", 1250, 1250, 12000, 10);

/**********************************************************************
*** this part is included here for backward compatibility from 0.9.27 to
*** 0.9.24 
***********************************************************************/

//------------------------------ count and take --------------------------------------

countN ((xs, xxs)) = 1 + countN(xxs);
countN (xx) = 1;

takeN (1, (xs, xxs))     = xs;
takeN (1, xs)                    = xs;
takeN (nn, (xs, xxs))    = takeN (nn-1, xxs);

//------------------------------ low/high-passfilters --------------------------------------

tf1N(b0,b1,a1) = _ <: *(b0), (mem : *(b1)) :> + ~ *(0-a1);

tf2N(b0,b1,b2,a1,a2) = sub ~ conv2(a1,a2) : conv3(b0,b1,b2)
with {
  conv3(k0,k1,k2,x)     = k0*x + k1*x' + k2*x'';
  conv2(k0,k1,x)        = k0*x + k1*x';
  sub(x,y)              = y-x;
};

tf1sN(b1,b0,a0,w1) = tf1N(b0d,b1d,a1d)
with {
  c   = 1/tan((w1)*0.5/SR); // bilinear-transform scale-factor
  d   = a0 + c;
  b1d = (b0 - b1*c) / d;
  b0d = (b0 + b1*c) / d;
  a1d = (a0 - c) / d;
};

tf2sN(b2,b1,b0,a1,a0,w1) = tf2N(b0d,b1d,b2d,a1d,a2d)
with {
  c   = 1/tan((w1)*0.5/SR); // bilinear-transform scale-factor
  csq = c*c;
  d   = a0 + a1 * c + csq;
  b0d = (b0 + b1 * c + b2 * csq)/d;
  b1d = 2 * (b0 - b2 * csq)/d;
  b2d = (b0 - b1 * c + b2 * csq)/d;
  a1d = 2 * (a0 - csq)/d;
  a2d = (a0 - a1*c + csq)/d;
};

lowpassN(N,fc) = lowpass0_highpass1N(0,N,fc);
highpassN(N,fc) = lowpass0_highpass1N(1,N,fc);
lowpass0_highpass1N(s,N,fc) = lphpr(s,N,N,fc)
with {
  lphpr(s,0,N,fc) = _;
  lphpr(s,1,N,fc) = tf1sN(s,1-s,1,2*PI*fc);
  lphpr(s,O,N,fc) = lphpr(s,(O-2),N,fc) : tf2sN(s,0,1-s,a1s,1,w1) with {
    parity = N % 2;
    S = (O-parity)/2; // current section number
    a1s = -2*cos(-PI + (1-parity)*PI/(2*N) + (S-1+parity)*PI/N);
    w1 = 2*PI*fc;
  };
};

//------------------------------ analyzer --------------------------------------
analyzern(O,lfreqs) = _ <: bsplit(nb) with
{
   nb = countN(lfreqs);
   fc(n) = takeN(n, lfreqs);
   lp(n) = lowpassN(O,fc(n));
   hp(n) = highpassN(O,fc(n));
   bsplit(0) = _;
   bsplit(i) = hp(i), (lp(i) <: bsplit(i-1));
};

analyzerN(lfreqs) = analyzern(3,lfreqs);

filterbankn(O,lfreqs) = analyzern(O,lfreqs) : delayeq with
{
   nb = count(lfreqs);
   fc(n) = take(n, lfreqs);
   ap(n) = highpass_plus_lowpass(O,fc(n));
   delayeq = par(i,nb-1,apchain(nb-1-i)),_,_;
   apchain(0) = _;
   apchain(i) =  ap(i) : apchain(i-1);
};

filterbankN(lfreqs) = filterbankn(3,lfreqs);

/**********************************************************************
*** end for backward compatibility from 0.9.27 to
*** 0.9.24 , it could removed when switch completly to > 0.9.27
***********************************************************************/

//----------distortion---------

//-distortion
drive			= vslider("drive", 0.35, 0, 1, 0.01);

distortion1 	=  _:cubicnl(0.45*drive,0.0): *(8.0); 
distortion2 	=  _:cubicnl(0.4*drive,0.0) : *(4.0);
distortion3 	=  _:cubicnl(1.0*drive,0.0) : *(8.0);
distortion4 	=  _:cubicnl(0.6*drive,0.0) : *(5.0);
distortion	= _ : filterbankN((F,(F1,F2))) : distortion2,distortion4 ,distortion3,distortion1 :>_;

//-resonator
resonator 		= (+ <: (delay(4096, 0.5) + delay(4096, 0.5)) / 2) ~ *(0.5);

fx = (-0.4)*(drive*64): db2linear : smoothi(0.999);

process 		=  distortion ;
