/* cursorposition.cc
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

#include <libvtemm/cursorposition.h>

namespace Gnome
{

namespace Vte
{

CursorPosition::CursorPosition(long column, long row)
:
  m_column(column),
  m_row(row)
{
}

CursorPosition::~CursorPosition()
{
}

long CursorPosition::get_column() const
{
  return m_column;
}

long CursorPosition::get_row() const
{
  return m_row;
}

} // namespace Vte

} // namespace Gnome
