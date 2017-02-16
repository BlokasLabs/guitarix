// generated from file '../src/plugins/susta.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)

#include "gx_faust_support.h"
#include "gx_plugin.h"

#include "trany.h"

namespace pluginlib {
namespace susta {

class Dsp: public PluginDef {
private:
	int fSamplingFreq;
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	FAUSTFLOAT 	fslider0;
	double 	fRec0[2];
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
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
	double 	fConst23;
	double 	fConst24;
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	double 	fConst28;
	double 	fConst29;
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;
	double 	fConst33;
	double 	fConst34;
	double 	fConst35;
	double 	fConst36;
	double 	fConst37;
	double 	fConst38;
	double 	fConst39;
	double 	fConst40;
	double 	fConst41;
	double 	fConst42;
	double 	fConst43;
	double 	fConst44;
	double 	fConst45;
	double 	fConst46;
	double 	fConst47;
	double 	fConst48;
	double 	fConst49;
	double 	fConst50;
	double 	fConst51;
	double 	fConst52;
	double 	fConst53;
	double 	fConst54;
	double 	fConst55;
	double 	fConst56;
	double 	fConst57;
	double 	fConst58;
	double 	fConst59;
	double 	fConst60;
	double 	fConst61;
	double 	fConst62;
	double 	fRec1[6];
	double 	fConst63;
	double 	fConst64;
	double 	fConst65;
	double 	fConst66;
	double 	fConst67;
	double 	fConst68;
	double 	fConst69;
	double 	fConst70;
	double 	fConst71;
	double 	fConst72;
	double 	fConst73;
	double 	fConst74;
	double 	fConst75;
	double 	fConst76;
	double 	fConst77;
	double 	fConst78;
	double 	fConst79;
	double 	fConst80;
	double 	fConst81;
	double 	fConst82;
	double 	fConst83;
	double 	fConst84;
	double 	fConst85;
	double 	fConst86;
	double 	fConst87;
	double 	fConst88;
	double 	fConst89;
	double 	fConst90;
	double 	fConst91;

	int samplingFreq;
	gx_resample::FixedRateResampler smpCl;
	double 	fVecCl0[2];
	double 	fRecCl7[2];
	double 	fRecCl6[3];
	int 	iConstCl0;
	double 	fConstCl1;
	double 	fConstCl2;
	double 	fConstCl3;
	double 	fConstCl4;
	double 	fRecCl8[2];
	double 	fRecCl5[3];
	double 	fConstCl5;
	double 	fConstCl6;
	double 	fConstCl7;
	double 	fConstCl8;
	double 	fConstCl9;
	double 	fRecCl4[2];
	double 	fRecCl3[2];
	double 	fRecCl2[3];
	double 	fRecCl9[2];
	double 	fRecCl1[3];
	double 	fRecCl0[2];

	FAUSTFLOAT 	fsliderV0;
	double 	fRecV0[2];
	void clear_state_f();
	int load_ui_f(const UiBuilder& b, int form);
	static const char *glade_def;
	void init(unsigned int samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);
	int register_par(const ParamReg& reg);

