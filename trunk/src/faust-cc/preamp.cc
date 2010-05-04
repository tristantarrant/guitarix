namespace preamp {
// generated from file '../src/faust/preamp.dsp'

float 	fVec0[3];
FAUSTFLOAT 	fslider0;
float 	fVec1[3];
int	fSamplingFreq;

void init(int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	for (int i=0; i<3; i++) fVec0[i] = 0;
	for (int i=0; i<3; i++) fVec1[i] = 0;
}

void compute(int count, float *input0, float *output0)
{
	float 	fSlow0 = fslider0;
	float 	fSlow1 = (0.75f / atanf(fSlow0));
	for (int i=0; i<count; i++) {
		float fTemp0 = (float)input0[i];
		fVec0[0] = fTemp0;
		float fTemp1 = (fVec0[2] + (fVec0[0] + fVec0[1]));
		float fTemp2 = faustpower<2>(fTemp1);
		float fTemp3 = ((0.3333333333333333f - (0.016666666666666663f * fTemp1)) - (0.005555555555555554f * fTemp2));
		float fTemp4 = (fSlow1 * atanf((fSlow0 * ((fTemp1 * fTemp3) * (1.5f - (0.5f * (fTemp2 * faustpower<2>(fTemp3))))))));
		fVec1[0] = fTemp4;
		output0[i] = (FAUSTFLOAT)(0.3333333333333333f * (fVec1[2] + (fVec1[0] + fVec1[1])));
		// post processing
		fVec1[2] = fVec1[1]; fVec1[1] = fVec1[0];
		fVec0[2] = fVec0[1]; fVec0[1] = fVec0[0];
	}
}

static struct RegisterParams { RegisterParams(); } RegisterParams;
RegisterParams::RegisterParams()
{
	registerVar("preamp.atan","drive","S","Input level for pre-amp (higher level gives more distortion)",&fslider0, 1.0f, 1.0f, 1e+01f, 1.0f);
	registerInit(init);
}

} // end namespace preamp
