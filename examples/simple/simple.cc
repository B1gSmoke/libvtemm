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

#include "simple.h"

Simple::Simple()
:
  m_box(),
  m_terminal(),
  m_scrollbar(m_terminal.get_adjustment())
{
  // first put everything into their proper places, then set them up.
  // add terminal to box.
  m_box.pack_start(m_terminal);
  // add scrollbar to box.
  m_box.pack_start(m_scrollbar);
  // put box into window.
  add(m_box);
  // set up a terminal.
  m_terminal.fork_command();
  m_terminal.set_size(80, 24);
  m_terminal.signal_child_exited().connect(sigc::mem_fun(*this, &Simple::on_child_exited));
  m_terminal.set_flags(Gtk::CAN_FOCUS);
  m_terminal.grab_focus();
  // Set geometry hints, so resizing will work nicely.
  // setting geometry hints is based on gnome-terminal code.
  Gdk::Geometry hints;
//  deprecated:
//  Gnome::Vte::Padding pads(m_terminal.get_padding());
//  hints.base_width = pads.get_x_pad();
//  hints.base_height = pads.get_y_pad();

//  C++ API does not work - wait for #603926 to be fixed.
//  Gtk::Border inner_border;
//  m_terminal.get_style_property("inner-border", inner_border);
//  hints.base_width = inner_border.left + inner_border.right;
//  hints.base_height = inner_border.top + inner_border.bottom;

//  C API does work
  GtkBorder* inner_border = NULL;
  gtk_widget_style_get(GTK_WIDGET(m_terminal.gobj()), "inner-border", &inner_border, NULL);
  if (inner_border)
  {
    hints.base_width = inner_border->left + inner_border->right;
    hints.base_height = inner_border->top + inner_border->bottom;
    gtk_border_free(inner_border);
  }
  else
  {
    hints.base_width = 2;
    hints.base_height = 2;
  }
  hints.width_inc = m_terminal.get_char_width();
  hints.height_inc = m_terminal.get_char_height();
  const int min_width_chars = 4;
  const int min_height_chars = 2;
  hints.min_width = hints.base_width + hints.width_inc * min_width_chars;
  hints.min_height = hints.base_height + hints.height_inc * min_height_chars;
  set_geometry_hints(m_terminal, hints, Gdk::HINT_RESIZE_INC | Gdk::HINT_MIN_SIZE | Gdk::HINT_BASE_SIZE);
  // scrollbar is already set up during initialization, so nothing to do here.
  // set up a window.
  set_title("Simple Gnome::Vte::Terminal example");
  // show us the co... terminal, we mean.
  show_all_children();
}

Simple::~Simple()
{}

void
Simple::on_child_exited()
{
  hide();
}
