declare name "ampmodul";

import("guitarix.lib");

feedback = hslider("feedback", 0, -1, 1, 0.01);
fbackw = (- : neg ) ~ (feedback * _'''');

feedbac = hslider("feedbac", 0, -1, 1, 0.01);
fback = (- : neg ) ~ (feedbac * _'''');

preamp =  (vslider("tube1",6,-20,20,0.1):db2linear : smoothi(0.999)); 
gain1 = vslider("tube2", 6, -20.0, 20.0, 0.1) : db2linear : smoothi(0.999);
gain = vslider("level", -20, -40, 4, 0.1) : db2linear : smoothi(0.999);

wet_dry = vslider("wet_dry", 0, -1, 1, 0.1);
balanc(b) = *(1 - max(0, b)), *(1 - max(0, -b));
wet_dry_mx(w, Fx) = _ <: (_:fback), Fx : balanc(w) : +;

process = wet_dry_mx(wet_dry, _:(*(gain) : component("gxamp2.dsp").tubec(preamp,gain1):fbackw)), wet_dry_mx(wet_dry, _:(*(gain) : component("gxamp2.dsp").tubec(preamp,gain1):fbackw));
