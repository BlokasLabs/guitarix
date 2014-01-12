// generated from file '../src/faust/panoram_enhancer.dsp' by dsp2cc:
// Code generated with Faust 0.9.46 (http://faust.grame.fr)


namespace panoram_enhancer {

class Dsp: public PluginDef {
private:
	int fSamplingFreq;
	int 	iConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
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
	int 	IOTA;
	double 	fVec0[65536];
	FAUSTFLOAT 	fslider0;
	double 	fRec6[2];
	double 	fConst20;
	double 	fRec5[3];
	double 	fConst21;
	double 	fRec4[3];
	double 	fRec3[3];
	double 	fRec2[3];
	double 	fRec1[3];
	double 	fRec0[3];
	FAUSTFLOAT 	fslider1;
	double 	fConst22;
	double 	fConst23;
	double 	fConst24;
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	double 	fConst28;
	double 	fConst29;
	double 	fVec1[65536];
	double 	fRec8[3];
	double 	fRec7[3];
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
	double 	fRec14[3];
	double 	fConst42;
	double 	fRec13[3];
	double 	fRec12[3];
	double 	fRec11[3];
	double 	fRec10[3];
	double 	fRec9[3];
	double 	fConst43;
	double 	fConst44;
	double 	fConst45;
	double 	fConst46;
	double 	fConst47;
	double 	fConst48;
	double 	fRec20[3];
	double 	fConst49;
	double 	fRec19[3];
	double 	fRec18[3];
	double 	fRec17[3];
	double 	fRec16[3];
	double 	fRec15[3];
	double 	fConst50;
	double 	fRec26[3];
	double 	fRec25[3];
	double 	fRec24[3];
	double 	fRec23[3];
	double 	fRec22[3];
	double 	fRec21[3];
	double 	fConst51;
	double 	fRec32[3];
	double 	fRec31[3];
	double 	fRec30[3];
	double 	fRec29[3];
	double 	fRec28[3];
	double 	fRec27[3];
	double 	fConst52;
	double 	fRec38[3];
	double 	fRec37[3];
	double 	fRec36[3];
	double 	fRec35[3];
	double 	fRec34[3];
	double 	fRec33[3];
	void clear_state_f();
	int load_ui_f(const UiBuilder& b, int form);
	void init(unsigned int samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1);
	int register_par(const ParamReg& reg);

