/* gettexter.cc
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

#include <iostream>

#include "gettexter.h"

GetTexter::GetTexter()
:
  m_main_box(),
  m_term_box(),
  m_terminal(),
  m_scrollbar(m_terminal.get_adjustment()),
  m_label(),
  m_entry(),
  m_button_box(Gtk::BUTTONBOX_SPREAD),
  m_get_every_second_button("Get every second"),
  m_get_only_a_button("Get only 'a'")
{
  // Pack everything.
  add(m_main_box);
  
  m_main_box.pack_start(m_term_box);
  m_main_box.pack_start(m_label, false, true);
  m_main_box.pack_start(m_entry, false, true);
  m_main_box.pack_start(m_button_box, false, true);
  
  m_term_box.pack_start(m_terminal);
  m_term_box.pack_start(m_scrollbar);
  
  m_button_box.pack_start(m_get_every_second_button);
  m_button_box.pack_start(m_get_only_a_button);
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
  // Set focus and default action on entry.
  m_entry.set_flags(Gtk::CAN_FOCUS | Gtk::CAN_DEFAULT);
  m_entry.grab_focus();
  m_entry.grab_default();
  // Set activation signal on entry (it will be executed when enter or return
  // is pressed).
  m_entry.signal_activate().connect(sigc::mem_fun(*this, &GetTexter::on_entry_activated));
  // Connect signals to buttons.
  m_get_every_second_button.signal_clicked().connect(sigc::mem_fun(*this, &GetTexter::on_get_every_second_button_clicked));
  m_get_only_a_button.signal_clicked().connect(sigc::mem_fun(*this, &GetTexter::on_get_only_a_button_clicked));
  
  set_title("GetTexter example");
  
  show_all_children();
}

GetTexter::~GetTexter()
{}

// Gnome::Vte::Terminal::get_text() gets whole screen, so it has lots of
// newlines, which are stripped here.
void
GetTexter::on_get_every_second_button_clicked()
{
  m_label.set_text(m_terminal.get_every_second());
}

// This method use Gnome::Vte::Terminal::get_text and count number of 'a'
// occurences and sets label with string consisting of that number of 'a's.
void
GetTexter::on_get_only_a_button_clicked()
{
  Glib::ustring text(m_terminal.get_text(sigc::ptr_fun(&Gnome::Vte::Terminal::always_selected)).get_text());
  unsigned int counter = 0;
  unsigned int text_len = text.size();
  for (unsigned iter = 0; iter < text_len; iter++)
  {
    if (text[iter] == 'a')
    {
      counter++;
    }
  }
  m_label.set_text(Glib::ustring(counter, 'a'));
}

// Appends carriage return and newline to text from entry and feeds the terminal
// with it. Without carriage return cursor will move to cell (row + 1, column)
// instead of cell (row + 1, 0).
void
GetTexter::on_entry_activated()
{
  m_terminal.feed(m_entry.get_text() + "\r\n");
  m_entry.set_text(Glib::ustring());
}