	static void clear_state_f_static(PluginDef*);
	static int load_ui_f_static(const UiBuilder& b, int form);
	static void init_static(unsigned int samplingFreq, PluginDef*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef*);
	static int register_params_static(const ParamReg& reg);
	static void del_instance(PluginDef *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginDef() {
	version = PLUGINDEF_VERSION;
	flags = 0;
	id = "susta";
	name = N_("Sustainer");
	groups = 0;
	description = N_("Sustainer"); // description (tooltip)
	category = N_("Fuzz");       // category
	shortname = N_("Sustainer");     // shortname
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	register_params = register_params_static;
	load_ui = load_ui_f_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fRec0[i] = 0;
	for (int i=0; i<6; i++) fRec1[i] = 0;

	for (int i=0; i<2; i++) fVecCl0[i] = 0;
	for (int i=0; i<2; i++) fRecCl7[i] = 0;
	for (int i=0; i<3; i++) fRecCl6[i] = 0;
	for (int i=0; i<2; i++) fRecCl8[i] = 0;
	for (int i=0; i<3; i++) fRecCl5[i] = 0;
	for (int i=0; i<2; i++) fRecCl4[i] = 0;
	for (int i=0; i<2; i++) fRecCl3[i] = 0;
	for (int i=0; i<3; i++) fRecCl2[i] = 0;
	for (int i=0; i<2; i++) fRecCl9[i] = 0;
	for (int i=0; i<3; i++) fRecCl1[i] = 0;
	for (int i=0; i<2; i++) fRecCl0[i] = 0;

	for (int i=0; i<2; i++) fRecV0[i] = 0;
}

void Dsp::clear_state_f_static(PluginDef *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(unsigned int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = double(min(192000, max(1, fSamplingFreq)));
	fConst1 = (1.58888527196851e-24 * fConst0);
	fConst2 = (3.80287926742832e-14 + (fConst0 * (4.14135154627774e-15 + (fConst0 * (1.4867852143994e-16 + (fConst0 * (6.14378170525581e-20 + fConst1)))))));
	fConst3 = (1.03973026841637e-24 * fConst0);
	fConst4 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (5.71785438210912e-20 + fConst3))) - 1.41224926366503e-16)) - 3.77185698680303e-15)) - 3.30317585349598e-14);
	fConst5 = (5.11091507074998e-24 * fConst0);
	fConst6 = (fConst0 * (1.75646845862514e-15 + (fConst0 * (1.4095256819997e-16 + (fConst0 * (6.98874158230498e-20 + fConst5))))));
	fConst7 = (5.07545362580621e-24 * fConst0);
	fConst8 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (7.00613593632107e-20 + fConst7))) - 1.47460849525455e-16)) - 2.81034919192636e-15)) - 1.29152092545966e-14);
	fConst9 = (9.91377586985301e-24 * fConst0);
	fConst10 = (fConst0 * ((fConst0 * ((fConst0 * (0 - (9.36483991458906e-20 + fConst9))) - 1.70486053448624e-16)) - 2.12307123308889e-15));
	fConst11 = (9.84499037599778e-24 * fConst0);
	fConst12 = (1.56108178903595e-14 + (fConst0 * (3.39775512445924e-15 + (fConst0 * (1.78421312766784e-16 + (fConst0 * (9.42766173980015e-20 + fConst11)))))));
	fConst13 = (4.07249439024394e-29 * fConst0);
	fConst14 = ((fConst0 * (0 - (1.34118849842818e-22 + fConst13))) - 1.23525177556824e-17);
	fConst15 = (4.07249439024394e-27 * fConst0);
	fConst16 = ((fConst0 * (0 - (1.34118849842818e-20 + fConst15))) - 1.23525177556824e-15);
	fConst17 = (3.9514408494262e-27 * fConst0);
	fConst18 = ((fConst0 * (1.26300907176988e-20 + fConst17)) - 2.68904213585766e-17);
	fConst19 = (3.9514408494262e-29 * fConst0);
	fConst20 = ((fConst0 * (1.26300907176988e-22 + fConst19)) - 2.68904213585766e-19);
	fConst21 = ((fConst0 * (4.14135154627774e-15 + (fConst0 * ((fConst0 * (6.14378170525581e-20 - fConst1)) - 1.4867852143994e-16)))) - 3.80287926742832e-14);
	fConst22 = (3.30317585349598e-14 + (fConst0 * ((fConst0 * (1.41224926366503e-16 + (fConst0 * (fConst3 - 5.71785438210912e-20)))) - 3.77185698680303e-15)));
	fConst23 = (fConst0 * (1.75646845862514e-15 + (fConst0 * ((fConst0 * (6.98874158230498e-20 - fConst5)) - 1.4095256819997e-16))));
	fConst24 = (1.29152092545966e-14 + (fConst0 * ((fConst0 * (1.47460849525455e-16 + (fConst0 * (fConst7 - 7.00613593632107e-20)))) - 2.81034919192636e-15)));
	fConst25 = (fConst0 * ((fConst0 * (1.70486053448624e-16 + (fConst0 * (fConst9 - 9.36483991458906e-20)))) - 2.12307123308889e-15));
	fConst26 = ((fConst0 * (3.39775512445924e-15 + (fConst0 * ((fConst0 * (9.42766173980015e-20 - fConst11)) - 1.78421312766784e-16)))) - 1.56108178903595e-14);
	fConst27 = (7.94442635984257e-24 * fConst0);
	fConst28 = ((fConst0 * (4.14135154627774e-15 + (fConst0 * (1.4867852143994e-16 + (fConst0 * (fConst27 - 1.84313451157674e-19)))))) - 1.1408637802285e-13);
	fConst29 = (5.19865134208184e-24 * fConst0);
	fConst30 = (9.90952756048795e-14 + (fConst0 * ((fConst0 * ((fConst0 * (1.71535631463274e-19 - fConst29)) - 1.41224926366503e-16)) - 3.77185698680303e-15)));
	fConst31 = (2.55545753537499e-23 * fConst0);
	fConst32 = (fConst0 * (1.75646845862514e-15 + (fConst0 * (1.4095256819997e-16 + (fConst0 * (fConst31 - 2.09662247469149e-19))))));
	fConst33 = (2.53772681290311e-23 * fConst0);
	fConst34 = (3.87456277637898e-14 + (fConst0 * ((fConst0 * ((fConst0 * (2.10184078089632e-19 - fConst33)) - 1.47460849525455e-16)) - 2.81034919192636e-15)));
	fConst35 = (4.95688793492651e-23 * fConst0);
	fConst36 = (fConst0 * ((fConst0 * ((fConst0 * (2.80945197437672e-19 - fConst35)) - 1.70486053448624e-16)) - 2.12307123308889e-15));
	fConst37 = (4.92249518799889e-23 * fConst0);
	fConst38 = ((fConst0 * (3.39775512445924e-15 + (fConst0 * (1.78421312766784e-16 + (fConst0 * (fConst37 - 2.82829852194005e-19)))))) - 4.68324536710785e-14);
	fConst39 = (1.58888527196851e-23 * fConst0);
	fConst40 = ((fConst0 * ((fConst0 * (2.97357042879881e-16 + (fConst0 * (1.22875634105116e-19 - fConst39)))) - 8.28270309255548e-15)) - 7.60575853485664e-14);
	fConst41 = (1.03973026841637e-23 * fConst0);
	fConst42 = (6.60635170699196e-14 + (fConst0 * (7.54371397360606e-15 + (fConst0 * ((fConst0 * (fConst41 - 1.14357087642182e-19)) - 2.82449852733007e-16)))));
	fConst43 = (5.11091507074998e-23 * fConst0);
	fConst44 = (fConst0 * ((fConst0 * (2.81905136399941e-16 + (fConst0 * (1.397748316461e-19 - fConst43)))) - 3.51293691725028e-15));
	fConst45 = (5.07545362580621e-23 * fConst0);
	fConst46 = (2.58304185091932e-14 + (fConst0 * (5.62069838385272e-15 + (fConst0 * ((fConst0 * (fConst45 - 1.40122718726421e-19)) - 2.94921699050911e-16)))));
	fConst47 = (9.91377586985301e-23 * fConst0);
	fConst48 = (fConst0 * (4.24614246617778e-15 + (fConst0 * ((fConst0 * (fConst47 - 1.87296798291781e-19)) - 3.40972106897249e-16))));
	fConst49 = (9.84499037599778e-23 * fConst0);
	fConst50 = ((fConst0 * ((fConst0 * (3.56842625533568e-16 + (fConst0 * (1.88553234796003e-19 - fConst49)))) - 6.79551024891847e-15)) - 3.1221635780719e-14);
	fConst51 = (7.60575853485664e-14 + (fConst0 * ((fConst0 * ((fConst0 * (1.22875634105116e-19 + fConst39)) - 2.97357042879881e-16)) - 8.28270309255548e-15)));
	fConst52 = ((fConst0 * (7.54371397360606e-15 + (fConst0 * (2.82449852733007e-16 + (fConst0 * (0 - (1.14357087642182e-19 + fConst41))))))) - 6.60635170699196e-14);
	fConst53 = (fConst0 * ((fConst0 * ((fConst0 * (1.397748316461e-19 + fConst43)) - 2.81905136399941e-16)) - 3.51293691725028e-15));
	fConst54 = ((fConst0 * (5.62069838385272e-15 + (fConst0 * (2.94921699050911e-16 + (fConst0 * (0 - (1.40122718726421e-19 + fConst45))))))) - 2.58304185091932e-14);
	fConst55 = (fConst0 * (4.24614246617778e-15 + (fConst0 * (3.40972106897249e-16 + (fConst0 * (0 - (1.87296798291781e-19 + fConst47)))))));
	fConst56 = (3.1221635780719e-14 + (fConst0 * ((fConst0 * ((fConst0 * (1.88553234796003e-19 + fConst49)) - 3.56842625533568e-16)) - 6.79551024891847e-15)));
	fConst57 = (1.1408637802285e-13 + (fConst0 * (4.14135154627774e-15 + (fConst0 * ((fConst0 * (0 - (1.84313451157674e-19 + fConst27))) - 1.4867852143994e-16)))));
	fConst58 = ((fConst0 * ((fConst0 * (1.41224926366503e-16 + (fConst0 * (1.71535631463274e-19 + fConst29)))) - 3.77185698680303e-15)) - 9.90952756048795e-14);
	fConst59 = (fConst0 * (1.75646845862514e-15 + (fConst0 * ((fConst0 * (0 - (2.09662247469149e-19 + fConst31))) - 1.4095256819997e-16))));
	fConst60 = ((fConst0 * ((fConst0 * (1.47460849525455e-16 + (fConst0 * (2.10184078089632e-19 + fConst33)))) - 2.81034919192636e-15)) - 3.87456277637898e-14);
	fConst61 = (fConst0 * ((fConst0 * (1.70486053448624e-16 + (fConst0 * (2.80945197437672e-19 + fConst35)))) - 2.12307123308889e-15));
	fConst62 = (4.68324536710785e-14 + (fConst0 * (3.39775512445924e-15 + (fConst0 * ((fConst0 * (0 - (2.82829852194005e-19 + fConst37))) - 1.78421312766784e-16)))));
	fConst63 = (2.03624719512197e-28 * fConst0);
	fConst64 = (1.23525177556824e-17 + (fConst0 * (4.02356549528453e-22 + fConst63)));
	fConst65 = (2.03624719512197e-26 * fConst0);
	fConst66 = (1.23525177556824e-15 + (fConst0 * (4.02356549528453e-20 + fConst65)));
	fConst67 = (1.9757204247131e-26 * fConst0);
	fConst68 = (2.68904213585766e-17 + (fConst0 * (0 - (3.78902721530964e-20 + fConst67))));
	fConst69 = (1.9757204247131e-28 * fConst0);
	fConst70 = (2.68904213585766e-19 + (fConst0 * (0 - (3.78902721530964e-22 + fConst69))));
	fConst71 = (4.07249439024394e-28 * fConst0);
	fConst72 = (2.47050355113649e-17 + (fConst0 * (0 - (2.68237699685635e-22 + fConst71))));
	fConst73 = (4.07249439024394e-26 * fConst0);
	fConst74 = (2.47050355113649e-15 + (fConst0 * (0 - (2.68237699685635e-20 + fConst73))));
	fConst75 = (3.9514408494262e-26 * fConst0);
	fConst76 = (5.37808427171532e-17 + (fConst0 * (2.52601814353976e-20 + fConst75)));
	fConst77 = (3.9514408494262e-28 * fConst0);
	fConst78 = (5.37808427171532e-19 + (fConst0 * (2.52601814353976e-22 + fConst77)));
	fConst79 = ((fConst0 * (fConst73 - 2.68237699685635e-20)) - 2.47050355113649e-15);
	fConst80 = ((fConst0 * (2.52601814353976e-20 - fConst75)) - 5.37808427171532e-17);
	fConst81 = ((fConst0 * (2.52601814353976e-22 - fConst77)) - 5.37808427171532e-19);
	fConst82 = ((fConst0 * (fConst71 - 2.68237699685635e-22)) - 2.47050355113649e-17);
	fConst83 = ((fConst0 * (4.02356549528453e-22 - fConst63)) - 1.23525177556824e-17);
	fConst84 = ((fConst0 * (4.02356549528453e-20 - fConst65)) - 1.23525177556824e-15);
	fConst85 = ((fConst0 * (fConst67 - 3.78902721530964e-20)) - 2.68904213585766e-17);
	fConst86 = ((fConst0 * (fConst69 - 3.78902721530964e-22)) - 2.68904213585766e-19);
	fConst87 = (1.23525177556824e-17 + (fConst0 * (fConst13 - 1.34118849842818e-22)));
	fConst88 = (1.23525177556824e-15 + (fConst0 * (fConst15 - 1.34118849842818e-20)));
	fConst89 = (2.68904213585766e-17 + (fConst0 * (1.26300907176988e-20 - fConst17)));
	fConst90 = (2.68904213585766e-19 + (fConst0 * (1.26300907176988e-22 - fConst19)));
	fConst91 = faustpower<3>(fConst0);

	samplingFreq = 96000;
	smpCl.setup(fSamplingFreq, samplingFreq);
	fSamplingFreq = samplingFreq;
	iConstCl0 = min(192000, max(1, fSamplingFreq));
	fConstCl1 = (1.0 / tan((270.1769682087222 / double(iConstCl0))));
	fConstCl2 = (1 + fConstCl1);
	fConstCl3 = (0.027 / fConstCl2);
	fConstCl4 = (0 - ((1 - fConstCl1) / fConstCl2));
	fConstCl5 = (1.0 / tan((97.38937226128358 / double(iConstCl0))));
	fConstCl6 = (0 - fConstCl5);
	fConstCl7 = (1 + fConstCl5);
	fConstCl8 = (0.025 / fConstCl7);
	fConstCl9 = (0 - ((1 - fConstCl5) / fConstCl7));

	clear_state_f();
}

