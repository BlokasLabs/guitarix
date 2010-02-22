namespace overdrive {
// generated from file '../src/faust/overdrive.dsp'

FAUSTFLOAT 	fslider0;
int	fSamplingFreq;

void init(int samplingFreq)
{
	fSamplingFreq = samplingFreq;
}

void compute(int count, float *input0, float *output0)
{
	float 	fSlow0 = fslider0;
	float 	fSlow1 = (fSlow0 - 1);
	for (int i=0; i<count; i++) {
		float fTemp0 = (float)input0[i];
		float fTemp1 = fabsf(fTemp0);
		float 	fRec0 = (0.999f + (1.000000e-03f * powf(10,(5.000000e-02f * (0 - (0.5f * fSlow0))))));
		output0[i] = (FAUSTFLOAT)(((fTemp0 * fRec0) * (fSlow0 + fTemp1)) / (1 + ((fSlow1 * fTemp1) + (fTemp0 * fTemp0))));
	}
}

static struct RegisterParams { RegisterParams(); } RegisterParams;
RegisterParams::RegisterParams()
{
	registerVar("overdrive.drive","","S","",&fslider0, 1.0f, 1.0f, 20.0f, 0.1f);
	registerInit(init);
}

} // end namespace overdrive
