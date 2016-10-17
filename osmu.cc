// generated from file './/osmu.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace osmu {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	class SIG0 {
	  private:
		int 	fSamplingFreq;
		static double 	fWave0[100];
		int 	idxfWave0;
	  public:
		int getNumInputs() 	{ return 0; }
		int getNumOutputs() 	{ return 1; }
		void init(int samplingFreq) {
			fSamplingFreq = samplingFreq;
			idxfWave0 = 0;
		}
		void fill (int count, double output[]) {
			for (int i=0; i<count; i++) {
				output[i] = fWave0[idxfWave0];
				// post processing
				idxfWave0 = (idxfWave0 + 1) % 100;
			}
		}
	};
			int 	iConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fVec0[2];
	double 	fRec0[3];
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
	double 	fRec5[2];
	double 	fRec4[3];
	double 	fRec3[3];
	double 	fConst22;
	double 	fConst23;
	double 	fVec1[2];
	double 	fConst24;
	double 	fRec2[2];
	double 	fRec1[3];
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	static double 	ftbl0[100];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec6[2];
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


double Dsp::ftbl0[100];

Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "osmu";
	name = N_("OsMutantes");
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
	for (int i=0; i<2; i++) fVec0[i] = 0;
	for (int i=0; i<3; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fRec5[i] = 0;
	for (int i=0; i<3; i++) fRec4[i] = 0;
	for (int i=0; i<3; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec2[i] = 0;
	for (int i=0; i<3; i++) fRec1[i] = 0;
	for (int i=0; i<2; i++) fRec6[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	SIG0 sig0;
	sig0.init(samplingFreq);
	sig0.fill(100,ftbl0);
	fSamplingFreq = samplingFreq;
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = double(iConst0);
	fConst2 = (4.16598233679216e-10 * fConst1);
	fConst3 = (4.20565481840985e-05 + (fConst1 * (fConst2 - 8.35741938643787e-07)));
	fConst4 = faustpower<2>(fConst1);
	fConst5 = (8.4113096368197e-05 - (8.33196467358432e-10 * fConst4));
	fConst6 = (1.0 / (4.20565481840985e-05 + (fConst1 * (8.35741938643787e-07 + fConst2))));
	fConst7 = (1.96120359895771e-07 * fConst4);
	fConst8 = (0 - (3.92240719791542e-07 * fConst4));
	fConst9 = tan((20517.741620594938 / double(iConst0)));
	fConst10 = (2 * (1 - (1.0 / faustpower<2>(fConst9))));
	fConst11 = (1.0 / fConst9);
	fConst12 = (1 + ((fConst11 - 1.0000000000000004) / fConst9));
	fConst13 = (1.0 / (1 + ((1.0000000000000004 + fConst11) / fConst9)));
	fConst14 = (2.69295148782388e-10 * fConst1);
	fConst15 = (0.0906470652808894 + (fConst1 * (fConst14 - 6.01868566509352e-06)));
	fConst16 = (0.181294130561779 - (5.38590297564776e-10 * fConst4));
	fConst17 = (0.0906470652808894 + (fConst1 * (6.01868566509352e-06 + fConst14)));
	fConst18 = (1.0 / fConst17);
	fConst19 = (1 + fConst11);
	fConst20 = (1.0 / fConst19);
	fConst21 = (0 - ((1 - fConst11) / fConst19));
	fConst22 = (1.26775049023867e-07 * fConst4);
	fConst23 = (0 - (2.53550098047734e-07 * fConst4));
	fConst24 = (1.0 / (fConst19 * fConst17));
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
	int 	iSlow0 = int(double(fslider0));
	double 	fSlow1 = (0.007000000000000006 * double(fslider1));
	for (int i=0; i<count; i++) {
		double fTemp0 = (double)input0[i];
		fVec0[0] = fTemp0;
		fRec0[0] = (fVec0[0] - (fConst6 * ((fConst5 * fRec0[1]) + (fConst3 * fRec0[2]))));
		fRec5[0] = ((fConst21 * fRec5[1]) + (fConst20 * (fVec0[0] + fVec0[1])));
		fRec4[0] = (fRec5[0] - (fConst13 * ((fConst12 * fRec4[2]) + (fConst10 * fRec4[1]))));
		fRec3[0] = ((fConst13 * (fRec4[2] + (fRec4[0] + (2 * fRec4[1])))) - (fConst18 * ((fConst16 * fRec3[1]) + (fConst15 * fRec3[2]))));
		double fTemp1 = (((fConst23 * fRec3[1]) + (fConst22 * fRec3[0])) + (fConst22 * fRec3[2]));
		fVec1[0] = fTemp1;
		fRec2[0] = ((fConst21 * fRec2[1]) + (fConst24 * (fVec1[0] + fVec1[1])));
		fRec1[0] = (fRec2[0] - (fConst13 * ((fConst12 * fRec1[2]) + (fConst10 * fRec1[1]))));
		double fTemp2 = ((iSlow0)?(fConst13 * (fRec1[2] + (fRec1[0] + (2 * fRec1[1])))):(fConst6 * (((fConst8 * fRec0[1]) + (fConst7 * fRec0[0])) + (fConst7 * fRec0[2]))));
		double fTemp3 = fabs(fTemp2);
		double fTemp4 = (101.97 * ((fTemp3 / (3.0 + fTemp3)) - 0.005));
		double fTemp5 = max((double)0, min((double)99, floor(fTemp4)));
		double fTemp6 = ((int((0 < fTemp5)))?0:((int((fTemp5 < 99)))?(fTemp4 - fTemp5):99));
		fRec6[0] = ((0.993 * fRec6[1]) + fSlow1);
		output0[i] = (FAUSTFLOAT)((fRec6[0] * fabs(((ftbl0[int(fTemp5)] * (1 - fTemp6)) + (fTemp6 * ftbl0[int((1 + fTemp5))])))) * ((int(((fTemp3 * ((int((fTemp2 < 0)))?1:-1)) < 0)))?-1:1));
		// post processing
		fRec6[1] = fRec6[0];
		fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
		fRec2[1] = fRec2[0];
		fVec1[1] = fVec1[0];
		fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
		fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
		fRec5[1] = fRec5[0];
		fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		fVec0[1] = fVec0[0];
	}
#undef fslider0
#undef fslider1
}
	
	
	double 	Dsp::SIG0::fWave0[100] = {
	0.00548195523036,0.016445865691,0.0274097761516,0.0383736866119,0.0493375970718,
	0.060301507531,0.0712654179894,0.0822293284464,0.0931932389016,0.104157149354,
	0.115121059803,0.126084970245,0.13704888068,0.148012791103,0.158976701508,
	0.169940611889,0.180904522235,0.19186843253,0.202832342751,0.213796252866,
	0.224760162828,0.23572407257,0.246687981995,0.257651890962,0.26861579927,
	0.279579706628,0.290543612617,0.301507516632,0.312471417804,0.323435314878,
	0.334399206045,0.3453630887,0.356326959087,0.367290811794,0.378254639021,
	0.389218429528,0.400182167115,0.411145828437,0.422109379849,0.433072772871,
	0.444035937638,0.454998773485,0.465961135365,0.476922814321,0.48788350936,
	0.498842787024,0.509800023297,0.520754320256,0.531704386732,0.542648367922,
	0.55358360312,0.564506283341,0.575410971703,0.586289940184,0.597132269761,
	0.607922663898,0.618639951041,0.629255322196,0.639730493837,0.650016225239,
	0.660051925492,0.669767316942,0.679086989359,0.687937882416,0.696258343947,
	0.704006183628,0.711163121782,0.717734492237,0.723745022743,0.72923269117,
	0.734242606851,0.738822090117,0.743017303269,0.74687127245,0.750422944114,
	0.7537069184,0.756753578753,0.759589425229,0.762237491115,0.764717773458,
	0.767047640962,0.769242202516,0.771314630963,0.773276442704,0.775137736666,
	0.776907397287,0.778593266396,0.780202288563,0.781740634041,0.783213802858,
	0.784626713121,0.785983776084,0.787288960129,0.788545845459,0.789757670968,
	0.790927374556,0.792057627879,0.793150866414,0.794209315546,0.795235013262
	};

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	// static const value_pair fslider0_values[] = {{"OFF"},{"ON"},{0}};
	case FILTER: 
		fslider0_ = (float*)data; // , 0.0, 0.0, 1.0, 1.0 
		break;
	case VOLUME: 
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
   FILTER, 
   VOLUME, 
} PortIndex;
*/

} // end namespace osmu