void Dsp::init_static(unsigned int samplingFreq, PluginDef *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
	double 	fSlowV0 = (0.0010000000000000009 * double(fsliderV0));

	double 	fSlow0 = (0.007000000000000006 * double(fslider0));
	for (int i=0; i<count; i++) {
		fRec0[0] = ((0.993 * fRec0[1]) + fSlow0);
		double fTemp0 = ((fConst0 * (((fRec0[0] * (fConst12 + (fConst10 * fRec0[0]))) + ((fRec0[0] * (fConst8 + (fConst6 * fRec0[0]))) + fConst4)) + fConst2)) + 1.982065173355061e-14);
		fRec1[0] = ((double)input0[i] - ((((((fRec1[1] * ((fConst0 * (((fRec0[0] * (fConst62 + (fConst61 * fRec0[0]))) + ((fRec0[0] * (fConst60 + (fConst59 * fRec0[0]))) + fConst58)) + fConst57)) + 9.910325866775292e-14)) + (fRec1[2] * ((fConst0 * (((fRec0[0] * (fConst56 + (fConst55 * fRec0[0]))) + ((fRec0[0] * (fConst54 + (fConst53 * fRec0[0]))) + fConst52)) + fConst51)) + 1.9820651733550584e-13))) + (fRec1[3] * (1.9820651733550584e-13 + (fConst0 * (((fRec0[0] * (fConst50 + (fConst48 * fRec0[0]))) + ((fRec0[0] * (fConst46 + (fConst44 * fRec0[0]))) + fConst42)) + fConst40))))) + (fRec1[4] * (9.910325866775292e-14 + (fConst0 * (((fRec0[0] * (fConst38 + (fConst36 * fRec0[0]))) + ((fRec0[0] * (fConst34 + (fConst32 * fRec0[0]))) + fConst30)) + fConst28))))) + (fRec1[5] * (1.982065173355061e-14 + (fConst0 * (((fRec0[0] * (fConst26 + (fConst25 * fRec0[0]))) + ((fRec0[0] * (fConst24 + (fConst23 * fRec0[0]))) + fConst22)) + fConst21))))) / fTemp0));
		output0[i] = (FAUSTFLOAT)(fConst91 * (((((((fRec1[0] * (((fConst90 + (fConst89 * fRec0[0])) + (fConst88 * fRec0[0])) + fConst87)) + (fRec1[1] * (((fConst86 + (fConst85 * fRec0[0])) + (fConst84 * fRec0[0])) + fConst83))) + (fRec1[2] * (fConst82 + ((fConst81 + (fConst80 * fRec0[0])) + (fConst79 * fRec0[0]))))) + (fRec1[3] * (((fConst78 + (fConst76 * fRec0[0])) + (fConst74 * fRec0[0])) + fConst72))) + (fRec1[4] * (((fConst70 + (fConst68 * fRec0[0])) + (fConst66 * fRec0[0])) + fConst64))) + (fRec1[5] * (((fConst20 + (fConst18 * fRec0[0])) + (fConst16 * fRec0[0])) + fConst14))) / fTemp0));
		// post processing
		for (int i=5; i>0; i--) fRec1[i] = fRec1[i-1];
		fRec0[1] = fRec0[0];
	}

	FAUSTFLOAT bufCl[smpCl.max_out_count(count)];
	int ReCount = smpCl.up(count, output0, bufCl);
	for (int i=0; i<ReCount; i++) {
		double fTemp0 = (double)bufCl[i];
		fVecCl0[0] = fTemp0;
		fRecCl7[0] = ((0.9302847925323914 * (fVecCl0[0] + fVecCl0[1])) - (0.8605695850647829 * fRecCl7[1]));
		fRecCl6[0] = (fRecCl7[0] - ((1.8405051250752198 * fRecCl6[1]) + (0.8612942439318627 * fRecCl6[2])));
		fRecCl8[0] = ((fConstCl4 * fRecCl8[1]) + (fConstCl3 * (fRecCl5[1] + fRecCl5[2])));
		fRecCl5[0] = (Ftrany(TRANY_TABLE_7199P_68k, ((fRecCl8[0] + (0.9254498422517706 * (fRecCl6[2] + (fRecCl6[0] + (2.0 * fRecCl6[1]))))) - 3.571981)) - 117.70440740740739);
		fRecCl4[0] = ((fConstCl9 * fRecCl4[1]) + (fConstCl8 * ((fConstCl5 * fRecCl5[0]) + (fConstCl6 * fRecCl5[1]))));
		fRecCl3[0] = ((0.9302847925323914 * (fRecCl4[0] + fRecCl4[1])) - (0.8605695850647829 * fRecCl3[1]));
		fRecCl2[0] = (fRecCl3[0] - ((1.8405051250752198 * fRecCl2[1]) + (0.8612942439318627 * fRecCl2[2])));
		fRecCl9[0] = ((fConstCl4 * fRecCl9[1]) + (fConstCl3 * (fRecCl1[1] + fRecCl1[2])));
		fRecCl1[0] = (Ftrany(TRANY_TABLE_7199P_68k, ((fRecCl9[0] + (0.9254498422517706 * (fRecCl2[2] + (fRecCl2[0] + (2.0 * fRecCl2[1]))))) - 3.571981)) - 117.70440740740739);
		fRecCl0[0] = ((fConstCl9 * fRecCl0[1]) + (fConstCl8 * ((fConstCl5 * fRecCl1[0]) + (fConstCl6 * fRecCl1[1]))));
		bufCl[i] = (FAUSTFLOAT)fRecCl0[0];
		// post processing
		fRecCl0[1] = fRecCl0[0];
		fRecCl1[2] = fRecCl1[1]; fRecCl1[1] = fRecCl1[0];
		fRecCl9[1] = fRecCl9[0];
		fRecCl2[2] = fRecCl2[1]; fRecCl2[1] = fRecCl2[0];
		fRecCl3[1] = fRecCl3[0];
		fRecCl4[1] = fRecCl4[0];
		fRecCl5[2] = fRecCl5[1]; fRecCl5[1] = fRecCl5[0];
		fRecCl8[1] = fRecCl8[0];
		fRecCl6[2] = fRecCl6[1]; fRecCl6[1] = fRecCl6[0];
		fRecCl7[1] = fRecCl7[0];
		fVecCl0[1] = fVecCl0[0];
	}
	smpCl.down(bufCl, output0);

	for (int i=0; i<count; i++) {
		fRecV0[0] = ((0.999 * fRecV0[1]) + fSlowV0);
		output0[i] = (FAUSTFLOAT)((double)output0[i] * fRecV0[0]);
		// post processing
		fRecV0[1] = fRecV0[0];
	}

}
		
