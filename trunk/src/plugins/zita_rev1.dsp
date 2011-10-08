declare id "zita_rev1";
declare name "Zita Rev1";

import("filter.lib");

//** from filter.lib v0.9.43

//------------------------------- peak_eq_rm ---------------------------------
// Regalia-Mitra second order peaking equalizer section
// USAGE: _ : peak_eq_rm(Lfx,fx,tanPiBT) : _;
// where
//     Lfx = level (dB) at fx
//      fx = boost or cut frequency (Hz)
// tanPiBT = tan(PI*B/SR), where B = -3dB bandwidth (Hz) when 10^(Lfx/20) = 0
//         ~ PI*B/SR for narrow bandwidths B
//
// REFERENCE: 
//   P.A. Regalia, S.K. Mitra, and P.P. Vaidyanathan,
//   "The Digital All-Pass Filter: A Versatile Signal Processing Building Block"
//   Proceedings of the IEEE, 76(1):19-37, Jan. 1988.  (See pp. 29-30.)
//
peak_eq_rm(Lfx,fx,tanPiBT) = _ <: _,A,_ : +,- : *(0.5),*(K/2.0) : + with {
  A = tf2(k2, k1*(1+k2), 1, k1*(1+k2), k2) <: _,_; // allpass
  k1 = 0.0 - cos(2.0*PI*fx/SR);
  k2 = (1.0 - tanPiBT)/(1.0 + tanPiBT);
  K = db2linear(Lfx);
};

//** from effect.lib v0.9.43

//------------------------------- zita_rev_fdn -------------------------------
// Internal 8x8 late-reverberation FDN used in the FOSS Linux reverb zita-rev1
// by Fons Adriaensen <fons@linuxaudio.org>.  This is an FDN reverb with
// allpass comb filters in each feedback delay in addition to the 
// damping filters.
//
// USAGE: 
//   bus(8) : zita_rev_fdn(f1,f2,t60dc,t60m,fsmax) : bus(8)
//
// WHERE 
//   f1    = crossover frequency (Hz) separating dc and midrange frequencies
//   f2    = frequency (Hz) above f1 where T60 = t60m/2 (see below)
//   t60dc = desired decay time (t60) at frequency 0 (sec)
//   t60m  = desired decay time (t60) at midrange frequencies (sec)
//   fsmax = maximum sampling rate to be used (Hz)
//
// REFERENCES:
//   http://www.kokkinizita.net/linuxaudio/zita-rev1-doc/quickguide.html
//   https://ccrma.stanford.edu/~jos/pasp/Zita_Rev1.html
//
// DEPENDENCIES: 
//   filter.lib (allpass_comb, lowpass, smooth)
//   math.lib (hadamard, take, etc.)

zita_rev_fdn(f1,f2,t60dc,t60m,fsmax) =
  ((bus(2*N) :> allpass_combs(N) : feedbackmatrix(N)) ~
   (delayfilters(N,freqs,durs) : fbdelaylines(N)))
with {
  N = 8;

  // Delay-line lengths in seconds:
  apdelays = (0.020346, 0.024421, 0.031604, 0.027333, 0.022904, 
              0.029291, 0.013458, 0.019123); // feedforward delays in seconds
  tdelays = ( 0.153129, 0.210389, 0.127837, 0.256891, 0.174713, 
              0.192303, 0.125000, 0.219991); // total delays in seconds
  tdelay(i) = floor(0.5 + SR*take(i+1,tdelays)); // samples
  apdelay(i) = floor(0.5 + SR*take(i+1,apdelays));
  fbdelay(i) = tdelay(i) - apdelay(i);
  // NOTE: Since SR is not bounded at compile time, we can't use it to
  // allocate delay lines; hence, the fsmax parameter:
  tdelaymaxfs(i) = floor(0.5 + fsmax*take(i+1,tdelays));
  apdelaymaxfs(i) = floor(0.5 + fsmax*take(i+1,apdelays));
  fbdelaymaxfs(i) = tdelaymaxfs(i) - apdelaymaxfs(i);
  nextpow2(x) = ceil(log(x)/log(2.0));
  maxapdelay(i) = int(2.0^max(1.0,nextpow2(apdelaymaxfs(i))));
  maxfbdelay(i) = int(2.0^max(1.0,nextpow2(fbdelaymaxfs(i))));

  apcoeff(i) = select2(i&1,0.6,-0.6);  // allpass comb-filter coefficient
  allpass_combs(N) = 
    par(i,N,(allpass_comb(maxapdelay(i),apdelay(i),apcoeff(i)))); // filter.lib
  fbdelaylines(N) = par(i,N,(delay(maxfbdelay(i),(fbdelay(i)))));
  freqs = (f1,f2); durs = (t60dc,t60m);
  delayfilters(N,freqs,durs) = par(i,N,filter(i,freqs,durs));
  feedbackmatrix(N) = hadamard(N); // math.lib

  staynormal = 10.0^(-20); // let signals decay well below LSB, but not to zero

  special_lowpass(g,f) = smooth(p) with {
    // unity-dc-gain lowpass needs gain g at frequency f => quadratic formula:
    p = mbo2 - sqrt(mbo2*mbo2 - 1.0); // other solution is unstable
    mbo2 = (1.0 - gs*c)/(1.0 - gs); // NOTE: must ensure |g|<1 (t60m finite)
    gs = g*g;
    c = cos(2.0*PI*f/float(SR));
  };

  filter(i,freqs,durs) = lowshelf_lowpass(i)/sqrt(float(N))+staynormal
  with {
    lowshelf_lowpass(i) = gM*low_shelf1_l(g0/gM,f(1)):special_lowpass(gM,f(2));
    low_shelf1_l(G0,fx,x) = x + (G0-1)*lowpass(1,fx,x); // filter.lib
    g0 = g(0,i);
    gM = g(1,i);
    f(k) = take(k,freqs);
    dur(j) = take(j+1,durs);
    n60(j) = dur(j)*SR; // decay time in samples
    g(j,i) = exp(-3.0*log(10.0)*tdelay(i)/n60(j));
  };
};

