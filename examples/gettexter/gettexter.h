/* gettexter.h
 *
 * Copyright (C) 2008, 2009 libvtemm Development Team
 *
 * This file is part of GetTexter Example.
 *
 * GetTexter Example is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GetTexter Example is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GetTexter Example.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _LIBVTEMM_EXAMPLE_GETTEXTER_H_
#define _LIBVTEMM_EXAMPLE_GETTEXTER_H_

#include <gtkmm.h>

#include "gtterminal.h"

class GetTexter : public Gtk::Window
{
public:
  GetTexter();
  virtual ~GetTexter();
protected:
  // Signal handlers:
  virtual void on_get_every_second_button_clicked();
  virtual void on_get_only_a_button_clicked();
  virtual void on_entry_activated();
private:
  // Member widgets:
  Gtk::VBox m_main_box;
  Gtk::HBox m_term_box;
  GtTerminal m_terminal;
  Gtk::VScrollbar m_scrollbar;
  Gtk::Label m_label;
  Gtk::Entry m_entry;
  Gtk::HButtonBox m_button_box;
  Gtk::Button m_get_every_second_button;
  Gtk::Button m_get_only_a_button;
};

#endif // _LIBVTEMM_EXAMPLE_GETTEXTER_H_
