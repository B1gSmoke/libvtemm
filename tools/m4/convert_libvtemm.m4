_EQUAL(glong,long)
_EQUAL(pid_t, Glib::Pid)
_EQUAL(Glib::Pid, GPid)

_CONV_ENUM(Vte,TerminalEraseBinding)
_CONV_ENUM(Vte,TerminalAntiAlias)
_CONV_ENUM(Vte,TerminalCursorBlinkMode)
_CONV_ENUM(Vte,TerminalCursorShape)
## eh?
## _CONV_ENUM(Gdk,CursorType)

## reminder on __Fx2y
## __FR2P = (x).gobj()
## __GCHARP_TO_USTRING = Glib::convert_const_gchar_ptr_to_ustring(x)
## __CFR2P = const_cast<y>(x.gobj())


#glib
##_CONVERSION(`pid_t', `Glib::Pid', `($3)')
##_CONVERSION(`Glib::Pid', `GPid', `($3)')
##_CONVERSION(`const Glib::ustring&',`const char*',`($3).c_str()')
##_CONVERSION(`const char*',`Glib::ustring',__GCHARP_TO_USTRING)
##_CONVERSION(`const std::string&', `const char*', `($3).c_str()')
_CONVERSION(`Glib::RefPtr<Glib::Regex>', `GRegex*', __CONVERT_REFPTR_TO_P)

#pango
_CONVERSION(`const PangoFontDescription*',`Pango::FontDescription',`Pango::FontDescription(const_cast<PangoFontDescription*>($3))')
_CONVERSION(`const Pango::FontDescription&',`const PangoFontDescription*',__FR2P)

#gdk
_CONVERSION(`const Gdk::Color&',`const GdkColor*',__FR2P) ## this should be commented
_CONVERSION(`Gdk::Cursor&',`GdkCursor*',__FR2P)

#gtk
_CONVERSION(`Gtk::MenuShell&', `GtkMenuShell*',__FR2P)
_CONVERSION(`GtkAdjustment*',`Gtk::Adjustment&',`*(Glib::wrap($3))')

#vte
_CONVERSION(`const Terminal&',`VteTerminal*', __CFR2P)
_CONVERSION(`const StdStringArrayHandle&', `char**', `const_cast<char**>(($3).data())')
##_CONVERSION(`guint',`bool',`($3)')
##_CONVERSION(`VteReaper*',`const Glib::RefPtr<Reaper>',`Glib::wrap($3)')
