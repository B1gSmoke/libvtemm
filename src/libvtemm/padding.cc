/* padding.cc
 *
 * Copyright (C) 2008, 2009 libvtemm Development Team
 *
 * This file is part of libvtemm.
 *
 * libvtemm is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libvtemm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser Public License
 * along with libvtemm.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libvtemm/padding.h>

namespace Gnome
{

namespace Vte
{

Padding::Padding(int x_pad, int y_pad)
:
  m_x_pad(x_pad),
  m_y_pad(y_pad)
{
}

Padding::~Padding()
{
}

int Padding::get_x_pad() const
{
  return m_x_pad;
}

int Padding::get_y_pad() const
{
  return m_y_pad;
}

} // namespace Vte

} // namespace Gnome
