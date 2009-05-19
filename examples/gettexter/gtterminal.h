/* gtterminal.h
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

#ifndef _LIBVTEMM_EXAMPLE_GTTERMINAL_H_
#define _LIBVTEMM_EXAMPLE_GTTERMINAL_H_

#include <gtkmm.h>
#include <libvtemm/terminal.h>

class GtTerminal : public Gnome::Vte::Terminal
{
public:
  GtTerminal();
  virtual ~GtTerminal();
  Glib::ustring get_every_second();
protected:
  // Method passed to get_text method.
  virtual bool on_get_every_second(long, long);
private:
  unsigned int counter;
};

#endif // _LIBVTEMM_EXAMPLE_GTTERMINAL_H_
