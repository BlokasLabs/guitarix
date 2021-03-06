// generated from file '../src/LV2/faust/gxtilttone.dsp' by dsp2cc:
// Code generated with Faust 0.9.65 (http://faust.grame.fr)

#include "valve.h"

namespace gxtilttone {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec0[2];
	double 	fVec0[2];
	double 	fRec10[2];
	double 	fRec9[3];
	double 	fVec1[2];
	int 	iConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fRec11[2];
	double 	fRec8[2];
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	double 	fConst8;
	double 	fConst9;
	double 	fRec7[2];
	double 	fConst10;
	double 	fConst11;
	double 	fConst12;
	double 	fConst13;
	double 	fRec6[2];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fConst14;
	double 	fConst15;
	double 	fConst16;
	double 	fConst17;
	double 	fConst18;
	double 	fRec12[2];
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec13[2];
	double 	fVec2[2];
	double 	fConst19;
	double 	fConst20;
	double 	fConst21;
	double 	fConst22;
	double 	fRec5[2];
	double 	fVec3[2];
	double 	fRec4[2];
	double 	fRec3[3];
	double 	fVec4[2];
	double 	fRec14[2];
	double 	fRec2[2];
	double 	fRec1[2];
	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "gxtilttone";
	name = N_("Gx Tilt Tone");
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fVec0[i] = 0;
	for (int i=0; i<2; i++) fRec10[i] = 0;
	for (int i=0; i<3; i++) fRec9[i] = 0;
	for (int i=0; i<2; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec11[i] = 0;
	for (int i=0; i<2; i++) fRec8[i] = 0;
	for (int i=0; i<2; i++) fRec7[i] = 0;
	for (int i=0; i<2; i++) fRec6[i] = 0;
	for (int i=0; i<2; i++) fRec12[i] = 0;
	for (int i=0; i<2; i++) fRec13[i] = 0;
	for (int i=0; i<2; i++) fVec2[i] = 0;
	for (int i=0; i<2; i++) fRec5[i] = 0;
	for (int i=0; i<2; i++) fVec3[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<3; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fVec4[i] = 0;
	for (int i=0; i<2; i++) fRec14[i] = 0;
	for (int i=0; i<2; i++) fRec2[i] = 0;
	for (int i=0; i<2; i++) fRec1[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = (1.0 / tan((270.1769682087222 / double(iConst0))));
	fConst2 = (1 + fConst1);
	fConst3 = (1.0 / fConst2);
	fConst4 = (0 - ((1 - fConst1) / fConst2));
	fConst5 = (1.0 / tan((97.38937226128358 / double(iConst0))));
	fConst6 = (0 - fConst5);
	fConst7 = (1 + fConst5);
	fConst8 = (0.025 / fConst7);
	fConst9 = (0 - ((1 - fConst5) / fConst7));
	fConst10 = (1.0 / tan((1281.7698026646356 / double(iConst0))));
	fConst11 = (1 + fConst10);
	fConst12 = (1.0 / fConst11);
	fConst13 = (0 - ((1 - fConst10) / fConst11));
	fConst14 = (1.0 / tan((5830.795965062656 / double(iConst0))));
	fConst15 = (0 - fConst14);
	fConst16 = (1 + fConst14);
	fConst17 = (1.0 / fConst16);
	fConst18 = (0 - ((1 - fConst14) / fConst16));
	fConst19 = (1.0 / tan((20517.741620594938 / double(iConst0))));
	fConst20 = (1 + fConst19);
	fConst21 = (1.0 / fConst20);
	fConst22 = (0 - ((1 - fConst19) / fConst20));
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fslider0 (*fslider0_)
#define fslider1 (*fslider1_)
#define fslider2 (*fslider2_)
	double 	fSlow0 = (0.0010000000000000009 * pow(10,(0.05 * double(fslider0))));
	double 	fSlow1 = double(fslider1);
	double 	fSlow2 = (1 - fSlow1);
	double 	fSlow3 = (0.0010000000000000009 * pow(10,(0.05 * double(fslider2))));
	for (int i=0; i<count; i++) {
		fRec0[0] = ((0.999 * fRec0[1]) + fSlow0);
		double fTemp0 = (1e-15 + ((double)input0[i] * fRec0[0]));
		fVec0[0] = fTemp0;
		fRec10[0] = ((0.9302847925323914 * (fVec0[0] + fVec0[1])) - (0.8605695850647829 * fRec10[1]));
		fRec9[0] = (fRec10[0] - ((1.8405051250752198 * fRec9[1]) + (0.8612942439318627 * fRec9[2])));
		double fTemp1 = (1e-15 + (0.027 * fRec8[1]));
		fVec1[0] = fTemp1;
		fRec11[0] = ((fConst4 * fRec11[1]) + (fConst3 * (fVec1[0] + fVec1[1])));
		fRec8[0] = (Ftube(TUBE_TABLE_12AX7_68k, ((fRec11[0] + (0.9254498422517706 * (fRec9[2] + (fRec9[0] + (2.0 * fRec9[1]))))) - 1.581656)) - 191.42014814814814);
		fRec7[0] = ((fConst9 * fRec7[1]) + (fConst8 * ((fConst5 * fRec8[0]) + (fConst6 * fRec8[1]))));
		fRec6[0] = ((fConst13 * fRec6[1]) + (fConst12 * (fRec7[0] + fRec7[1])));
		fRec12[0] = ((fConst18 * fRec12[1]) + (fConst17 * ((fConst14 * fRec7[0]) + (fConst15 * fRec7[1]))));
		fRec13[0] = ((0.999 * fRec13[1]) + fSlow3);
		double fTemp2 = (fRec13[0] * ((fSlow1 * fRec12[0]) + (fSlow2 * fRec6[0])));
		fVec2[0] = fTemp2;
		fRec5[0] = ((fConst22 * fRec5[1]) + (fConst21 * (fVec2[0] + fVec2[1])));
		double fTemp3 = (1e-15 + fRec5[0]);
		fVec3[0] = fTemp3;
		fRec4[0] = ((0.9302847925323914 * (fVec3[0] + fVec3[1])) - (0.8605695850647829 * fRec4[1]));
		fRec3[0] = (fRec4[0] - ((1.8405051250752198 * fRec3[1]) + (0.8612942439318627 * fRec3[2])));
		double fTemp4 = (1e-15 + (0.027 * fRec2[1]));
		fVec4[0] = fTemp4;
		fRec14[0] = ((fConst4 * fRec14[1]) + (fConst3 * (fVec4[0] + fVec4[1])));
		fRec2[0] = (Ftube(TUBE_TABLE_12AX7_68k, ((fRec14[0] + (0.9254498422517706 * (fRec3[2] + (fRec3[0] + (2.0 * fRec3[1]))))) - 1.581656)) - 191.42014814814814);
		fRec1[0] = ((fConst9 * fRec1[1]) + (fConst8 * ((fConst5 * fRec2[0]) + (fConst6 * fRec2[1]))));
		output0[i] = (FAUSTFLOAT)(fRec1[0] / fRec0[0]);
		// post processing
		fRec1[1] = fRec1[0];
		fRec2[1] = fRec2[0];
		fRec14[1] = fRec14[0];
		fVec4[1] = fVec4[0];
		fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
		fRec4[1] = fRec4[0];
		fVec3[1] = fVec3[0];
		fRec5[1] = fRec5[0];
		fVec2[1] = fVec2[0];
		fRec13[1] = fRec13[0];
		fRec12[1] = fRec12[0];
		fRec6[1] = fRec6[0];
		fRec7[1] = fRec7[0];
		fRec8[1] = fRec8[0];
		fRec11[1] = fRec11[0];
		fVec1[1] = fVec1[0];
		fRec9[2] = fRec9[1]; fRec9[1] = fRec9[0];
		fRec10[1] = fRec10[0];
		fVec0[1] = fVec0[0];
		fRec0[1] = fRec0[0];
	}
#undef fslider0
#undef fslider1
#undef fslider2
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case DRIVE: 
		fslider0_ = (float*)data; // , 0.0, 0.0, 2e+01, 0.1 
		break;
	case GAIN: 
		fslider2_ = (float*)data; // , 0.0, 0.0, 2e+01, 0.1 
		break;
	case TONE: 
		fslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
   DRIVE, 
   GAIN, 
   TONE, 
} PortIndex;
*/

} // end namespace gxtilttone
