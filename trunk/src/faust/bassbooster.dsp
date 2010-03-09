import("filter.lib");

//------------------------------------------------------------------
// DAFX, Digital Audio Effects (Wiley ed.)
// chapter 2 : filters
// section 2.3 : Equalizers
// page 53 : second order shelving filter design
//------------------------------------------------------------------

lfboost(F,G) = tf2(b0,b1,b2,a0,a1)
with {
  V = db2linear(G);
  K = tan(PI*F/SR);
  D = 1 + sqrt(2)*K + K*K;

  b0 = (1 + sqrt(2*V)*K + V*K*K) / D;
  b1 = 2 * (V*K*K - 1) / D;
  b2 = (1 - sqrt(2*V)*K + V*K*K) / D;
  a0 = 2 * (K*K - 1) / D;
  a1 = (1 - sqrt(2)*K + K*K) / D;
};

process = lfboost(120, 10);
