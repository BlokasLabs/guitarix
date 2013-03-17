/*
 * Copyright (C) 2012 Hermann Meyer, Andreas Degert, Pete Shorthose
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * --------------------------------------------------------------------------
 */

/*
	SHP :
	Attempt to do 12ax7/6v6 as new LV2 plugin

	Seems to work but for some reason controls not as expected.
	Pregain changes tone not volume.
	Both Cabinet and Presence effect volume too much.
	Presets unpredictable, choosing save reloads old values!
	
	Like the idea of separate cabinet for mix and match so look into that.
	Just one cabinet plugin switchable IR, bass and treble aswell as level!

	TODO : Stereo stuff ( not important for me )
*/


inline void GxAmp7Mono::clear_state_f()
{
	for (int i=0; i<2; i++) fRec5[i] = 0;
	for (int i=0; i<2; i++) fRec6[i] = 0;
	for (int i=0; i<2; i++) fRec8[i] = 0;
	for (int i=0; i<2; i++) fVec0[i] = 0;
	for (int i=0; i<2; i++) fRec21[i] = 0;
	for (int i=0; i<2; i++) fRec20[i] = 0;
	for (int i=0; i<3; i++) fRec19[i] = 0;
	for (int i=0; i<3; i++) fRec18[i] = 0;
	for (int i=0; i<2; i++) fRec22[i] = 0;
	for (int i=0; i<2; i++) fRec23[i] = 0;
	for (int i=0; i<3; i++) fRec17[i] = 0;
	for (int i=0; i<2; i++) fRec16[i] = 0;
	for (int i=0; i<2; i++) fRec26[i] = 0;
	for (int i=0; i<3; i++) fRec25[i] = 0;
	for (int i=0; i<2; i++) fRec24[i] = 0;
	for (int i=0; i<2; i++) fRec15[i] = 0;
	for (int i=0; i<2; i++) fRec14[i] = 0;
	for (int i=0; i<2; i++) fRec27[i] = 0;
	for (int i=0; i<3; i++) fRec13[i] = 0;
	for (int i=0; i<2; i++) fRec12[i] = 0;
	for (int i=0; i<2; i++) fRec30[i] = 0;
	for (int i=0; i<3; i++) fRec29[i] = 0;
	for (int i=0; i<2; i++) fRec28[i] = 0;
	for (int i=0; i<2; i++) fRec11[i] = 0;
	for (int i=0; i<2; i++) fRec31[i] = 0;
	for (int i=0; i<3; i++) fRec10[i] = 0;
	for (int i=0; i<2; i++) fRec9[i] = 0;
	for (int i=0; i<2; i++) fRec34[i] = 0;
	for (int i=0; i<32768; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec33[i] = 0;
	for (int i=0; i<2; i++) fRec32[i] = 0;
	for (int i=0; i<3; i++) fRec42[i] = 0;
	for (int i=0; i<2; i++) fVec2[i] = 0;
	for (int i=0; i<2; i++) fRec41[i] = 0;
	for (int i=0; i<2; i++) fRec40[i] = 0;
	for (int i=0; i<3; i++) fRec39[i] = 0;
	for (int i=0; i<2; i++) fVec3[i] = 0;
	for (int i=0; i<2; i++) fRec38[i] = 0;
	for (int i=0; i<3; i++) fRec37[i] = 0;
	for (int i=0; i<3; i++) fRec36[i] = 0;
	for (int i=0; i<2; i++) fRec46[i] = 0;
	for (int i=0; i<3; i++) fRec45[i] = 0;
	for (int i=0; i<2; i++) fVec4[i] = 0;
	for (int i=0; i<2; i++) fRec44[i] = 0;
	for (int i=0; i<3; i++) fRec43[i] = 0;
	for (int i=0; i<2; i++) fRec50[i] = 0;
	for (int i=0; i<3; i++) fRec49[i] = 0;
	for (int i=0; i<3; i++) fRec48[i] = 0;
	for (int i=0; i<3; i++) fRec47[i] = 0;
	for (int i=0; i<2; i++) fRec52[i] = 0;
	for (int i=0; i<3; i++) fRec51[i] = 0;
	for (int i=0; i<2; i++) fVec5[i] = 0;
	for (int i=0; i<2; i++) fRec35[i] = 0;
	for (int i=0; i<2; i++) fVec6[i] = 0;
	for (int i=0; i<2; i++) fRec7[i] = 0;
	for (int i=0; i<3; i++) fRec4[i] = 0;
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fRec55[i] = 0;
	for (int i=0; i<3; i++) fRec54[i] = 0;
	for (int i=0; i<2; i++) fRec53[i] = 0;
	for (int i=0; i<3; i++) fVec7[i] = 0;
	for (int i=0; i<3; i++) fRec2[i] = 0;
	for (int i=0; i<3; i++) fRec1[i] = 0;
	for (int i=0; i<3; i++) fRec0[i] = 0;
}

inline void GxAmp7Mono::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = (31704.95306002819 / iConst0);
	fConst2 = (2 * cos(fConst1));
	fConst3 = (0.026178010471204185 * sin(fConst1));
	fConst4 = (fConst3 - 1);
	fConst5 = (49574.33207364693 / iConst0);
	fConst6 = (2 * cos(fConst5));
	fConst7 = (0.07042253521126761 * sin(fConst5));
	fConst8 = (fConst7 - 1);
	fConst9 = (60601.32228774711 / iConst0);
	fConst10 = (2 * cos(fConst9));
	fConst11 = (0.03546099290780142 * sin(fConst9));
	fConst12 = (fConst11 - 1);
	fConst13 = (1.0 / tan((97.38937226128358 / iConst0)));
	fConst14 = (1 + fConst13);
	fConst15 = (0 - ((1 - fConst13) / fConst14));
	fConst16 = (1.0 / tan((20517.741620594938 / iConst0)));
	fConst17 = (1 + fConst16);
	fConst18 = (0 - ((1 - fConst16) / fConst17));
	fConst19 = (0.0041 / fConst17);
	fConst20 = tan((37699.11184307752 / iConst0));
	fConst21 = (2 * (1 - (1.0 / faustpower<2>(fConst20))));
	fConst22 = (1.0 / fConst20);
	fConst23 = (1 + ((fConst22 - 0.7653668647301795) / fConst20));
	fConst24 = (1.0 / (1 + ((0.7653668647301795 + fConst22) / fConst20)));
	fConst25 = (1 + ((fConst22 - 1.8477590650225735) / fConst20));
	fConst26 = (1.0 / (1 + ((fConst22 + 1.8477590650225735) / fConst20)));
	fConst27 = (973.8937226128359 / iConst0);
	fConst28 = (1 - fConst27);
	fConst29 = (1.0 / (1 + fConst27));
	fConst30 = (1.0 / tan((270.1769682087222 / iConst0)));
	fConst31 = (1 + fConst30);
	fConst32 = (0 - ((1 - fConst30) / fConst31));
	fConst33 = (0.027 / fConst31);
	fConst34 = (0 - fConst13);
	fConst35 = (0.025 / fConst14);
	fConst36 = (1.0 / tan((414.6902302738527 / iConst0)));
	fConst37 = (1 + fConst36);
	fConst38 = (0 - ((1 - fConst36) / fConst37));
	fConst39 = (0.015 / fConst37);
	fConst40 = (1.0 / fConst17);
	fConst41 = (1.0 / tan((609.4689747964198 / iConst0)));
	fConst42 = (1 + fConst41);
	fConst43 = (0 - ((1 - fConst41) / fConst42));
	fConst44 = (0.0082 / fConst42);
	IOTA = 0;
	iConst45 = int((int((0.1111111111111111 * iConst0)) & 65535));
	fConst46 = (0.009000000000000008 / iConst0);
	fConst47 = tan((942.4777960769379 / iConst0));
	fConst48 = (1.0 / faustpower<2>(fConst47));
	fConst49 = (2 * (1 - fConst48));
	fConst50 = (1.0 / fConst47);
	fConst51 = (1 + ((fConst50 - 1.0) / fConst47));
	fConst52 = (1.0 / (1 + ((1.0 + fConst50) / fConst47)));
	fConst53 = tan((3769.9111843077517 / iConst0));
	fConst54 = (1.0 / faustpower<2>(fConst53));
	fConst55 = (2 * (1 - fConst54));
	fConst56 = (1.0 / fConst53);
	fConst57 = (1 + ((fConst56 - 1.0000000000000004) / fConst53));
	fConst58 = (1 + ((fConst56 + 1.0000000000000004) / fConst53));
	fConst59 = (1.0 / fConst58);
	fConst60 = (1 + fConst56);
	fConst61 = (0 - ((1 - fConst56) / fConst60));
	fConst62 = tan((10053.096491487338 / iConst0));
	fConst63 = (1.0 / faustpower<2>(fConst62));
	fConst64 = (2 * (1 - fConst63));
	fConst65 = (1.0 / fConst62);
	fConst66 = (1 + ((fConst65 - 1.0000000000000004) / fConst62));
	fConst67 = (1 + ((1.0000000000000004 + fConst65) / fConst62));
	fConst68 = (1.0 / fConst67);
	fConst69 = (1 + fConst65);
	fConst70 = (0 - ((1 - fConst65) / fConst69));
	fConst71 = tan((47123.8898038469 / iConst0));
	fConst72 = (2 * (1 - (1.0 / faustpower<2>(fConst71))));
	fConst73 = (1.0 / fConst71);
	fConst74 = (1 + ((fConst73 - 1.414213562373095) / fConst71));
	fConst75 = (1 + ((1.414213562373095 + fConst73) / fConst71));
	fConst76 = (1.0 / fConst75);
	fConst77 = (1.0 / (fConst14 * fConst75));
	fConst78 = (1.0 / fConst69);
	fConst79 = (0 - fConst56);
	fConst80 = (1.0 / (fConst60 * fConst67));
	fConst81 = (2 * (0 - fConst54));
	fConst82 = (1 + ((fConst50 - 1.0000000000000004) / fConst47));
	fConst83 = (1.0 / (1 + ((fConst50 + 1.0000000000000004) / fConst47)));
	fConst84 = (1 + fConst50);
	fConst85 = (0 - ((1 - fConst50) / fConst84));
	fConst86 = (0 - fConst50);
	fConst87 = (1.0 / (fConst84 * fConst58));
	fConst88 = (2 * (0 - fConst48));
	fConst89 = (1 + ((fConst56 - 1.0) / fConst53));
	fConst90 = (1.0 / (1 + ((1.0 + fConst56) / fConst53)));
	fConst91 = (0 - fConst65);
	fConst92 = (2 * (0 - fConst63));
	fConst93 = (0 - fConst10);
	fConst94 = (1.0 / (1 + fConst11));
	fConst95 = (0 - fConst6);
	fConst96 = (1.0 / (1 + fConst7));
	fConst97 = (0 - fConst2);
	fConst98 = (1.0 / (1 + fConst3));
	clear_state_f();
}

