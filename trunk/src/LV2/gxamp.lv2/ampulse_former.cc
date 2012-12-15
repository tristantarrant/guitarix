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


Ampf::Ampf()
{
}

Ampf::~Ampf()
{
}

inline void Ampf::init(unsigned int samplingFreq)
{
  fSamplingFreq = samplingFreq;
  fslider0 = 1.;
}

inline void Ampf::compute(int count, float *input0, float *output0)
{
  fslider0 = (*fslider0_);
  double 	fSlow0 = fslider0;
  double 	fSlow1 = (fSlow0 * pow(10,(0 - (0.1 * fSlow0))));
  for (int i=0; i<count; i++)
    {
      output0[i] = (FAUSTFLOAT)(fSlow1 * (double)input0[i]);
    }
}

void Ampf::connect(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {
    case AMP_MASTERGAIN:
      break;
    case AMP_PREGAIN:
      break;
    case AMP_WET_DRY:
      break;
    case AMP_DRIVE:
      break;
    case MID:
      break;
    case BASS:
      break;
    case TREBLE:
      break;
    case CLevel:
      break;
    case ALevel:
      fslider0_ = (float*)data;
      break;
    case AMP_OUTPUT:
      break;
    case AMP_INPUT:
      break;
    case AMP_CONTROL:
      break;
    case AMP_NOTIFY:
      break;
    }
}

void Ampf::connect_static(uint32_t port,void* data, Ampf *p)
{
  static_cast<Ampf*>(p)->connect(port, data);
}

void Ampf::init_static(unsigned int samplingFreq, Ampf *p)
{
  static_cast<Ampf*>(p)->init(samplingFreq);
}
