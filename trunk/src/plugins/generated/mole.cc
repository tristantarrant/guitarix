// generated from file '../src/plugins/mole.dsp' by dsp2cc:
// Code generated with Faust 0.9.65 (http://faust.grame.fr)

#include "gx_faust_support.h"
#include "gx_plugin.h"

namespace pluginlib {
namespace mole {

class Dsp: public PluginDef {
private:
	int fSamplingFreq;
	FAUSTFLOAT 	fslider0;
	double 	fRec0[2];
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	FAUSTFLOAT 	fslider1;
	double 	fRec1[4];
	double 	fConst8;
	void clear_state_f();
	int load_ui_f(const UiBuilder& b, int form);
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
	id = "mole";
	name = N_("The Mole");
	groups = 0;
	description = N_("EHX Mole"); // description (tooltip)
	category = N_("Tone control");       // category
	shortname = N_("The Mole");     // shortname
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
	for (int i=0; i<4; i++) fRec1[i] = 0;
}

void Dsp::clear_state_f_static(PluginDef *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(unsigned int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = double(min(192000, max(1, fSamplingFreq)));
	fConst1 = (8.93878454194095e-15 * fConst0);
	fConst2 = (2.70404912477885e-11 + (fConst0 * ((fConst0 * (4.96556855945694e-12 - fConst1)) - 2.64572840995574e-11)));
	fConst3 = (2.68163536258229e-14 * fConst0);
	fConst4 = (8.11214737433656e-11 + (fConst0 * ((fConst0 * (fConst3 - 4.96556855945694e-12)) - 2.64572840995574e-11)));
	fConst5 = (8.11214737433656e-11 + (fConst0 * (2.64572840995574e-11 + (fConst0 * (0 - (4.96556855945694e-12 + fConst3))))));
	fConst6 = (2.70404912477885e-11 + (fConst0 * (2.64572840995574e-11 + (fConst0 * (4.96556855945694e-12 + fConst1)))));
	fConst7 = (1.0 / fConst6);
	fConst8 = (faustpower<2>(fConst0) / fConst6);
	clear_state_f();
}

void Dsp::init_static(unsigned int samplingFreq, PluginDef *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
	double 	fSlow0 = (0.007000000000000006 * double(fslider0));
	double 	fSlow1 = (0.01 * double(fslider1));
	double 	fSlow2 = (1 - fSlow1);
	for (int i=0; i<count; i++) {
		fRec0[0] = ((0.993 * fRec0[1]) + fSlow0);
		double fTemp0 = (0 - (9.74268345040146e-11 * fRec0[0]));
		double fTemp1 = (double)input0[i];
		fRec1[0] = ((fSlow1 * fTemp1) - (fConst7 * (((fConst5 * fRec1[1]) + (fConst4 * fRec1[2])) + (fConst2 * fRec1[3]))));
		output0[i] = (FAUSTFLOAT)((fSlow2 * fTemp1) + (fConst8 * ((((fRec1[0] * fTemp0) + (9.74268345040146e-11 * (fRec0[0] * fRec1[1]))) + (9.74268345040146e-11 * (fRec0[0] * fRec1[2]))) + (fRec1[3] * fTemp0))));
		// post processing
		for (int i=3; i>0; i--) fRec1[i] = fRec1[i-1];
		fRec0[1] = fRec0[0];
	}
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}

int Dsp::register_par(const ParamReg& reg)
{
	reg.registerVar("mole.Boost",N_("Boost"),"S","",&fslider0, 0.5, 0.0, 1.0, 0.01);
	reg.registerVar("mole.wet_dry",N_("wet/dry"),"S",N_("percentage of processed signal in output signal"),&fslider1, 1e+02, 0.0, 1e+02, 1.0);
	return 0;
}

int Dsp::register_params_static(const ParamReg& reg)
{
	return static_cast<Dsp*>(reg.plugin)->register_par(reg);
}

inline int Dsp::load_ui_f(const UiBuilder& b, int form)
{
    if (form & UI_FORM_STACK) {
#define PARAM(p) ("mole" "." p)

b.openHorizontalhideBox("");
    b.create_master_slider(PARAM("Boost"), "Boost");
b.closeBox();
b.openHorizontalBox("");

    b.create_small_rackknobr(PARAM("Boost"), "Boost");
    b.create_small_rackknobr(PARAM("wet_dry"), "dry/wet");
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

} // end namespace mole
} // end namespace pluginlib