// SHP these were wrong way round !
void GxAmp7Mono::connect(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {
    case AMP_MASTERGAIN:
      fslider0_ = (float*)data;
      break;
    case AMP_PREGAIN:
      fslider2_ = (float*)data;
      break;
    case AMP_WET_DRY:
      fslider1_ = (float*)data;
      break;
    case AMP_DRIVE:
      fslider3_ = (float*)data;
      break;
    default:
      break;
    }
}

void GxAmp7Mono::run_12ax7pp6v6(uint32_t n_samples, float* input0, float* output0)
{
  fslider0  = (*fslider0_);
  fslider1  = (*fslider1_);
  fslider2  = (*fslider2_);
  fslider3  = (*fslider3_);

	double 	fSlow0 = (0.0010000000000000009 * pow(10,(0.05 * fslider0)));
	double 	fSlow1 = (1.000000000000001e-05 * fslider1);
	double 	fSlow2 = (0.0010000000000000009 * pow(10,(0.05 * fslider2)));
	double 	fSlow3 = fslider3;
	double 	fSlow4 = (1.25 * fSlow3);
	double 	fSlow5 = (2 * (fSlow3 - 0.5));
	double 	fSlow6 = (0.024937655860349125 * (1 - max(0, fSlow5)));
	double 	fSlow7 = pow(1e+01,(1.2 * fSlow3));
	double 	fSlow8 = (fConst83 * pow(1e+01,(2 * fSlow3)));
	double 	fSlow9 = pow(1e+01,(0.8 * fSlow3));
	double 	fSlow10 = (fConst83 * pow(1e+01,(0.9 * fSlow3)));
	double 	fSlow11 = (1 - max(0, (0 - fSlow5)));
	for (uint32_t i=0; i<n_samples; i++) {
		fRec5[0] = ((fConst19 * (fRec4[1] + fRec4[2])) + (fConst18 * fRec5[1]));
		fRec6[0] = (fSlow0 + (0.999 * fRec6[1]));
		fRec8[0] = (fSlow1 + (0.999 * fRec8[1]));
		double fTemp0 = (double)input0[i];
		fVec0[0] = fTemp0;
		fRec21[0] = (fConst29 * ((fVec0[0] - fVec0[1]) + (fConst28 * fRec21[1])));
		fRec20[0] = (fConst29 * ((fRec21[0] - fRec21[1]) + (fConst28 * fRec20[1])));
		fRec19[0] = (fRec20[0] - (fConst26 * ((fConst25 * fRec19[2]) + (fConst21 * fRec19[1]))));
		fRec18[0] = ((fConst26 * (fRec19[2] + (fRec19[0] + (2 * fRec19[1])))) - (fConst24 * ((fConst23 * fRec18[2]) + (fConst21 * fRec18[1]))));
		fRec22[0] = (fSlow2 + (0.999 * fRec22[1]));
		fRec23[0] = ((fConst33 * (fRec17[1] + fRec17[2])) + (fConst32 * fRec23[1]));
		fRec17[0] = (Ftube(TUBE_TABLE_12AX7_68k, ((fRec23[0] + (fConst24 * (fRec22[0] * (fRec18[2] + (fRec18[0] + (2 * fRec18[1])))))) - 1.581656)) - 191.42014814814814);
		fRec16[0] = ((fConst35 * ((fConst34 * fRec17[1]) + (fConst13 * fRec17[0]))) + (fConst15 * fRec16[1]));
		fRec26[0] = ((fConst39 * (fRec25[1] + fRec25[2])) + (fConst38 * fRec26[1]));
		fRec25[0] = (Ftube(TUBE_TABLE_12AX7_250k, ((fRec26[0] + fRec15[1]) - 1.204285)) - 169.71433333333334);
		fRec24[0] = ((fConst35 * ((fConst34 * fRec25[1]) + (fConst13 * fRec25[0]))) + (fConst15 * fRec24[1]));
		fRec15[0] = ((0.6 * fRec24[0]) + fRec16[0]);
		fRec14[0] = ((fConst40 * (fRec15[0] + fRec15[1])) + (fConst18 * fRec14[1]));
		fRec27[0] = ((fConst39 * (fRec13[1] + fRec13[2])) + (fConst38 * fRec27[1]));
		fRec13[0] = (Ftube(TUBE_TABLE_12AX7_250k, ((fRec27[0] + fRec14[0]) - 1.204285)) - 169.71433333333334);
		fRec12[0] = ((fConst35 * ((fConst34 * fRec13[1]) + (fConst13 * fRec13[0]))) + (fConst15 * fRec12[1]));
		fRec30[0] = ((fConst44 * (fRec29[1] + fRec29[2])) + (fConst43 * fRec30[1]));
		fRec29[0] = (Ftube(TUBE_TABLE_12AX7_250k, ((fRec30[0] + fRec11[1]) - 0.840703)) - 147.47524390243905);
		fRec28[0] = ((fConst35 * ((fConst34 * fRec29[1]) + (fConst13 * fRec29[0]))) + (fConst15 * fRec28[1]));
		fRec11[0] = ((0.6 * fRec28[0]) + fRec12[0]);
		fRec31[0] = ((fConst44 * (fRec10[1] + fRec10[2])) + (fConst43 * fRec31[1]));
		fRec10[0] = (Ftube(TUBE_TABLE_12AX7_250k, ((fRec31[0] + fRec11[0]) - 0.840703)) - 147.47524390243905);
		fRec9[0] = ((fConst35 * ((fConst34 * fRec10[1]) + (fConst13 * fRec10[0]))) + (fConst15 * fRec9[1]));
		double fTemp1 = (fRec9[0] * (1 - fRec8[0]));
		double fTemp2 = (fRec9[0] * fRec8[0]);
		double fTemp3 = fabs(fTemp2);
		fRec34[0] = ((9.999999999998899e-05 * fTemp3) + (0.9999 * fRec34[1]));
		double fTemp4 = max(fRec34[0], fTemp3);
		fVec1[IOTA&32767] = fTemp4;
		fRec33[0] = ((fVec1[IOTA&32767] + fRec33[1]) - fVec1[(IOTA-iConst45)&32767]);
		fRec32[0] = ((fConst46 * fRec33[0]) + (0.999 * fRec32[1]));
		double fTemp5 = max(-1.0, min(-0.01, (fVec1[IOTA&32767] - (1.0 + (1.02 * fRec32[0])))));
		double fTemp6 = (0 - fTemp5);
		double fTemp7 = (40.1 * fTemp6);
		double fTemp8 = max(-600, fTemp7);
		double fTemp9 = (0 - fTemp8);
		double fTemp10 = (fTemp2 - fTemp5);
		double fTemp11 = (40.1 * fTemp10);
		double fTemp12 = max(-600, fTemp11);
		double fTemp13 = (0 - fTemp12);
		double fTemp14 = (((int((fabs(fTemp11) > 0.0001)))?((int((fTemp12 < -50)))?(exp(fTemp12) * fTemp13):(fTemp12 / (1 - exp(fTemp13)))):(1 + (fTemp10 * (20.05 + (134.00083333333336 * fTemp10))))) - ((int((fabs(fTemp7) > 0.0001)))?((int((fTemp8 < -50)))?(exp(fTemp8) * fTemp9):(fTemp8 / (1 - exp(fTemp9)))):(1 + (fTemp6 * (20.05 + (134.00083333333336 * fTemp6))))));
		double fTemp15 = (fConst49 * fRec36[1]);
		fRec42[0] = ((0.024937655860349125 * fTemp14) - (fConst76 * ((fConst74 * fRec42[2]) + (fConst72 * fRec42[1]))));
		double fTemp16 = (fRec42[2] + (fRec42[0] + (2 * fRec42[1])));
		fVec2[0] = fTemp16;
		fRec41[0] = ((fConst77 * ((fConst34 * fVec2[1]) + (fConst13 * fVec2[0]))) + (fConst15 * fRec41[1]));
		fRec40[0] = ((fConst78 * (fRec41[0] + fRec41[1])) + (fConst70 * fRec40[1]));
		fRec39[0] = (fRec40[0] - (fConst68 * ((fConst66 * fRec39[2]) + (fConst64 * fRec39[1]))));
		double fTemp17 = (fRec39[2] + (fRec39[0] + (2 * fRec39[1])));
		fVec3[0] = fTemp17;
		fRec38[0] = ((fConst80 * ((fConst79 * fVec3[1]) + (fConst56 * fVec3[0]))) + (fConst61 * fRec38[1]));
		fRec37[0] = (fRec38[0] - (fConst59 * ((fConst57 * fRec37[2]) + (fConst55 * fRec37[1]))));
		fRec36[0] = ((fConst59 * (((fConst54 * fRec37[0]) + (fConst81 * fRec37[1])) + (fConst54 * fRec37[2]))) - (fConst52 * ((fConst51 * fRec36[2]) + fTemp15)));
		double fTemp18 = max(-1, min(1, (fSlow7 * (fRec36[2] + (fConst52 * (fTemp15 + (fConst51 * fRec36[0])))))));
		fRec46[0] = ((fConst80 * (fVec3[0] + fVec3[1])) + (fConst61 * fRec46[1]));
		fRec45[0] = (fRec46[0] - (fConst59 * ((fConst57 * fRec45[2]) + (fConst55 * fRec45[1]))));
		double fTemp19 = (fRec45[2] + (fRec45[0] + (2 * fRec45[1])));
		fVec4[0] = fTemp19;
		fRec44[0] = ((fConst87 * ((fConst86 * fVec4[1]) + (fConst50 * fVec4[0]))) + (fConst85 * fRec44[1]));
		fRec43[0] = (fRec44[0] - (fConst83 * ((fConst82 * fRec43[2]) + (fConst49 * fRec43[1]))));
		double fTemp20 = max(-1, min(1, (fSlow8 * (((fConst48 * fRec43[0]) + (fConst88 * fRec43[1])) + (fConst48 * fRec43[2])))));
		double fTemp21 = (fConst49 * fRec47[1]);
		double fTemp22 = (fConst55 * fRec48[1]);
		fRec50[0] = ((fConst78 * ((fConst91 * fRec41[1]) + (fConst65 * fRec41[0]))) + (fConst70 * fRec50[1]));
		fRec49[0] = (fRec50[0] - (fConst68 * ((fConst66 * fRec49[2]) + (fConst64 * fRec49[1]))));
		fRec48[0] = ((fConst68 * (((fConst63 * fRec49[0]) + (fConst92 * fRec49[1])) + (fConst63 * fRec49[2]))) - (fConst90 * ((fConst89 * fRec48[2]) + fTemp22)));
		fRec47[0] = ((fRec48[2] + (fConst90 * (fTemp22 + (fConst89 * fRec48[0])))) - (fConst52 * ((fConst51 * fRec47[2]) + fTemp21)));
		double fTemp23 = max(-1, min(1, (fSlow9 * (fRec47[2] + (fConst52 * (fTemp21 + (fConst51 * fRec47[0])))))));
		fRec52[0] = ((fConst87 * (fVec4[0] + fVec4[1])) + (fConst85 * fRec52[1]));
		fRec51[0] = (fRec52[0] - (fConst83 * ((fConst82 * fRec51[2]) + (fConst49 * fRec51[1]))));
		double fTemp24 = max(-1, min(1, (fSlow10 * (fRec51[2] + (fRec51[0] + (2 * fRec51[1]))))));
		double fTemp25 = ((1.2589412 * (fTemp24 * (1 - (0.3333333333333333 * faustpower<2>(fTemp24))))) + (1.584893192 * ((fTemp23 * (1 - (0.3333333333333333 * faustpower<2>(fTemp23)))) + ((fTemp20 * (1 - (0.3333333333333333 * faustpower<2>(fTemp20)))) + (0.8413951417869425 * (fTemp18 * (1 - (0.3333333333333333 * faustpower<2>(fTemp18)))))))));
		fVec5[0] = fTemp25;
		fRec35[0] = ((fConst40 * (fVec5[0] + fVec5[1])) + (fConst18 * fRec35[1]));
		double fTemp26 = (((fSlow11 * fRec35[0]) + (fSlow6 * fTemp14)) + (fTemp1 * (1 + (fSlow4 * ((4 - (4 * fabs(fTemp1))) - 1)))));
		fVec6[0] = fTemp26;
		fRec7[0] = ((fConst40 * (fVec6[0] + fVec6[1])) + (fConst18 * fRec7[1]));
		double fTemp27 = (fRec7[0] * fRec6[0]);
		fRec4[0] = (Ftube(TUBE_TABLE_6V6_68k, ((fTemp27 + fRec5[0]) - 0.664541)) - 87.91682926829267);
		fRec3[0] = ((fConst35 * ((fConst34 * fRec4[1]) + (fConst13 * fRec4[0]))) + (fConst15 * fRec3[1]));
		fRec55[0] = ((fConst19 * (fRec54[1] + fRec54[2])) + (fConst18 * fRec55[1]));
		fRec54[0] = (Ftube(TUBE_TABLE_6V6_250k, ((fRec55[0] + fTemp27) - 0.659761)) - 89.08268292682925);
		fRec53[0] = ((fConst35 * ((fConst34 * fRec54[1]) + (fConst13 * fRec54[0]))) + (fConst15 * fRec53[1]));
		double fTemp28 = (min(0.7, fRec53[0]) + max(-0.75, fRec3[0]));
		fVec7[0] = fTemp28;
		fRec2[0] = (fConst94 * ((fVec7[2] + (fVec7[0] + (fConst93 * fVec7[1]))) + ((fConst12 * fRec2[2]) + (fConst10 * fRec2[1]))));
		fRec1[0] = (fConst96 * ((fRec2[2] + (fRec2[0] + (fConst95 * fRec2[1]))) + ((fConst8 * fRec1[2]) + (fConst6 * fRec1[1]))));
		fRec0[0] = (fConst98 * ((fRec1[2] + (fRec1[0] + (fConst97 * fRec1[1]))) + ((fConst4 * fRec0[2]) + (fConst2 * fRec0[1]))));
		output0[i] = (FAUSTFLOAT)fRec0[0];
		// post processing
		fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
		fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
		fVec7[2] = fVec7[1]; fVec7[1] = fVec7[0];
		fRec53[1] = fRec53[0];
		fRec54[2] = fRec54[1]; fRec54[1] = fRec54[0];
		fRec55[1] = fRec55[0];
		fRec3[1] = fRec3[0];
		fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
		fRec7[1] = fRec7[0];
		fVec6[1] = fVec6[0];
		fRec35[1] = fRec35[0];
		fVec5[1] = fVec5[0];
		fRec51[2] = fRec51[1]; fRec51[1] = fRec51[0];
		fRec52[1] = fRec52[0];
		fRec47[2] = fRec47[1]; fRec47[1] = fRec47[0];
		fRec48[2] = fRec48[1]; fRec48[1] = fRec48[0];
		fRec49[2] = fRec49[1]; fRec49[1] = fRec49[0];
		fRec50[1] = fRec50[0];
		fRec43[2] = fRec43[1]; fRec43[1] = fRec43[0];
		fRec44[1] = fRec44[0];
		fVec4[1] = fVec4[0];
		fRec45[2] = fRec45[1]; fRec45[1] = fRec45[0];
		fRec46[1] = fRec46[0];
		fRec36[2] = fRec36[1]; fRec36[1] = fRec36[0];
		fRec37[2] = fRec37[1]; fRec37[1] = fRec37[0];
		fRec38[1] = fRec38[0];
		fVec3[1] = fVec3[0];
		fRec39[2] = fRec39[1]; fRec39[1] = fRec39[0];
		fRec40[1] = fRec40[0];
		fRec41[1] = fRec41[0];
		fVec2[1] = fVec2[0];
		fRec42[2] = fRec42[1]; fRec42[1] = fRec42[0];
		fRec32[1] = fRec32[0];
		fRec33[1] = fRec33[0];
		IOTA = IOTA+1;
		fRec34[1] = fRec34[0];
		fRec9[1] = fRec9[0];
		fRec10[2] = fRec10[1]; fRec10[1] = fRec10[0];
		fRec31[1] = fRec31[0];
		fRec11[1] = fRec11[0];
		fRec28[1] = fRec28[0];
		fRec29[2] = fRec29[1]; fRec29[1] = fRec29[0];
		fRec30[1] = fRec30[0];
		fRec12[1] = fRec12[0];
		fRec13[2] = fRec13[1]; fRec13[1] = fRec13[0];
		fRec27[1] = fRec27[0];
		fRec14[1] = fRec14[0];
		fRec15[1] = fRec15[0];
		fRec24[1] = fRec24[0];
		fRec25[2] = fRec25[1]; fRec25[1] = fRec25[0];
		fRec26[1] = fRec26[0];
		fRec16[1] = fRec16[0];
		fRec17[2] = fRec17[1]; fRec17[1] = fRec17[0];
		fRec23[1] = fRec23[0];
		fRec22[1] = fRec22[0];
		fRec18[2] = fRec18[1]; fRec18[1] = fRec18[0];
		fRec19[2] = fRec19[1]; fRec19[1] = fRec19[0];
		fRec20[1] = fRec20[0];
		fRec21[1] = fRec21[0];
		fVec0[1] = fVec0[0];
		fRec8[1] = fRec8[0];
		fRec6[1] = fRec6[0];
		fRec5[1] = fRec5[0];
	}

}


// static wrappers
void GxAmp7Mono::init_static(uint32_t samplingFreq, GxAmp7Mono *p)
{
  p->init(samplingFreq);
}

void GxAmp7Mono::connect_static(uint32_t port,void* data, GxAmp7Mono *p)
{
  p->connect(port, data);
}


