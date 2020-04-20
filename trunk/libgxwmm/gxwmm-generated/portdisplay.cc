// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gxwmm/portdisplay.h>
#include <gxwmm/private/portdisplay_p.h>


/*
 * Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
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
 */

#include <gxw/GxPortDisplay.h>

Gxw::PortDisplay::PortDisplay(const Glib::RefPtr<Gtk::Adjustment>& adjustment):
	// Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gxw::VSlider(Glib::ConstructParams(portdisplay_class_.init(), "adjustment",adjustment->gobj(), nullptr))
{}

namespace
{
} // anonymous namespace


namespace Glib
{

Gxw::PortDisplay* wrap(GxPortDisplay* object, bool take_copy)
{
  return dynamic_cast<Gxw::PortDisplay *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gxw
{


/* The *_Class implementation: */

const Glib::Class& PortDisplay_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &PortDisplay_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gx_port_display_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void PortDisplay_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* PortDisplay_Class::wrap_new(GObject* o)
{
  return manage(new PortDisplay((GxPortDisplay*)(o)));

}


/* The implementation: */

PortDisplay::PortDisplay(const Glib::ConstructParams& construct_params)
:
  Gxw::VSlider(construct_params)
{
  }

PortDisplay::PortDisplay(GxPortDisplay* castitem)
:
  Gxw::VSlider((GxVSlider*)(castitem))
{
  }


PortDisplay::PortDisplay(PortDisplay&& src) noexcept
: Gxw::VSlider(std::move(src))
{}

PortDisplay& PortDisplay::operator=(PortDisplay&& src) noexcept
{
  Gxw::VSlider::operator=(std::move(src));
  return *this;
}

PortDisplay::~PortDisplay() noexcept
{
  destroy_();
}

PortDisplay::CppClassType PortDisplay::portdisplay_class_; // initialize static member

GType PortDisplay::get_type()
{
  return portdisplay_class_.init().get_type();
}


GType PortDisplay::get_base_type()
{
  return gx_port_display_get_type();
}


void PortDisplay::set_state(int cutoff_low, int cutoff_high)
{
  gx_port_display_set_state(gobj(), cutoff_low, cutoff_high);
}

void PortDisplay::set_cutoff_low(int cutoff_low)
{
  gx_port_display_set_cutoff_low(gobj(), cutoff_low);
}

void PortDisplay::set_cutoff_high(int cutoff_high)
{
  gx_port_display_set_cutoff_high(gobj(), cutoff_high);
}

PortDisplay::PortDisplay()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gxw::VSlider(Glib::ConstructParams(portdisplay_class_.init()))
{
  

}


} // namespace Gxw


