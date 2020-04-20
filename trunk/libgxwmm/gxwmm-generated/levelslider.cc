// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gxwmm/levelslider.h>
#include <gxwmm/private/levelslider_p.h>


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

#include <gxw/GxLevelSlider.h>

Gxw::LevelSlider::LevelSlider(const Glib::RefPtr<Gtk::Adjustment>& adjustment):
	// Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gxw::VSlider(Glib::ConstructParams(levelslider_class_.init(), "adjustment",adjustment->gobj(), nullptr))
{}

namespace
{
} // anonymous namespace


namespace Glib
{

Gxw::LevelSlider* wrap(GxLevelSlider* object, bool take_copy)
{
  return dynamic_cast<Gxw::LevelSlider *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gxw
{


/* The *_Class implementation: */

const Glib::Class& LevelSlider_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &LevelSlider_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gx_level_slider_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void LevelSlider_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* LevelSlider_Class::wrap_new(GObject* o)
{
  return manage(new LevelSlider((GxLevelSlider*)(o)));

}


/* The implementation: */

LevelSlider::LevelSlider(const Glib::ConstructParams& construct_params)
:
  Gxw::VSlider(construct_params)
{
  }

LevelSlider::LevelSlider(GxLevelSlider* castitem)
:
  Gxw::VSlider((GxVSlider*)(castitem))
{
  }


LevelSlider::LevelSlider(LevelSlider&& src) noexcept
: Gxw::VSlider(std::move(src))
{}

LevelSlider& LevelSlider::operator=(LevelSlider&& src) noexcept
{
  Gxw::VSlider::operator=(std::move(src));
  return *this;
}

LevelSlider::~LevelSlider() noexcept
{
  destroy_();
}

LevelSlider::CppClassType LevelSlider::levelslider_class_; // initialize static member

GType LevelSlider::get_type()
{
  return levelslider_class_.init().get_type();
}


GType LevelSlider::get_base_type()
{
  return gx_level_slider_get_type();
}


LevelSlider::LevelSlider()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gxw::VSlider(Glib::ConstructParams(levelslider_class_.init()))
{
  

}


} // namespace Gxw


