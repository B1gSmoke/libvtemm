/* main.cc
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

#include <gtkmm.h>
#include <libvtemm/init.h>

#include "gettexter.h"

int main(int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);
  Gnome::Vte::init();
  GetTexter window;
  Gtk::Main::run(window);
  return 0;
}