// Stereo input delay used by zita_rev1 in both stereo and ambisonics mode:
zita_in_delay(rdel) = zita_delay_mono(rdel), zita_delay_mono(rdel) with {
  zita_delay_mono(rdel) = delay(8192,SR*rdel*0.001) * 0.3;
};

// Stereo input mapping used by zita_rev1 in both stereo and ambisonics mode:
zita_distrib2(N) = _,_ <: fanflip(N) with {
   fanflip(4) = _,_,*(-1),*(-1);
   fanflip(N) = fanflip(N/2),fanflip(N/2);
};

//---------------------------- zita_rev1_stereo ---------------------------
// Extend zita_rev_fdn to include zita_rev1 input/output mapping in stereo mode.
//
// USAGE:
//   _,_ : zita_rev1_stereo(rdel,f1,f2,t60dc,t60m,fsmax) : _,_
//
// WHERE
//   rdel  = delay (in ms) before reverberation begins (e.g., 0 to ~100 ms)
//   (remaining args and refs as for zita_rev_fdn above)

zita_rev1_stereo(rdel,f1,f2,t60dc,t60m,fsmax) =
   zita_in_delay(rdel)
 : zita_distrib2(N)
 : zita_rev_fdn(f1,f2,t60dc,t60m,fsmax)
 : output2(N)
with {
 N = 8;
 output2(N) = outmix(N) : *(t1),*(t1);
 t1 = 0.37; // zita-rev1 linearly ramps from 0 to t1 over one buffer
 outmix(4) = !,butterfly(2),!; // probably the result of some experimenting!
 outmix(N) = outmix(N/2),par(i,N/2,!);

};

//----------------------------- zita_rev1_ambi ---------------------------
// Extend zita_rev_fdn to include zita_rev1 input/output mapping in
// ambisonics mode.
//
// USAGE:
//   _,_ : zita_rev1_ambi(rgxyz,rdel,f1,f2,t60dc,t60m,fsmax) : _,_
//
// WHERE
//   rgxyz = relative gain of lanes 1,4,2 to lane 0 in output (e.g., -9 to 9)
//   (remaining args and refs as for zita_rev1_stereo above)

zita_rev1_ambi(rgxyz,rdel,f1,f2,t60dc,t60m,fsmax) =
   zita_in_delay(rdel)
 : zita_distrib2(N)
 : zita_rev_fdn(f1,f2,t60dc,t60m,fsmax)
 : output4(N) // ambisonics mode
with {
  N=8;
  output4(N) = select4 : *(t0),*(t1),*(t1),*(t1);
  select4 = _,_,_,!,_,!,!,! : _,_,cross with { cross(x,y) = y,x; };
  t0 = 1.0/sqrt(2.0);
  t1 = t0 * 10.0^(0.05 * rgxyz);
};

//---------------------------------- zita_rev1 ------------------------------
// Example GUI for zita_rev1_stereo (mostly following the Linux zita-rev1 GUI).
//
// Only the dry/wet and output level parameters are "dezippered" here.  If 
// parameters are to be varied in real time, use "smooth(0.999)" or the like
// in the same way.
//
// REFERENCE: 
//   http://www.kokkinizita.net/linuxaudio/zita-rev1-doc/quickguide.html
//
// DEPENDENCIES: 
//   filter.lib (peak_eq_rm)

zita_rev1(x,y) = zita_rev1_stereo(rdel,f1,f2,t60dc,t60m,fsmax,x,y)
	  : out_eq : dry_wet(x,y) : out_level
