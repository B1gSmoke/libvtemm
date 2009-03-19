/* simple.cc
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

#include "simple.h"
#include <vector>
#include <string>

Simple::Simple()
: m_terminal()
{
	/*
	we are making a NULL terminated string vector. as we are passing neither
	argv nor envv, the string vector contains one empty string only.
	*/
	std::vector<std::string> nil;
	nil.push_back(std::string());
	std::string command("sh");
	set_title("Simple Gnome::Vte::Terminal example");
	m_terminal.fork_command(command, nil, nil, std::string(), false, false, false);
	m_terminal.set_size(80, 24);
	m_terminal.signal_child_exited().connect(sigc::mem_fun(*this, &Simple::on_child_exited));
	add(m_terminal);
	m_terminal.set_flags(Gtk::CAN_DEFAULT);
	m_terminal.grab_default();
	show_all_children();
}

Simple::~Simple()
{
	
}

void Simple::on_child_exited()
{
	hide();
}
