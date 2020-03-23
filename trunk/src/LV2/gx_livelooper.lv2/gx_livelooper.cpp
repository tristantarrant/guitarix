/*
 * Copyright (C) 2014 Guitarix project MOD project
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


#include <sndfile.hh>
#include <glibmm.h>
#include <sys/stat.h>
#include <time.h>
////////////////////////////// LOCAL INCLUDES //////////////////////////

#include "gx_common.h"      // faust support and denormal protection (SSE)
#include "gx_livelooper.h"        // define struct PortIndex
#include "livelooper.cc"    // dsp class generated by faust -> dsp2cc

////////////////////////////// PLUG-IN CLASS ///////////////////////////

namespace livelooper {

class Gx_livelooper_
{
private:
  LV2_URID_Map* map;
  LV2_URID atom_string;
  LV2_URID file_name;
  // pointer to buffer
  float*      output;
  float*      input;
  // pointer to dsp class
  LiveLooper*  livelooper;
  // private functions
  inline void run_dsp_(uint32_t n_samples);
  inline void connect_(uint32_t port,void* data);
  inline void init_dsp_(uint32_t rate);
  inline void connect_all__ports(uint32_t port, void* data);
  inline void activate_f();
  inline void clean_up();
  inline void deactivate_f();

public:
  char uniq_name[24];
  // LV2 Descriptor
  static const LV2_Descriptor descriptor;
  // static wrapper to private functions
  static void deactivate(LV2_Handle instance);
  static void cleanup(LV2_Handle instance);
  static void run(LV2_Handle instance, uint32_t n_samples);
  static void activate(LV2_Handle instance);
  static void connect_port(LV2_Handle instance, uint32_t port, void* data);
  static LV2_Handle instantiate(const LV2_Descriptor* descriptor,
                                double rate, const char* bundle_path,
                                const LV2_Feature* const* features);
  static LV2_State_Status lsave(LV2_Handle instance,
                                LV2_State_Store_Function   store,
                                LV2_State_Handle           handle,
                                uint32_t                   flags,
                                const LV2_Feature *const * features);

  static LV2_State_Status lrestore(LV2_Handle instance,
                            LV2_State_Retrieve_Function retrieve,
                            LV2_State_Handle            handle,
                            uint32_t                    flags,
                            const LV2_Feature *const *  features);
  static const void* extension_data(const char* uri);
  Gx_livelooper_();
  ~Gx_livelooper_();
};

// constructor
Gx_livelooper_::Gx_livelooper_() :
  output(NULL),
  input(NULL),
  livelooper(livelooper::plugin()) {};

// destructor
Gx_livelooper_::~Gx_livelooper_()
{
  // just to be sure the plug have given free the allocated mem
  // it didn't hurd if the mem is already given free by clean_up()
  livelooper->activate_static(false, livelooper);
  // delete DSP class
  livelooper->del_instance(livelooper);
};

///////////////////////// PRIVATE CLASS  FUNCTIONS /////////////////////

void Gx_livelooper_::init_dsp_(uint32_t rate)
{
  AVOIDDENORMALS(); // init the SSE denormal protection
  livelooper->init_static(rate, livelooper); // init the DSP class
}

// connect the Ports used by the plug-in class
void Gx_livelooper_::connect_(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {
    case EFFECTS_OUTPUT:
      output = static_cast<float*>(data);
      break;
    case EFFECTS_INPUT:
      input = static_cast<float*>(data);
      break;
    default:
      break;
    }
}

void Gx_livelooper_::activate_f()
{
  // allocate the internal DSP mem
  livelooper->activate_static(true, livelooper);
}

void Gx_livelooper_::clean_up()
{
  // delete the internal DSP mem
  livelooper->activate_static(false, livelooper);
}

void Gx_livelooper_::deactivate_f()
{
  // delete the internal DSP mem
  livelooper->activate_static(false, livelooper);
}

void Gx_livelooper_::run_dsp_(uint32_t n_samples)
{
  if (n_samples< 1) return;
  livelooper->compute_static(static_cast<int>(n_samples), input, output, livelooper);
}

void Gx_livelooper_::connect_all__ports(uint32_t port, void* data)
{
  // connect the Ports used by the plug-in class
  connect_(port,data); 
  // connect the Ports used by the DSP class
  livelooper->connect_static(port,  data, livelooper);
}

////////////////////// STATIC CLASS  FUNCTIONS  ////////////////////////

LV2_Handle 
Gx_livelooper_::instantiate(const LV2_Descriptor* descriptor,
                            double rate, const char* bundle_path,
                            const LV2_Feature* const* features)
{
  // init the plug-in class
  Gx_livelooper_ *self = new Gx_livelooper_();
  if (!self)
    {
      return NULL;
    }
  for (int32_t i = 0; features[i]; ++i)
    {
      if (!strcmp(features[i]->URI, LV2_URID__map))
        {
          self->map = (LV2_URID_Map*)features[i]->data;
        }
    }
  if (!self->map)
    {
      fprintf(stderr, "Missing feature uri:map.\n");
      free(self);
      return NULL;
    }

  self->atom_string = self->map->map(self->map->handle, LV2_ATOM__String);
  self->file_name = self->map->map(self->map->handle, GXPLUGIN_URI "#_livelooper_" "Filename");
  self->init_dsp_((uint32_t)rate);

  return (LV2_Handle)self;
}

void Gx_livelooper_::connect_port(LV2_Handle instance, 
                                   uint32_t port, void* data)
{
  // connect all ports
  static_cast<Gx_livelooper_*>(instance)->connect_all__ports(port, data);
}

void Gx_livelooper_::activate(LV2_Handle instance)
{
  // allocate needed mem
  static_cast<Gx_livelooper_*>(instance)->activate_f();
}

void Gx_livelooper_::run(LV2_Handle instance, uint32_t n_samples)
{
  // run dsp
  static_cast<Gx_livelooper_*>(instance)->run_dsp_(n_samples);
}

void Gx_livelooper_::deactivate(LV2_Handle instance)
{
  // free allocated mem
  static_cast<Gx_livelooper_*>(instance)->deactivate_f();
}

void Gx_livelooper_::cleanup(LV2_Handle instance)
{
  // well, clean up after us
  Gx_livelooper_* self = static_cast<Gx_livelooper_*>(instance);
  self->clean_up();
  delete self;
}

LV2_State_Status Gx_livelooper_::lsave(LV2_Handle instance,
                                LV2_State_Store_Function   store,
                                LV2_State_Handle           handle,
                                uint32_t                   flags,
                                const LV2_Feature *const * features) {
  Gx_livelooper_* self = static_cast<Gx_livelooper_*>(instance);
  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (self->uniq_name,24,"%Y%m%d%H%M%S_",timeinfo);
 
  store(handle,self->file_name, self->uniq_name, strlen(self->uniq_name) + 1,  
                self->atom_string, LV2_STATE_IS_POD | LV2_STATE_IS_PORTABLE);

  self->livelooper->set_preset_state(self->uniq_name, true,self->livelooper);

  return LV2_STATE_SUCCESS;
}

LV2_State_Status Gx_livelooper_::lrestore(LV2_Handle instance,
                            LV2_State_Retrieve_Function retrieve,
                            LV2_State_Handle            handle,
                            uint32_t                    fflags,
                            const LV2_Feature *const *  features) {
  Gx_livelooper_* self = static_cast<Gx_livelooper_*>(instance);

  size_t      size;
  uint32_t    type;
  uint32_t    flags;
  const void* name = retrieve(handle, self->file_name, &size, &type, &flags);

  if (name) {
    fprintf(stderr,"%s\n",(const char*)name);
    self->livelooper->set_preset_state((const char*)name , false, self->livelooper);
  } else {
    fprintf(stderr,"fail to fetch state\n");
  }
  return LV2_STATE_SUCCESS;
}

const void* Gx_livelooper_::extension_data(const char* uri) {
  static const LV2_State_Interface state_iface = { lsave, lrestore };
  if (!strcmp(uri, LV2_STATE__interface)) {
    return &state_iface;
  }
  return NULL;
}

const LV2_Descriptor Gx_livelooper_::descriptor =
{
  GXPLUGIN_URI "#_livelooper_",
  Gx_livelooper_::instantiate,
  Gx_livelooper_::connect_port,
  Gx_livelooper_::activate,
  Gx_livelooper_::run,
  Gx_livelooper_::deactivate,
  Gx_livelooper_::cleanup,
  Gx_livelooper_::extension_data
};


} // end namespace livelooper

////////////////////////// LV2 SYMBOL EXPORT ///////////////////////////

extern "C"
LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
  switch (index)
    {
    case 0:
      return &livelooper::Gx_livelooper_::descriptor;
    default:
      return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
