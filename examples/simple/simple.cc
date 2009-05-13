/* simple.cc
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

#include <vector>
#include <string>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#include "simple.h"

static
std::string get_shell();

Simple::Simple()
:
  m_terminal()
{
  /*
  we are making a NULL terminated string vector. as we are passing neither
  argv nor envv, the string vector contains one empty string only.
  */
  std::vector<std::string> nil(1, std::string());
  std::string command(get_shell());
  set_title("Simple Gnome::Vte::Terminal example");
  m_terminal.fork_command(command, nil, nil, std::string(), false, false, false);
  m_terminal.set_size(80, 24);
  m_terminal.signal_child_exited().connect(sigc::mem_fun(*this, &Simple::on_child_exited));
  add(m_terminal);
  m_terminal.set_flags(Gtk::CAN_DEFAULT);
  m_terminal.grab_default();
  Gdk::Geometry hints;
  hints.base_width = hints.min_width = hints.width_inc = m_terminal.get_char_width();
  hints.base_height = hints.min_height = hints.height_inc = m_terminal.get_char_height();
  set_geometry_hints(m_terminal, hints, Gdk::HINT_RESIZE_INC | Gdk::HINT_MIN_SIZE | Gdk::HINT_BASE_SIZE);
  show_all_children();
}

Simple::~Simple()
{}

void Simple::on_child_exited()
{
  hide();
}

// static

static
std::string get_shell()
{
  uid_t uid(getuid());
  passwd* pwd(getpwuid(uid));
  return pwd->pw_shell;
}
