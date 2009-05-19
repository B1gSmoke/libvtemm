/* simple.h
 *
 * Copyright (C) 2008, 2009 libvtemm Development Team
 *
 * This file is part of Terminal Example.
 *
 * Terminal Example is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Terminal Example is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Terminal Example.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _LIBVTEMM_EXAMPLE_SIMPLE_H_
#define _LIBVTEMM_EXAMPLE_SIMPLE_H_

#include <gtkmm.h>
#include <libvtemm/terminal.h>

class Simple : public Gtk::Window
{
public:
  Simple();
  virtual ~Simple();
protected:
  //Signal handlers:
  virtual void on_child_exited();
private:
  //Member widgets:
  Gtk::HBox m_box;
  Gnome::Vte::Terminal m_terminal;
  Gtk::VScrollbar m_scrollbar;
};

#endif // _LIBVTEMM_EXAMPLE_SIMPLE_H_
