/*
 * Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
 * Copyright (C) 2011 Pete Shorthose
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

/* ------- This is the GUI namespace ------- */

#pragma once

#ifndef SRC_HEADERS_GX_UI_BUILDER_H_
#define SRC_HEADERS_GX_UI_BUILDER_H_

namespace gx_gui {

/****************************************************************
 ** class GxBuilder
 **
 ** Attempts to correct the mismatch between GtkBuilder and
 ** Gtk::Builder wrt. reference counting.
 **
 ** Use get_toplevel or get_toplevel_derived to become the owner of a
 ** toplevel widget of the loaded builder widget tree (specifying
 ** object id's for the loader means that only part of the defined
 ** widget tree is loaded). These pointers must be delete'd to destroy
 ** the widget (and its child widgets). If you loaded a window
 ** (GtkWindow or derived) you must use one of the get_toplevel
 ** functions and delete the instance to avoid a memory leak.
 **
 ** Use find_widget for getting a pointer to a widget (but you don't
 ** become owner of that widget, don't use delete). If you want to add
 ** the loaded widget tree to a container, use this function (the
 ** container will ref the widget and manage its lifetime).
 **
 ** template function code mostly copied from Gtk::Builder, look
 ** there for comments.
 */

class GxBuilder: public Gtk::Builder {
private:
    // only implemented for base class, make inaccessable
    static Glib::RefPtr<GxBuilder> create_from_file(const std::string& filename, const char* object_id);
    static Glib::RefPtr<GxBuilder> create_from_file(const std::string& filename, const Glib::ustring& object_id);
    static Glib::RefPtr<GxBuilder> create_from_file(const std::string& filename, const Glib::StringArrayHandle& object_ids);
    static Glib::RefPtr<GxBuilder> create_from_string(const Glib::ustring& buffer, const char* object_id);
    static Glib::RefPtr<GxBuilder> create_from_string(const Glib::ustring& buffer, const Glib::ustring& object_id);
    static Glib::RefPtr<GxBuilder> create_from_string(const Glib::ustring& buffer, const Glib::StringArrayHandle& object_ids);
protected:
    Gtk::Widget* get_widget_checked(const Glib::ustring& name, GType type, bool take_ref);
public:
    static inline Glib::RefPtr<GxBuilder> create() { return Glib::RefPtr<GxBuilder>(new GxBuilder()); }

    static Glib::RefPtr<GxBuilder> create_from_file(
	const std::string& filename, gx_ui::GxUI* ui = 0, const char* object_id = 0);

    static Glib::RefPtr<GxBuilder> create_from_file(
	const std::string& filename, gx_ui::GxUI* ui, const Glib::StringArrayHandle& object_ids);

    static Glib::RefPtr<GxBuilder> create_from_string(
	const Glib::ustring& buffer, gx_ui::GxUI* ui = 0, const char* object_id = 0);

    static Glib::RefPtr<GxBuilder> create_from_string(
	const Glib::ustring& buffer, gx_ui::GxUI* ui, const Glib::StringArrayHandle& object_ids);

    void fixup_controlparameters(gx_ui::GxUI& ui);

    template <class T_Widget> inline
    void find_widget(const Glib::ustring& name, T_Widget*& widget) {
	widget = 0;
	widget = dynamic_cast<T_Widget*>(this->get_widget_checked(name, T_Widget::get_base_type(), false));
	assert(widget);
    }

    template <class T_Widget> inline
    void get_toplevel(const Glib::ustring& name, T_Widget*& widget) {
	widget = 0;
	GType type = T_Widget::get_base_type();
	widget = dynamic_cast<T_Widget*>(this->get_widget_checked(name, type, !g_type_is_a(type, GTK_TYPE_WINDOW)));
	assert(widget);
	assert(!widget->get_parent());
    }

    Gtk::Window *get_first_window();

    template <class T_Widget, class F> inline
    void get_toplevel_derived(const Glib::ustring& name, T_Widget*& widget, F f) {
	widget = 0;
	typedef typename T_Widget::BaseObjectType cwidget_type;
	cwidget_type* pCWidget = (cwidget_type*)get_cwidget(name);
	if(!pCWidget) {
	    return;
	}
	if (!g_type_is_a(G_OBJECT_TYPE(pCWidget), GTK_TYPE_WINDOW)) {
	    g_object_ref(pCWidget);
	}
	Glib::ObjectBase* pObjectBase = ObjectBase::_get_current_wrapper((GObject*)pCWidget);
	if (pObjectBase) {
	    widget = dynamic_cast<T_Widget*>( Glib::wrap((GtkWidget*)pCWidget) );
	    if (!widget) {
		g_critical("GxBuilder::get_widget_derived(): dynamic_cast<> failed. An existing C++ instance, of a different type, seems to exist.");      
	    }
	} else {
	    widget = f(pCWidget);
	}
	assert(!widget->get_parent());
    }
};
} /* end of gx_gui namespace */
#endif  // SRC_HEADERS_GX_UI_BUILDER_H_
