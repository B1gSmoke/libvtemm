/* gtterminal.cc
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

#include "gtterminal.h"

GtTerminal::GtTerminal()
:
  Gnome::Vte::Terminal(),
  counter(0)
{
  set_size(80, 24);
}

GtTerminal::~GtTerminal()
{}

// Returns true for every second cell.
bool
GtTerminal::on_get_every_second(long, long)
{
  bool odd = false;
  if (counter % 2)
  {
    odd = true;
  }
  else
  {
    odd = false;
  }
  counter++;
  return odd;
}

Glib::ustring
GtTerminal::get_every_second()
{
  Glib::ustring text(get_text(sigc::mem_fun(*this, &GtTerminal::on_get_every_second)).get_text());
  unsigned int text_len = text.size();
  unsigned int to_erase = 0;
  for (unsigned int iter = text_len - 1; true; iter--)
  {
    gunichar uc = text[iter];
    if ((uc == '\n') || (uc == '\r'))
    {
    	to_erase++;
    }
    else if (to_erase)
    {
    	text.erase(iter + 1, to_erase);
    	to_erase = 0;
    }
    if (!iter)
    {
    	break;
    }
  }
  counter = 0;
  return text;
}
