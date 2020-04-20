// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!
#ifndef _GXWMM_SELECTOR_H
#define _GXWMM_SELECTOR_H


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
#include <gtkmm/treemodel.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GxSelector = struct _GxSelector;
using GxSelectorClass = struct _GxSelectorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gxw
{ class Selector_Class; } // namespace Gxw
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gxw {


class Selector: public Gxw::Regler {
	public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Selector CppObjectType;
  typedef Selector_Class CppClassType;
  typedef GxSelector BaseObjectType;
  typedef GxSelectorClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Selector(Selector&& src) noexcept;
  Selector& operator=(Selector&& src) noexcept;

  // noncopyable
  Selector(const Selector&) = delete;
  Selector& operator=(const Selector&) = delete;

  ~Selector() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class Selector_Class;
  static CppClassType selector_class_;

protected:
  explicit Selector(const Glib::ConstructParams& construct_params);
  explicit Selector(GxSelector* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  GxSelector*       gobj()       { return reinterpret_cast<GxSelector*>(gobject_); }

  /// Provides access to the underlying C GObject.
  const GxSelector* gobj() const { return reinterpret_cast<GxSelector*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

	public:
	Selector();
	
  void set_model(Glib::RefPtr<Gtk::TreeModel> p1);;
	
  Glib::RefPtr<Gtk::TreeModel> get_model();;
	/** The model for the selector.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Gtk::TreeModel > property_model() ;

/** The model for the selector.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Gtk::TreeModel > property_model() const;


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
   * @relates Gxw::Selector
   */
  Gxw::Selector* wrap(GxSelector* object, bool take_copy = false);
} //namespace Glib


#endif /* _GXWMM_SELECTOR_H */

