declare id   "bassEnhancer";
declare name "Bass Enhancer";
declare category "Misc";

//------------------------------------
//Based at:
//"LOW COMPLEXITY VIRTUAL BASS ENHANCEMENT ALGORITHM FOR PORTABLE MULTIMEDIA DEVICE"
//MANISH ARORA, HAN-GIL MOON, AND SEONGCHEOL JANG
//Audio lab, DM R&D Center, Samsung Electronics co. Ltd, Suwon, South Korea
//------------------------------------

import("filter.lib");
import("effect.lib");

//Controls
lp_freq = hslider("Frequency",100,60,240,5);
harmonics_volume = hslider("HarmonicsdB",0, -16, +32, 0.1): db2linear : smooth(0.999);

//Can be moved to .lib
X = (_,_)<:(!,_,_,!);
switch(c,x,y) = sel(c,x,y)
with { 
	sel(c,x,y) = (1-c)*x + c*y; 
};

//NLD and consts
harm1 = 0.03;
harm2 = 0.015;
get_const(a,b,x,y) = (x <= y)*a + (x > y)*b;
nld1(a,b) = _<:(_,_,X,_,_:_,X,_,_,_:((get_const(a,b):1-_),_,get_const(a,b),_):(_*_,_*_:(_+_)))~_~_~_;

process = _,_<:hp_branch,(_,_:>lp_branch<:_,_),(_,_:>be_branch<:_,_),hp_branch:>_,_ 
with {
	hp_branch = dcblockerat(20) : highpass(8, lp_freq);
	lp_branch = dcblockerat(20) : lowpass(8,lp_freq);
	be_branch = lowpass(8,lp_freq) : nld1(harm1,harm2) : _*harmonics_volume; 
};


