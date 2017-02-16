// generated from file '../src/LV2/faust/cstb.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)

#include "trany.h"

namespace cstb {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	int 	iConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec8[2];
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec9[2];
	double 	fConst8;
	double 	fConst9;
	double 	fConst10;
	double 	fConst11;
	double 	fConst12;
	double 	fConst13;
	double 	fConst14;
	double 	fConst15;
	double 	fConst16;
	double 	fConst17;
	double 	fConst18;
	double 	fConst19;
	double 	fConst20;
	double 	fConst21;
	double 	fConst22;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec11[2];
	double 	fRec10[5];
	double 	fVec0[2];
	double 	fConst23;
	double 	fRec7[2];
	double 	fRec6[3];
	double 	fConst24;
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	double 	fRec12[2];
	double 	fRec5[3];
	double 	fConst28;
	double 	fConst29;
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;
	double 	fRec4[2];
	double 	fRec3[2];
	double 	fRec2[3];
	double 	fRec13[2];
	double 	fRec1[3];
	double 	fRec0[2];
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
	id = "cstb";
	name = N_("Colorsound Tone Blender");
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
	for (int i=0; i<2; i++) fRec8[i] = 0;
	for (int i=0; i<2; i++) fRec9[i] = 0;
	for (int i=0; i<2; i++) fRec11[i] = 0;
	for (int i=0; i<5; i++) fRec10[i] = 0;
	for (int i=0; i<2; i++) fVec0[i] = 0;
	for (int i=0; i<2; i++) fRec7[i] = 0;
	for (int i=0; i<3; i++) fRec6[i] = 0;
	for (int i=0; i<2; i++) fRec12[i] = 0;
	for (int i=0; i<3; i++) fRec5[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<3; i++) fRec2[i] = 0;
	for (int i=0; i<2; i++) fRec13[i] = 0;
	for (int i=0; i<3; i++) fRec1[i] = 0;
	for (int i=0; i<2; i++) fRec0[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = double(iConst0);
	fConst2 = (7.72761004436121e-17 * fConst1);
	fConst3 = (1.90124164300881e-12 + (fConst1 * (4.0705776699833e-14 + fConst2)));
	fConst4 = (7.13788307669893e-19 * fConst1);
	fConst5 = ((fConst1 * ((fConst1 * (0 - (3.81274375281155e-16 + fConst4))) - 1.78337596435683e-14)) - 3.57720562427687e-14);
	fConst6 = (7.26395344169953e-19 * fConst1);
	fConst7 = (3.58457860428614e-14 + (fConst1 * (1.78716714442828e-14 + (fConst1 * (3.82634300978431e-16 + fConst6)))));
	fConst8 = ((fConst1 * (4.0705776699833e-14 - fConst2)) - 1.90124164300881e-12);
	fConst9 = (3.57720562427687e-14 + (fConst1 * ((fConst1 * (3.81274375281155e-16 - fConst4)) - 1.78337596435683e-14)));
	fConst10 = ((fConst1 * (1.78716714442828e-14 + (fConst1 * (fConst6 - 3.82634300978431e-16)))) - 3.58457860428614e-14);
	fConst11 = (2.85515323067957e-18 * fConst1);
	fConst12 = faustpower<2>(fConst1);
	fConst13 = (7.15441124855374e-14 + (fConst12 * (fConst11 - 7.6254875056231e-16)));
	fConst14 = (2.90558137667981e-18 * fConst1);
	fConst15 = ((fConst12 * (7.65268601956861e-16 - fConst14)) - 7.16915720857228e-14);
	fConst16 = (1.54552200887224e-16 * fConst12);
	fConst17 = (fConst16 - 3.80248328601762e-12);
	fConst18 = (3.56675192871367e-14 - (4.28272984601936e-18 * fConst12));
	fConst19 = ((4.35837206501972e-18 * fConst12) - 3.57433428885656e-14);
	fConst20 = (3.80248328601762e-12 - fConst16);
	fConst21 = ((fConst12 * (7.6254875056231e-16 + fConst11)) - 7.15441124855374e-14);
	fConst22 = (7.16915720857228e-14 + (fConst12 * (0 - (7.65268601956861e-16 + fConst14))));
	fConst23 = (0.9302847925323914 * faustpower<3>(fConst1));
	fConst24 = (1.0 / tan((270.1769682087222 / double(iConst0))));
	fConst25 = (1 + fConst24);
	fConst26 = (0.027 / fConst25);
	fConst27 = (0 - ((1 - fConst24) / fConst25));
	fConst28 = (1.0 / tan((97.38937226128358 / double(iConst0))));
	fConst29 = (0 - fConst28);
	fConst30 = (1 + fConst28);
	fConst31 = (0.025 / fConst30);
	fConst32 = (0 - ((1 - fConst28) / fConst30));
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
	double 	fSlow0 = (0.007000000000000006 * double(fslider0));
	double 	fSlow1 = (0.007000000000000006 * double(fslider1));
	double 	fSlow2 = (7.000000000000006e-05 * double(fslider2));
	for (int i=0; i<count; i++) {
		fRec8[0] = ((0.993 * fRec8[1]) + fSlow0);
		double fTemp0 = (3.81338149392143e-12 + (fConst1 * ((fRec8[0] * (fConst7 + (fConst5 * fRec8[0]))) + fConst3)));
		fRec9[0] = ((0.993 * fRec9[1]) + fSlow1);
		double fTemp1 = (fConst1 * (fRec8[0] * (((fRec8[0] * (2.34677954600673e-22 + (2.34677954600673e-19 * fRec9[0]))) - (2.35728909376724e-17 * fRec9[0])) - 2.35728909376724e-20)));
		double fTemp2 = (2.50775435507154e-15 * fRec9[0]);
		fRec11[0] = ((0.993 * fRec11[1]) + fSlow2);
		double fTemp3 = (double)input0[i];
		fRec10[0] = ((fTemp3 * fRec11[0]) - (((((fRec10[1] * (1.52535259756857e-11 + (fConst1 * ((fRec8[0] * (fConst22 + (fConst21 * fRec8[0]))) + fConst20)))) + (fRec10[2] * (2.28802889635286e-11 + (fConst12 * ((fRec8[0] * (fConst19 + (fConst18 * fRec8[0]))) - 8.14115533996661e-14))))) + (fRec10[3] * (1.52535259756857e-11 + (fConst1 * (fConst17 + (fRec8[0] * (fConst15 + (fConst13 * fRec8[0])))))))) + (fRec10[4] * (3.81338149392143e-12 + (fConst1 * ((fRec8[0] * (fConst10 + (fConst9 * fRec8[0]))) + fConst8))))) / fTemp0));
		double fTemp4 = (5.01550871014307e-15 * fRec9[0]);
		double fTemp5 = (fConst1 * (fRec8[0] * (9.42915637506898e-20 + ((9.42915637506898e-17 * fRec9[0]) + (fRec8[0] * ((0 - (9.38711818402692e-19 * fRec9[0])) - 9.38711818402692e-22))))));
		double fTemp6 = ((((((fRec10[0] * ((fTemp1 - fTemp2) - 2.50775435507154e-18)) + (fRec10[1] * (5.01550871014307e-18 + (fTemp4 + fTemp5)))) + (fConst1 * ((fRec8[0] * fRec10[2]) * (((fRec8[0] * (1.40806772760404e-21 + (1.40806772760404e-18 * fRec9[0]))) - (1.41437345626035e-16 * fRec9[0])) - 1.41437345626035e-19)))) + (fRec10[3] * ((fTemp5 - fTemp4) - 5.01550871014307e-18))) + (fRec10[4] * (2.50775435507154e-18 + (fTemp2 + fTemp1)))) / fTemp0);
		fVec0[0] = fTemp6;
		fRec7[0] = ((fConst23 * (fVec0[0] + fVec0[1])) - (0.8605695850647829 * fRec7[1]));
		fRec6[0] = (fRec7[0] - ((1.8405051250752198 * fRec6[1]) + (0.8612942439318627 * fRec6[2])));
		fRec12[0] = ((fConst27 * fRec12[1]) + (fConst26 * (fRec5[1] + fRec5[2])));
		fRec5[0] = (Ftrany(TRANY_TABLE_KT88_68k, ((fRec12[0] + (0.9254498422517706 * (fRec6[2] + (fRec6[0] + (2.0 * fRec6[1]))))) - 5.562895)) - 43.96685185185183);
		fRec4[0] = ((fConst32 * fRec4[1]) + (fConst31 * ((fConst28 * fRec5[0]) + (fConst29 * fRec5[1]))));
		fRec3[0] = ((0.9302847925323914 * (fRec4[0] + fRec4[1])) - (0.8605695850647829 * fRec3[1]));
		fRec2[0] = (fRec3[0] - ((1.8405051250752198 * fRec2[1]) + (0.8612942439318627 * fRec2[2])));
		fRec13[0] = ((fConst27 * fRec13[1]) + (fConst26 * (fRec1[1] + fRec1[2])));
		fRec1[0] = (Ftrany(TRANY_TABLE_KT88_68k, ((fRec13[0] + (0.9254498422517706 * (fRec2[2] + (fRec2[0] + (2.0 * fRec2[1]))))) - 5.562895)) - 43.96685185185183);
		fRec0[0] = ((fConst32 * fRec0[1]) + (fConst31 * ((fConst28 * fRec1[0]) + (fConst29 * fRec1[1]))));
		output0[i] = (FAUSTFLOAT)((fTemp3 * (1 - fRec11[0])) + fRec0[0]);
		// post processing
		fRec0[1] = fRec0[0];
		fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
		fRec13[1] = fRec13[0];
		fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
		fRec3[1] = fRec3[0];
		fRec4[1] = fRec4[0];
		fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
		fRec12[1] = fRec12[0];
		fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
		fRec7[1] = fRec7[0];
		fVec0[1] = fVec0[0];
		for (int i=4; i>0; i--) fRec10[i] = fRec10[i-1];
		fRec11[1] = fRec11[0];
		fRec9[1] = fRec9[0];
		fRec8[1] = fRec8[0];
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
	case ATTACK: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 0.95, 0.01 
		break;
	case LEVEL: 
		fslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case WET_DRY: 
		fslider2_ = (float*)data; // , 1e+02, 0.0, 1e+02, 1.0 
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
   ATTACK, 
   LEVEL, 
   WET_DRY, 
} PortIndex;
*/

} // end namespace cstb