with {

  fsmax = 48000.0;  // highest sampling rate that will be used

  fdn_group(x) = hgroup(
    "zita_rev1[name:Zita_Rev1] [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER ALLPASS-COMB REVERBERATOR (8x8). See Faust's effect.lib for documentation and references]", x);

  in_group(x) = fdn_group(hgroup("g1[name:Input]", x));

  rdel = in_group(vslider("in_delay[name:In Delay] [unit:ms] [style:knob] 
                  [tooltip: Delay in ms before reverberation begins]",
                  60,20,100,1));

  freq_group(x) = fdn_group(hgroup("g2[name:Decay Times in Bands (see tooltips)]", x));

  f1 = freq_group(vslider("lf_x[name:LF X] [unit:Hz] [style:knob] 
       [tooltip: Crossover frequency (Hz) separating low and middle frequencies]",
       200, 50, 1000, 1));

  t60dc = freq_group(vslider("low_rt60[name:Low RT60] [unit:s] [style:knob] 
          [style:knob] [tooltip: T60 = time (in seconds) to decay 60dB in low-frequency band]", 
	  3, 1, 8, 0.1));

  t60m = freq_group(vslider("mid_rt60[name:Mid RT60] [unit:s] [style:knob]
          [tooltip: T60 = time (in seconds) to decay 60dB in middle band]", 
	  2, 1, 8, 0.1));

  f2 = freq_group(vslider("hf_damping[name:HF Damping] [unit:Hz] [style:knob]
       [tooltip: Frequency (Hz) at which the high-frequency T60 is half the middle-band's T60]",
       6000, 1500, 0.49*fsmax, 1));

  out_eq = pareq_stereo(eq1f,eq1l,eq1q) : pareq_stereo(eq2f,eq2l,eq2q);
// Zolzer style peaking eq (not used in zita-rev1) (filter.lib):
// pareq_stereo(eqf,eql,Q) = peak_eq(eql,eqf,eqf/Q), peak_eq(eql,eqf,eqf/Q);
// Regalia-Mitra peaking eq with "Q" hard-wired near sqrt(g)/2 (filter.lib):
  pareq_stereo(eqf,eql,Q) = peak_eq_rm(eql,eqf,tpbt), peak_eq_rm(eql,eqf,tpbt)
  with {
    tpbt = wcT/sqrt(g); // tan(PI*B/SR) where B bandwidth in Hz (Q^2 ~ g/4)
    wcT = 2*PI*eqf/SR;  // peak frequency in rad/sample
    g = db2linear(eql); // peak gain
  };

  eq1_group(x) = fdn_group(hgroup("g3[name:RM Peaking Equalizer 1]", x));

  eq1f = eq1_group(vslider("eq1_freq[name:Eq1 Freq] [unit:Hz] [style:knob]
       [tooltip: Center-frequency of second-order Regalia-Mitra peaking equalizer section 1]",
       315, 40, 2500, 1));
  
  eq1l = eq1_group(vslider("eq1_level[name:Eq1 Level] [unit:dB] [style:knob]
       [tooltip: Peak level in dB of second-order Regalia-Mitra peaking equalizer section 1]",
       0, -15, 15, 0.1));
  
  eq1q = eq1_group(vslider("eq1_q[name:Eq1 Q] [style:knob]
       [tooltip: Q = centerFrequency/bandwidth of second-order peaking equalizer section 1]",
       3, 0.1, 10, 0.1));
  
  eq2_group(x) = fdn_group(hgroup("g4[name:RM Peaking Equalizer 2]", x));

  eq2f = eq2_group(vslider("eq2_freq[name:Eq2 Freq] [unit:Hz] [style:knob]
       [tooltip: Center-frequency of second-order Regalia-Mitra peaking equalizer section 2]",
       315, 40, 2500, 1));
  
  eq2l = eq2_group(vslider("eq2_level[name:Eq2 Level] [unit:dB] [style:knob]
       [tooltip: Peak level in dB of second-order Regalia-Mitra peaking equalizer section 2]",
       0, -15, 15, 0.1));

  eq2q = eq2_group(vslider("eq2_q[name:Eq2 Q] [style:knob]
       [tooltip: Q = centerFrequency/bandwidth of second-order peaking equalizer section 2]",
       3, 0.1, 10, 0.1));
  
  out_group(x)  = fdn_group(hgroup("g5[name:Output]", x));

  dry_wet(x,y) = *(wet) + dry*x, *(wet) + dry*y with { 
    wet = 0.5*(drywet+1.0);
    dry = 1.0-wet; 
  };

  drywet = out_group(vslider("dry_wet_mix[name:Dry/Wet Mix] [style:knob]
       [tooltip: -1 = dry, 1 = wet]",
       0, -1.0, 1.0, 0.01)) : smooth(0.999);

  out_level = *(gain),*(gain);

  gain = out_group(vslider("level[name:Level] [unit:dB] [style:knob]
    [tooltip: Output scale factor]", -40, -70, 40, 0.1)) 
    : smooth(0.999) : db2linear; 

};

process = zita_rev1;
