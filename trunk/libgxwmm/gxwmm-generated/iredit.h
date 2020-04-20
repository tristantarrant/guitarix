// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!
#ifndef _GXWMM_IREDIT_H
#define _GXWMM_IREDIT_H


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

#include <gtkmm/drawingarea.h>
#include <gxwmm/gainline.h>
#include <vector>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GxIREdit = struct _GxIREdit;
using GxIREditClass = struct _GxIREditClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gxw
{ class IREdit_Class; } // namespace Gxw
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gxw {


class IREdit: public Gtk::DrawingArea {
	public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef IREdit CppObjectType;
  typedef IREdit_Class CppClassType;
  typedef GxIREdit BaseObjectType;
  typedef GxIREditClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  IREdit(IREdit&& src) noexcept;
  IREdit& operator=(IREdit&& src) noexcept;

  // noncopyable
  IREdit(const IREdit&) = delete;
  IREdit& operator=(const IREdit&) = delete;

  ~IREdit() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class IREdit_Class;
  static CppClassType iredit_class_;

protected:
  explicit IREdit(const Glib::ConstructParams& construct_params);
  explicit IREdit(GxIREdit* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  GxIREdit*       gobj()       { return reinterpret_cast<GxIREdit*>(gobject_); }

  /// Provides access to the underlying C GObject.
  const GxIREdit* gobj() const { return reinterpret_cast<GxIREdit*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

	public:
	void set_state(float *data, int chan, int data_len, int samplerate, int cutoff_low, int cutoff_high, int offset, const Gainline& gain);
	Gainline get_gain();
	void set_gain(const Gainline& gain);

	IREdit();
	
  void set_ir_data(float* p1, int p2, int p3, int p4);
	
  void home();
	
  void jump_zoom_mark();
	
  void set_channel(int p1);
	
  void incr_scale(double p1);
	
  void decr_scale(double p1);
	
  void set_log(bool p1);
	
  int get_delay();
	
  void set_delay(int p1);
	
  int get_offset();
	
  void set_offset(int p1);
	
  int get_length();
	
  void set_length(int p1);
	
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%delay_changed(int p1, int p2)</tt>
   *
   * Flags: Run First, No Recurse
   *
   */

  Glib::SignalProxy< void,int,int > signal_delay_changed();

	
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%offset_changed(int p1, int p2)</tt>
   *
   * Flags: Run First, No Recurse
   *
   */

  Glib::SignalProxy< void,int,int > signal_offset_changed();

	
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%length_changed(int p1, int p2)</tt>
   *
   * Flags: Run First, No Recurse
   *
   */

  Glib::SignalProxy< void,int,int > signal_length_changed();

	
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%scale_max_reached(bool p1)</tt>
   *
   * Flags: Run Last
   *
   */

  Glib::SignalProxy< void,bool > signal_scale_max_reached();

	
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%scale_min_reached(bool p1)</tt>
   *
   * Flags: Run Last
   *
   */

  Glib::SignalProxy< void,bool > signal_scale_min_reached();

	/** area above x axis at the top of the window.
   *
   * Default value: 5
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< int > property_y_border_top() ;

/** area above x axis at the top of the window.
   *
   * Default value: 5
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_y_border_top() const;

	/** Default value: 10
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< int > property_y_border_bottom() ;

/** Default value: 10
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_y_border_bottom() const;

	/** Default value: 5
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< int > property_x_border() ;

/** Default value: 5
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_x_border() const;

	/** Default value: 4
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< int > property_label_sep() ;

/** Default value: 4
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_label_sep() const;

	/** Default value: 5
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< double > property_dot_diameter() ;

/** Default value: 5
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< double > property_dot_diameter() const;

	/** Default value: 2
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< double > property_segment_distance() ;

/** Default value: 2
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< double > property_segment_distance() const;

	/** Default value: 5
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< double > property_limit() ;

/** Default value: 5
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< double > property_limit() const;

	/** Default value: 4
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_fs() const;


	/** Default value: 50
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< double > property_max_scale_fact() ;

/** Default value: 50
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< double > property_max_scale_fact() const;

	/** Default value: 0.02
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< double > property_min_scale() ;

/** Default value: 0.02
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< double > property_min_scale() const;

	/** Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< double > property_scale() ;

/** Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< double > property_scale() const;

	/** text displayed when no data is available.
   *
   * Default value: "NO DATA"
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Glib::ustring > property_no_data_text() ;

/** text displayed when no data is available.
   *
   * Default value: "NO DATA"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::ustring > property_no_data_text() const;


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
   * @relates Gxw::IREdit
   */
  Gxw::IREdit* wrap(GxIREdit* object, bool take_copy = false);
} //namespace Glib


#endif /* _GXWMM_IREDIT_H */