	static void clear_state_f_static(PluginDef*);
	static int load_ui_f_static(const UiBuilder& b, int form);
	static void init_static(unsigned int samplingFreq, PluginDef*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1, PluginDef*);
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
	id = "panoram enhancer";
	name = N_("Panoram enhancer");
	groups = 0;
	description = ""; // description (tooltip)
	category = N_("Misc");       // category
	shortname = "";     // shortname
	mono_audio = 0;
	stereo_audio = compute_static;
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
	for (int i=0; i<65536; i++) fVec0[i] = 0;
	for (int i=0; i<2; i++) fRec6[i] = 0;
	for (int i=0; i<3; i++) fRec5[i] = 0;
	for (int i=0; i<3; i++) fRec4[i] = 0;
	for (int i=0; i<3; i++) fRec3[i] = 0;
	for (int i=0; i<3; i++) fRec2[i] = 0;
	for (int i=0; i<3; i++) fRec1[i] = 0;
	for (int i=0; i<3; i++) fRec0[i] = 0;
	for (int i=0; i<65536; i++) fVec1[i] = 0;
	for (int i=0; i<3; i++) fRec8[i] = 0;
	for (int i=0; i<3; i++) fRec7[i] = 0;
	for (int i=0; i<3; i++) fRec14[i] = 0;
	for (int i=0; i<3; i++) fRec13[i] = 0;
	for (int i=0; i<3; i++) fRec12[i] = 0;
	for (int i=0; i<3; i++) fRec11[i] = 0;
	for (int i=0; i<3; i++) fRec10[i] = 0;
	for (int i=0; i<3; i++) fRec9[i] = 0;
	for (int i=0; i<3; i++) fRec20[i] = 0;
	for (int i=0; i<3; i++) fRec19[i] = 0;
	for (int i=0; i<3; i++) fRec18[i] = 0;
	for (int i=0; i<3; i++) fRec17[i] = 0;
	for (int i=0; i<3; i++) fRec16[i] = 0;
	for (int i=0; i<3; i++) fRec15[i] = 0;
	for (int i=0; i<3; i++) fRec26[i] = 0;
	for (int i=0; i<3; i++) fRec25[i] = 0;
	for (int i=0; i<3; i++) fRec24[i] = 0;
	for (int i=0; i<3; i++) fRec23[i] = 0;
	for (int i=0; i<3; i++) fRec22[i] = 0;
	for (int i=0; i<3; i++) fRec21[i] = 0;
	for (int i=0; i<3; i++) fRec32[i] = 0;
	for (int i=0; i<3; i++) fRec31[i] = 0;
	for (int i=0; i<3; i++) fRec30[i] = 0;
	for (int i=0; i<3; i++) fRec29[i] = 0;
	for (int i=0; i<3; i++) fRec28[i] = 0;
	for (int i=0; i<3; i++) fRec27[i] = 0;
	for (int i=0; i<3; i++) fRec38[i] = 0;
	for (int i=0; i<3; i++) fRec37[i] = 0;
	for (int i=0; i<3; i++) fRec36[i] = 0;
	for (int i=0; i<3; i++) fRec35[i] = 0;
	for (int i=0; i<3; i++) fRec34[i] = 0;
	for (int i=0; i<3; i++) fRec33[i] = 0;
}

void Dsp::clear_state_f_static(PluginDef *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(unsigned int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = tan((62831.853071795864 / iConst0));
	fConst2 = (2 * (1 - (1.0 / faustpower<2>(fConst1))));
	fConst3 = (1.0 / fConst1);
	fConst4 = (1 + ((fConst3 - 0.5176380902050413) / fConst1));
	fConst5 = (1.0 / (1 + ((0.5176380902050413 + fConst3) / fConst1)));
	fConst6 = (1 + ((fConst3 - 1.414213562373095) / fConst1));
	fConst7 = (1.0 / (1 + ((1.414213562373095 + fConst3) / fConst1)));
	fConst8 = (1 + ((fConst3 - 1.9318516525781364) / fConst1));
	fConst9 = (1.0 / (1 + ((1.9318516525781364 + fConst3) / fConst1)));
	fConst10 = tan((20106.192982974677 / iConst0));
	fConst11 = (1.0 / faustpower<2>(fConst10));
	fConst12 = (2 * (1 - fConst11));
	fConst13 = (1.0 / fConst10);
	fConst14 = (1 + ((fConst13 - 0.5176380902050413) / fConst10));
	fConst15 = (1.0 / (1 + ((0.5176380902050413 + fConst13) / fConst10)));
	fConst16 = (1 + ((fConst13 - 1.414213562373095) / fConst10));
	fConst17 = (1.0 / (1 + ((1.414213562373095 + fConst13) / fConst10)));
	fConst18 = (1 + ((fConst13 - 1.9318516525781364) / fConst10));
	fConst19 = (1.0 / (1 + ((1.9318516525781364 + fConst13) / fConst10)));
	IOTA = 0;
	fConst20 = (0.13999999999999999 * iConst0);
	fConst21 = (2 * (0 - fConst11));
	fConst22 = tan((5654.8667764616275 / iConst0));
	fConst23 = (1.0 / faustpower<2>(fConst22));
	fConst24 = (2 * (1 - fConst23));
	fConst25 = (1.0 / fConst22);
	fConst26 = (1 + ((fConst25 - 0.7653668647301795) / fConst22));
	fConst27 = (1.0 / (1 + ((0.7653668647301795 + fConst25) / fConst22)));
	fConst28 = (1 + ((fConst25 - 1.8477590650225735) / fConst22));
	fConst29 = (1.0 / (1 + ((fConst25 + 1.8477590650225735) / fConst22)));
	fConst30 = tan((11309.733552923255 / iConst0));
	fConst31 = (1.0 / faustpower<2>(fConst30));
	fConst32 = (2 * (1 - fConst31));
	fConst33 = (1.0 / fConst30);
	fConst34 = (1 + ((fConst33 - 0.5176380902050413) / fConst30));
	fConst35 = (1.0 / (1 + ((0.5176380902050413 + fConst33) / fConst30)));
	fConst36 = (1 + ((fConst33 - 1.414213562373095) / fConst30));
	fConst37 = (1.0 / (1 + ((1.414213562373095 + fConst33) / fConst30)));
	fConst38 = (1 + ((fConst33 - 1.9318516525781364) / fConst30));
	fConst39 = (1.0 / (1 + ((1.9318516525781364 + fConst33) / fConst30)));
	fConst40 = (0.2 * iConst0);
	fConst41 = sqrt((0.3 + fConst40));
	fConst42 = (2 * (0 - fConst31));
	fConst43 = (1 + ((fConst25 - 0.5176380902050413) / fConst22));
	fConst44 = (1.0 / (1 + ((0.5176380902050413 + fConst25) / fConst22)));
	fConst45 = (1 + ((fConst25 - 1.414213562373095) / fConst22));
	fConst46 = (1.0 / (1 + ((1.414213562373095 + fConst25) / fConst22)));
	fConst47 = (1 + ((fConst25 - 1.9318516525781364) / fConst22));
	fConst48 = (1.0 / (1 + ((1.9318516525781364 + fConst25) / fConst22)));
	fConst49 = (2 * (0 - fConst23));
	fConst50 = (3.141592653589793 / iConst0);
	fConst51 = log10((9 + fConst40));
	fConst52 = cos((0.246 * iConst0));
	clear_state_f();
}

void Dsp::init_static(unsigned int samplingFreq, PluginDef *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1)
{
	double 	fSlow0 = (0.0010000000000000009 * fslider0);
	double 	fSlow1 = fslider1;
	double 	fSlow2 = (0.6 + (0.4 * sin((3.14 * fSlow1))));
	double 	fSlow3 = (fConst5 * fSlow2);
	double 	fSlow4 = (0.6 + (0.27999999999999997 * fSlow1));
	double 	fSlow5 = (fConst15 * fSlow4);
	double 	fSlow6 = (fConst35 * (0.6 + (0.4 * cos((1.23 * fSlow1)))));
	double 	fSlow7 = (1500 * fSlow1);
	double 	fSlow8 = tan((fConst50 * (6400 - fSlow7)));
	double 	fSlow9 = (1.0 / faustpower<2>(fSlow8));
	double 	fSlow10 = (2 * (1 - fSlow9));
	double 	fSlow11 = (1.0 / fSlow8);
	double 	fSlow12 = (1 + ((fSlow11 - 0.5176380902050413) / fSlow8));
	double 	fSlow13 = (1 + ((0.5176380902050413 + fSlow11) / fSlow8));
	double 	fSlow14 = (1.0 / fSlow13);
	double 	fSlow15 = (1 + ((fSlow11 - 1.414213562373095) / fSlow8));
	double 	fSlow16 = (1.0 / (1 + ((1.414213562373095 + fSlow11) / fSlow8)));
	double 	fSlow17 = (1 + ((fSlow11 - 1.9318516525781364) / fSlow8));
	double 	fSlow18 = (1.0 / (1 + ((1.9318516525781364 + fSlow11) / fSlow8)));
	double 	fSlow19 = tan((fConst50 * (3600 - fSlow7)));
	double 	fSlow20 = (1.0 / faustpower<2>(fSlow19));
	double 	fSlow21 = (2 * (1 - fSlow20));
	double 	fSlow22 = (1.0 / fSlow19);
	double 	fSlow23 = (1 + ((fSlow22 - 0.5176380902050413) / fSlow19));
	double 	fSlow24 = (1 + ((0.5176380902050413 + fSlow22) / fSlow19));
	double 	fSlow25 = (1.0 / fSlow24);
	double 	fSlow26 = (1 + ((fSlow22 - 1.414213562373095) / fSlow19));
	double 	fSlow27 = (1.0 / (1 + ((1.414213562373095 + fSlow22) / fSlow19)));
	double 	fSlow28 = (1 + ((fSlow22 - 1.9318516525781364) / fSlow19));
	double 	fSlow29 = (1.0 / (1 + ((1.9318516525781364 + fSlow22) / fSlow19)));
	double 	fSlow30 = (2 * (0 - fSlow20));
	double 	fSlow31 = (fSlow2 / fSlow13);
	double 	fSlow32 = tan((fConst50 * (20000 - fSlow7)));
	double 	fSlow33 = (2 * (1 - (1.0 / faustpower<2>(fSlow32))));
	double 	fSlow34 = (1.0 / fSlow32);
	double 	fSlow35 = (1 + ((fSlow34 - 0.5176380902050413) / fSlow32));
	double 	fSlow36 = (1 + ((0.5176380902050413 + fSlow34) / fSlow32));
	double 	fSlow37 = (1.0 / fSlow36);
	double 	fSlow38 = (1 + ((fSlow34 - 1.414213562373095) / fSlow32));
	double 	fSlow39 = (1.0 / (1 + ((fSlow34 + 1.414213562373095) / fSlow32)));
	double 	fSlow40 = (1 + ((fSlow34 - 1.9318516525781364) / fSlow32));
	double 	fSlow41 = (1.0 / (1 + ((fSlow34 + 1.9318516525781364) / fSlow32)));
	double 	fSlow42 = (2 * (0 - fSlow9));
	double 	fSlow43 = (fSlow4 / fSlow36);
	double 	fSlow44 = tan((fConst50 * (1800 - fSlow7)));
	double 	fSlow45 = (1.0 / faustpower<2>(fSlow44));
	double 	fSlow46 = (2 * (1 - fSlow45));
	double 	fSlow47 = (1.0 / fSlow44);
	double 	fSlow48 = (1 + ((fSlow47 - 0.5176380902050413) / fSlow44));
	double 	fSlow49 = (1.0 / (1 + ((0.5176380902050413 + fSlow47) / fSlow44)));
	double 	fSlow50 = (1 + ((fSlow47 - 1.414213562373095) / fSlow44));
	double 	fSlow51 = (1.0 / (1 + ((1.414213562373095 + fSlow47) / fSlow44)));
	double 	fSlow52 = (1 + ((fSlow47 - 1.9318516525781364) / fSlow44));
	double 	fSlow53 = (1.0 / (1 + ((1.9318516525781364 + fSlow47) / fSlow44)));
	double 	fSlow54 = (2 * (0 - fSlow45));
	double 	fSlow55 = ((0.6 + (0.4 * sqrt((0.3 + fSlow1)))) / fSlow24);
	for (int i=0; i<count; i++) {
		double fTemp0 = (double)input0[i];
		fVec0[IOTA&65535] = fTemp0;
		fRec6[0] = (fSlow0 + (0.999 * fRec6[1]));
		double fTemp1 = (fConst20 * fRec6[0]);
		int iTemp2 = int(fTemp1);
		int iTemp3 = (1 + iTemp2);
		fRec5[0] = ((((fTemp1 - iTemp2) * fVec0[(IOTA-int((int(iTemp3) & 65535)))&65535]) + ((iTemp3 - fTemp1) * fVec0[(IOTA-int((iTemp2 & 65535)))&65535])) - (fConst19 * ((fConst18 * fRec5[2]) + (fConst12 * fRec5[1]))));
		fRec4[0] = ((fConst19 * (((fConst11 * fRec5[0]) + (fConst21 * fRec5[1])) + (fConst11 * fRec5[2]))) - (fConst17 * ((fConst16 * fRec4[2]) + (fConst12 * fRec4[1]))));
		fRec3[0] = ((fConst17 * (((fConst11 * fRec4[0]) + (fConst21 * fRec4[1])) + (fConst11 * fRec4[2]))) - (fConst15 * ((fConst14 * fRec3[2]) + (fConst12 * fRec3[1]))));
		fRec2[0] = ((fConst15 * (((fConst11 * fRec3[0]) + (fConst21 * fRec3[1])) + (fConst11 * fRec3[2]))) - (fConst9 * ((fConst8 * fRec2[2]) + (fConst2 * fRec2[1]))));
		fRec1[0] = ((fConst9 * (fRec2[2] + (fRec2[0] + (2 * fRec2[1])))) - (fConst7 * ((fConst6 * fRec1[2]) + (fConst2 * fRec1[1]))));
		fRec0[0] = ((fConst7 * (fRec1[2] + (fRec1[0] + (2 * fRec1[1])))) - (fConst5 * ((fConst4 * fRec0[2]) + (fConst2 * fRec0[1]))));
		double fTemp4 = (double)input1[i];
		fVec1[IOTA&65535] = fTemp4;
		fRec8[0] = ((0.5 * (fVec0[IOTA&65535] + fVec1[IOTA&65535])) - (fConst29 * ((fConst28 * fRec8[2]) + (fConst24 * fRec8[1]))));
		fRec7[0] = ((fConst29 * (fRec8[2] + (fRec8[0] + (2 * fRec8[1])))) - (fConst27 * ((fConst26 * fRec7[2]) + (fConst24 * fRec7[1]))));
		double fTemp5 = (fConst27 * (fRec7[2] + (fRec7[0] + (2 * fRec7[1]))));
		double fTemp6 = (fConst41 * fRec6[0]);
		int iTemp7 = int(fTemp6);
		int iTemp8 = (1 + iTemp7);
		fRec14[0] = ((((fTemp6 - iTemp7) * fVec0[(IOTA-int((int(iTemp8) & 65535)))&65535]) + ((iTemp8 - fTemp6) * fVec0[(IOTA-int((iTemp7 & 65535)))&65535])) - (fConst39 * ((fConst38 * fRec14[2]) + (fConst32 * fRec14[1]))));
		fRec13[0] = ((fConst39 * (((fConst31 * fRec14[0]) + (fConst42 * fRec14[1])) + (fConst31 * fRec14[2]))) - (fConst37 * ((fConst36 * fRec13[2]) + (fConst32 * fRec13[1]))));
		fRec12[0] = ((fConst37 * (((fConst31 * fRec13[0]) + (fConst42 * fRec13[1])) + (fConst31 * fRec13[2]))) - (fConst35 * ((fConst34 * fRec12[2]) + (fConst32 * fRec12[1]))));
		fRec11[0] = ((fConst35 * (((fConst31 * fRec12[0]) + (fConst42 * fRec12[1])) + (fConst31 * fRec12[2]))) - (fConst19 * ((fConst18 * fRec11[2]) + (fConst12 * fRec11[1]))));
		fRec10[0] = ((fConst19 * (fRec11[2] + (fRec11[0] + (2 * fRec11[1])))) - (fConst17 * ((fConst16 * fRec10[2]) + (fConst12 * fRec10[1]))));
		fRec9[0] = ((fConst17 * (fRec10[2] + (fRec10[0] + (2 * fRec10[1])))) - (fConst15 * ((fConst14 * fRec9[2]) + (fConst12 * fRec9[1]))));
		double fTemp9 = (fConst40 * fRec6[0]);
		int iTemp10 = int(fTemp9);
		int iTemp11 = int((iTemp10 & 65535));
		int iTemp12 = (1 + iTemp10);
		double fTemp13 = (iTemp12 - fTemp9);
		int iTemp14 = int((int(iTemp12) & 65535));
		double fTemp15 = (fTemp9 - iTemp10);
		fRec20[0] = (((fTemp15 * fVec0[(IOTA-iTemp14)&65535]) + (fTemp13 * fVec0[(IOTA-iTemp11)&65535])) - (fConst48 * ((fConst47 * fRec20[2]) + (fConst24 * fRec20[1]))));
		fRec19[0] = ((fConst48 * (((fConst23 * fRec20[0]) + (fConst49 * fRec20[1])) + (fConst23 * fRec20[2]))) - (fConst46 * ((fConst45 * fRec19[2]) + (fConst24 * fRec19[1]))));
		fRec18[0] = ((fConst46 * (((fConst23 * fRec19[0]) + (fConst49 * fRec19[1])) + (fConst23 * fRec19[2]))) - (fConst44 * ((fConst43 * fRec18[2]) + (fConst24 * fRec18[1]))));
		fRec17[0] = ((fConst44 * (((fConst23 * fRec18[0]) + (fConst49 * fRec18[1])) + (fConst23 * fRec18[2]))) - (fConst39 * ((fConst38 * fRec17[2]) + (fConst32 * fRec17[1]))));
		fRec16[0] = ((fConst39 * (fRec17[2] + (fRec17[0] + (2 * fRec17[1])))) - (fConst37 * ((fConst36 * fRec16[2]) + (fConst32 * fRec16[1]))));
		fRec15[0] = ((fConst37 * (fRec16[2] + (fRec16[0] + (2 * fRec16[1])))) - (fConst35 * ((fConst34 * fRec15[2]) + (fConst32 * fRec15[1]))));
		output0[i] = (FAUSTFLOAT)((fSlow6 * (fRec15[2] + (fRec15[0] + (2 * fRec15[1])))) + ((fSlow5 * (fRec9[2] + (fRec9[0] + (2 * fRec9[1])))) + (fTemp5 + (fSlow3 * (fRec0[2] + (fRec0[0] + (2 * fRec0[1])))))));
		fRec26[0] = (((fTemp15 * fVec1[(IOTA-iTemp14)&65535]) + (fTemp13 * fVec1[(IOTA-iTemp11)&65535])) - (fSlow29 * ((fSlow28 * fRec26[2]) + (fSlow21 * fRec26[1]))));
		fRec25[0] = ((fSlow29 * (((fSlow20 * fRec26[0]) + (fSlow30 * fRec26[1])) + (fSlow20 * fRec26[2]))) - (fSlow27 * ((fSlow26 * fRec25[2]) + (fSlow21 * fRec25[1]))));
		fRec24[0] = ((fSlow27 * (((fSlow20 * fRec25[0]) + (fSlow30 * fRec25[1])) + (fSlow20 * fRec25[2]))) - (fSlow25 * ((fSlow23 * fRec24[2]) + (fSlow21 * fRec24[1]))));
		fRec23[0] = ((fSlow25 * (((fSlow20 * fRec24[0]) + (fSlow30 * fRec24[1])) + (fSlow20 * fRec24[2]))) - (fSlow18 * ((fSlow17 * fRec23[2]) + (fSlow10 * fRec23[1]))));
		fRec22[0] = ((fSlow18 * (fRec23[2] + (fRec23[0] + (2 * fRec23[1])))) - (fSlow16 * ((fSlow15 * fRec22[2]) + (fSlow10 * fRec22[1]))));
		fRec21[0] = ((fSlow16 * (fRec22[2] + (fRec22[0] + (2 * fRec22[1])))) - (fSlow14 * ((fSlow12 * fRec21[2]) + (fSlow10 * fRec21[1]))));
		double fTemp16 = (fConst51 * fRec6[0]);
		int iTemp17 = int(fTemp16);
		int iTemp18 = (1 + iTemp17);
		fRec32[0] = ((((fTemp16 - iTemp17) * fVec1[(IOTA-int((int(iTemp18) & 65535)))&65535]) + ((iTemp18 - fTemp16) * fVec1[(IOTA-int((iTemp17 & 65535)))&65535])) - (fSlow18 * ((fSlow17 * fRec32[2]) + (fSlow10 * fRec32[1]))));
		fRec31[0] = ((fSlow18 * (((fSlow9 * fRec32[0]) + (fSlow42 * fRec32[1])) + (fSlow9 * fRec32[2]))) - (fSlow16 * ((fSlow15 * fRec31[2]) + (fSlow10 * fRec31[1]))));
		fRec30[0] = ((fSlow16 * (((fSlow9 * fRec31[0]) + (fSlow42 * fRec31[1])) + (fSlow9 * fRec31[2]))) - (fSlow14 * ((fSlow12 * fRec30[2]) + (fSlow10 * fRec30[1]))));
		fRec29[0] = ((fSlow14 * (((fSlow9 * fRec30[0]) + (fSlow42 * fRec30[1])) + (fSlow9 * fRec30[2]))) - (fSlow41 * ((fSlow40 * fRec29[2]) + (fSlow33 * fRec29[1]))));
		fRec28[0] = ((fSlow41 * (fRec29[2] + (fRec29[0] + (2 * fRec29[1])))) - (fSlow39 * ((fSlow38 * fRec28[2]) + (fSlow33 * fRec28[1]))));
		fRec27[0] = ((fSlow39 * (fRec28[2] + (fRec28[0] + (2 * fRec28[1])))) - (fSlow37 * ((fSlow35 * fRec27[2]) + (fSlow33 * fRec27[1]))));
		double fTemp19 = (fConst52 * fRec6[0]);
		int iTemp20 = int(fTemp19);
		int iTemp21 = (1 + iTemp20);
		fRec38[0] = ((((fTemp19 - iTemp20) * fVec1[(IOTA-int((int(iTemp21) & 65535)))&65535]) + ((iTemp21 - fTemp19) * fVec1[(IOTA-int((iTemp20 & 65535)))&65535])) - (fSlow53 * ((fSlow52 * fRec38[2]) + (fSlow46 * fRec38[1]))));
		fRec37[0] = ((fSlow53 * (((fSlow45 * fRec38[0]) + (fSlow54 * fRec38[1])) + (fSlow45 * fRec38[2]))) - (fSlow51 * ((fSlow50 * fRec37[2]) + (fSlow46 * fRec37[1]))));
		fRec36[0] = ((fSlow51 * (((fSlow45 * fRec37[0]) + (fSlow54 * fRec37[1])) + (fSlow45 * fRec37[2]))) - (fSlow49 * ((fSlow48 * fRec36[2]) + (fSlow46 * fRec36[1]))));
		fRec35[0] = ((fSlow49 * (((fSlow45 * fRec36[0]) + (fSlow54 * fRec36[1])) + (fSlow45 * fRec36[2]))) - (fSlow29 * ((fSlow28 * fRec35[2]) + (fSlow21 * fRec35[1]))));
		fRec34[0] = ((fSlow29 * (fRec35[2] + (fRec35[0] + (2 * fRec35[1])))) - (fSlow27 * ((fSlow26 * fRec34[2]) + (fSlow21 * fRec34[1]))));
		fRec33[0] = ((fSlow27 * (fRec34[2] + (fRec34[0] + (2 * fRec34[1])))) - (fSlow25 * ((fSlow23 * fRec33[2]) + (fSlow21 * fRec33[1]))));
		output1[i] = (FAUSTFLOAT)(((fSlow55 * (fRec33[2] + (fRec33[0] + (2 * fRec33[1])))) + ((fSlow43 * (fRec27[2] + (fRec27[0] + (2 * fRec27[1])))) + (fSlow31 * (fRec21[2] + (fRec21[0] + (2 * fRec21[1])))))) + fTemp5);
		// post processing
		fRec33[2] = fRec33[1]; fRec33[1] = fRec33[0];
		fRec34[2] = fRec34[1]; fRec34[1] = fRec34[0];
		fRec35[2] = fRec35[1]; fRec35[1] = fRec35[0];
		fRec36[2] = fRec36[1]; fRec36[1] = fRec36[0];
		fRec37[2] = fRec37[1]; fRec37[1] = fRec37[0];
		fRec38[2] = fRec38[1]; fRec38[1] = fRec38[0];
		fRec27[2] = fRec27[1]; fRec27[1] = fRec27[0];
		fRec28[2] = fRec28[1]; fRec28[1] = fRec28[0];
		fRec29[2] = fRec29[1]; fRec29[1] = fRec29[0];
		fRec30[2] = fRec30[1]; fRec30[1] = fRec30[0];
		fRec31[2] = fRec31[1]; fRec31[1] = fRec31[0];
		fRec32[2] = fRec32[1]; fRec32[1] = fRec32[0];
		fRec21[2] = fRec21[1]; fRec21[1] = fRec21[0];
		fRec22[2] = fRec22[1]; fRec22[1] = fRec22[0];
		fRec23[2] = fRec23[1]; fRec23[1] = fRec23[0];
		fRec24[2] = fRec24[1]; fRec24[1] = fRec24[0];
		fRec25[2] = fRec25[1]; fRec25[1] = fRec25[0];
		fRec26[2] = fRec26[1]; fRec26[1] = fRec26[0];
		fRec15[2] = fRec15[1]; fRec15[1] = fRec15[0];
		fRec16[2] = fRec16[1]; fRec16[1] = fRec16[0];
		fRec17[2] = fRec17[1]; fRec17[1] = fRec17[0];
		fRec18[2] = fRec18[1]; fRec18[1] = fRec18[0];
		fRec19[2] = fRec19[1]; fRec19[1] = fRec19[0];
		fRec20[2] = fRec20[1]; fRec20[1] = fRec20[0];
		fRec9[2] = fRec9[1]; fRec9[1] = fRec9[0];
		fRec10[2] = fRec10[1]; fRec10[1] = fRec10[0];
		fRec11[2] = fRec11[1]; fRec11[1] = fRec11[0];
		fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
		fRec13[2] = fRec13[1]; fRec13[1] = fRec13[0];
		fRec14[2] = fRec14[1]; fRec14[1] = fRec14[0];
		fRec7[2] = fRec7[1]; fRec7[1] = fRec7[0];
		fRec8[2] = fRec8[1]; fRec8[1] = fRec8[0];
		fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
		fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
		fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
		fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
		fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
		fRec6[1] = fRec6[0];
		IOTA = IOTA+1;
	}
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1, PluginDef *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, input1, output0, output1);
}

int Dsp::register_par(const ParamReg& reg)
{
	reg.registerVar("panoram enhancer.Delay width","","S","",&fslider0, 0.0, 0.0, 1.0, 0.01);
	reg.registerVar("panoram enhancer.Frequency width","","S","",&fslider1, 0.0, 0.0, 1.0, 0.01);
	return 0;
}

int Dsp::register_params_static(const ParamReg& reg)
{
	return static_cast<Dsp*>(reg.plugin)->register_par(reg);
}

inline int Dsp::load_ui_f(const UiBuilder& b, int form)
{
    if (form & UI_FORM_STACK) {
#define PARAM(p) ("panoram enhancer" "." p)
// ----- panoram enhancer
b.openHorizontalhideBox("");
b.closeBox();
b.openVerticalBox("");
{
    b.openHorizontalTableBox("");
    {
	b.create_small_rackknob(PARAM("Delay width"), _("  delay width  "));
	b.create_small_rackknob(PARAM("Frequency width"), _("  freq width   "));
    }
    b.closeBox();
}
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

} // end namespace panoram_enhancer
