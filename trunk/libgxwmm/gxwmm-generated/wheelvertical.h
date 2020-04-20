// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!
#ifndef _GXWMM_WHEELVERTICAL_H
#define _GXWMM_WHEELVERTICAL_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

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

#include <gxwmm/regler.h>
#include <gtkmm/adjustment.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GxWheelVertical = struct _GxWheelVertical;
using GxWheelVerticalClass = struct _GxWheelVerticalClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gxw
{ class WheelVertical_Class; } // namespace Gxw
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gxw {


class WheelVertical: public Gxw::Regler {
	public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef WheelVertical CppObjectType;
  typedef WheelVertical_Class CppClassType;
  typedef GxWheelVertical BaseObjectType;
  typedef GxWheelVerticalClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  WheelVertical(WheelVertical&& src) noexcept;
  WheelVertical& operator=(WheelVertical&& src) noexcept;

  // noncopyable
  WheelVertical(const WheelVertical&) = delete;
  WheelVertical& operator=(const WheelVertical&) = delete;

  ~WheelVertical() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class WheelVertical_Class;
  static CppClassType wheelvertical_class_;

protected:
  explicit WheelVertical(const Glib::ConstructParams& construct_params);
  explicit WheelVertical(GxWheelVertical* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  GxWheelVertical*       gobj()       { return reinterpret_cast<GxWheelVertical*>(gobject_); }

  /// Provides access to the underlying C GObject.
  const GxWheelVertical* gobj() const { return reinterpret_cast<GxWheelVertical*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

	public:
	WheelVertical();
	explicit WheelVertical(const Glib::RefPtr<Gtk::Adjustment>& adjustment);


};

} // namespace Gxw


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gxw::WheelVertical
   */
  Gxw::WheelVertical* wrap(GxWheelVertical* object, bool take_copy = false);
} //namespace Glib


#endif /* _GXWMM_WHEELVERTICAL_H */

