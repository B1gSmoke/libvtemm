/* main.cc
 *
 * Copyright (C) 2008 libvtemm Development Team
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

#include <gtkmm/main.h>
#include "simple.h"
#include <libvtemm/init.h>

int main(int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);
	Gnome::Vte::init();
	Simple window;
	Gtk::Main::run(window);
	return 0;
}
