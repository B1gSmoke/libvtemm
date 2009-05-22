/* ptysize.cc
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

#include "ptysize.h"

namespace Gnome
{

namespace Vte
{

namespace Pty
{

Size::Size(int columns, int rows, bool ok)
:
  m_columns(columns),
  m_rows(rows),
  m_ok(ok)
{}

Size::~Size()
{}

int Size::get_columns() const
{
  return m_columns;
}

int Size::get_rows() const
{
  return m_rows;
}

bool Size::is_ok() const
{
  return m_ok;
}

} // namespace Pty

} // namespace Vte

} // namespace Gnome