void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}

int Dsp::register_par(const ParamReg& reg)
{
	reg.registerVar("susta.Volume",N_("Volume"),"S","",&fsliderV0, 0.5, 0.0, 1, 0.01);
	reg.registerVar("susta.Sustain",N_("Sustain"),"S","",&fslider0, 0.5, 0.0, 1.0, 0.01);
	return 0;
}

int Dsp::register_params_static(const ParamReg& reg)
{
	return static_cast<Dsp*>(reg.plugin)->register_par(reg);
}

const char *Dsp::glade_def = "\
<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\
<interface>\n\
  <!-- interface-requires gxwidgets 0.0 -->\n\
  <requires lib=\"gtk+\" version=\"2.20\"/>\n\
  <!-- interface-naming-policy project-wide -->\n\
  <object class=\"GtkWindow\" id=\"window1\">\n\
    <property name=\"can_focus\">False</property>\n\
    <child>\n\
      <object class=\"GtkVBox\" id=\"vbox1\">\n\
        <property name=\"visible\">True</property>\n\
        <property name=\"can_focus\">False</property>\n\
        <child>\n\
          <object class=\"GtkHBox\" id=\"rackbox\">\n\
            <property name=\"visible\">True</property>\n\
            <property name=\"can_focus\">False</property>\n\
            <property name=\"spacing\">4</property>\n\
            <child>\n\
              <object class=\"GtkHBox\" id=\"hbox1\">\n\
                <property name=\"visible\">True</property>\n\
                <property name=\"can_focus\">False</property>\n\
                <property name=\"spacing\">10</property>\n\
                <child>\n\
                  <object class=\"GtkVBox\" id=\"vbox2\">\n\
                    <property name=\"visible\">True</property>\n\
                    <property name=\"can_focus\">False</property>\n\
                    <child>\n\
                      <object class=\"GtkLabel\" id=\"label1:rack_label\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">False</property>\n\
                        <property name=\"label\" translatable=\"yes\">label</property>\n\
                      </object>\n\
                      <packing>\n\
                        <property name=\"expand\">False</property>\n\
                        <property name=\"fill\">False</property>\n\
                        <property name=\"position\">0</property>\n\
                      </packing>\n\
                    </child>\n\
                    <child>\n\
                      <object class=\"GxSmallKnobR\" id=\"gxbigknob1\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">True</property>\n\
                        <property name=\"receives_default\">True</property>\n\
                        <property name=\"var_id\">susta.Sustain</property>\n\
                        <property name=\"label_ref\">label1:rack_label</property>\n\
                      </object>\n\
                      <packing>\n\
                        <property name=\"expand\">False</property>\n\
                        <property name=\"fill\">False</property>\n\
                        <property name=\"position\">1</property>\n\
                      </packing>\n\
                    </child>\n\
                  </object>\n\
                  <packing>\n\
                    <property name=\"expand\">False</property>\n\
                    <property name=\"fill\">False</property>\n\
                    <property name=\"position\">0</property>\n\
                  </packing>\n\
                </child>\n\
                <child>\n\
                  <object class=\"GtkVBox\" id=\"vbox3\">\n\
                    <property name=\"visible\">True</property>\n\
                    <property name=\"can_focus\">False</property>\n\
                    <child>\n\
                      <object class=\"GtkLabel\" id=\"label2:rack_label\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">False</property>\n\
                        <property name=\"label\" translatable=\"yes\">label</property>\n\
                      </object>\n\
                      <packing>\n\
                        <property name=\"expand\">False</property>\n\
                        <property name=\"fill\">False</property>\n\
                        <property name=\"position\">0</property>\n\
                      </packing>\n\
                    </child>\n\
                    <child>\n\
                      <object class=\"GxMidKnob\" id=\"gxbigknob2\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">True</property>\n\
                        <property name=\"receives_default\">True</property>\n\
                        <property name=\"var_id\">susta.Volume</property>\n\
                        <property name=\"label_ref\">label2:rack_label</property>\n\
                      </object>\n\
                      <packing>\n\
                        <property name=\"expand\">False</property>\n\
                        <property name=\"fill\">False</property>\n\
                        <property name=\"position\">1</property>\n\
                      </packing>\n\
                    </child>\n\
                  </object>\n\
                  <packing>\n\
                    <property name=\"expand\">False</property>\n\
                    <property name=\"fill\">False</property>\n\
                    <property name=\"position\">1</property>\n\
                  </packing>\n\
                </child>\n\
              </object>\n\
              <packing>\n\
                <property name=\"expand\">True</property>\n\
                <property name=\"fill\">False</property>\n\
                <property name=\"pack_type\">end</property>\n\
                <property name=\"position\">0</property>\n\
              </packing>\n\
            </child>\n\
          </object>\n\
          <packing>\n\
            <property name=\"expand\">True</property>\n\
            <property name=\"fill\">False</property>\n\
            <property name=\"position\">0</property>\n\
          </packing>\n\
        </child>\n\
        <child>\n\
          <object class=\"GtkHBox\" id=\"minibox\">\n\
            <property name=\"visible\">True</property>\n\
            <property name=\"can_focus\">False</property>\n\
            <property name=\"spacing\">4</property>\n\
            <child>\n\
              <object class=\"GxHSlider\" id=\"gxhslider1\">\n\
                <property name=\"visible\">True</property>\n\
                <property name=\"can_focus\">True</property>\n\
                <property name=\"receives_default\">True</property>\n\
                <property name=\"round_digits\">0</property>\n\
                <property name=\"var_id\">susta.Sustain</property>\n\
                <property name=\"show_value\">False</property>\n\
                <property name=\"value_position\">right</property>\n\
                <property name=\"value_xalign\">0.52000000000000002</property>\n\
                <property name=\"label_ref\">label0:rack_label</property>\n\
              </object>\n\
              <packing>\n\
                <property name=\"expand\">False</property>\n\
                <property name=\"fill\">False</property>\n\
                <property name=\"position\">0</property>\n\
              </packing>\n\
            </child>\n\
            <child>\n\
              <object class=\"GtkLabel\" id=\"label0:rack_label\">\n\
                <property name=\"visible\">True</property>\n\
                <property name=\"can_focus\">False</property>\n\
                <property name=\"xalign\">0</property>\n\
                <property name=\"label\" translatable=\"yes\">Sustain</property>\n\
              </object>\n\
              <packing>\n\
                <property name=\"expand\">False</property>\n\
                <property name=\"fill\">False</property>\n\
                <property name=\"position\">1</property>\n\
              </packing>\n\
            </child>\n\
          </object>\n\
          <packing>\n\
            <property name=\"expand\">True</property>\n\
            <property name=\"fill\">True</property>\n\
            <property name=\"position\">1</property>\n\
          </packing>\n\
        </child>\n\
      </object>\n\
    </child>\n\
  </object>\n\
</interface>\n\
";

inline int Dsp::load_ui_f(const UiBuilder& b, int form)
{
    if (form & UI_FORM_GLADE) {
        b.load_glade(glade_def);
        return 0;
    }
    if (form & UI_FORM_STACK) {
#define PARAM(p) ("susta" "." p)

b.openHorizontalhideBox("");
    b.create_master_slider(PARAM("Sustain"), N_("Sustain"));
b.closeBox();
b.openHorizontalBox("");

    b.create_small_rackknobr(PARAM("Sustain"), N_("Sustain"));

    b.create_small_rackknobr(PARAM("Volume"), N_("Volume"));
b.closeBox();

#undef PARAM
        return 0;
    }
	return -1;
}

int Dsp::load_ui_f_static(const UiBuilder& b, int form)
{
	return static_cast<Dsp*>(b.plugin)->load_ui_f(b, form);
}
PluginDef *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginDef *p)
{
	delete static_cast<Dsp*>(p);
}

} // end namespace susta
} // end namespace pluginlib
