/* cursorposition.h
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

#ifndef _LIBVTEMM_CURSOR_POSITION_H_
#define _LIBVTEMM_CURSOR_POSITION_H_

namespace Gnome
{

namespace Vte
{
/** CursorPosition - simple struct holding cursor position.
 */
class CursorPosition
{
public:
/** The only way to fill #Gnome::Vte::CursorPosition class.
 * @param column Cursor's column position.
 * @param row Cursor's row position.
 */
  CursorPosition(long column, long row);
  virtual ~CursorPosition();

/** Gets column position.
 * @return Column position.
 */
  long get_column() const;

/** Gets row position.
 * @return Row position.
 */
  long get_row() const;
private:
  long m_column;
  long m_row;
};

} // namespace Vte

} // namespace Gnome

#endif // _LIBVTEMM_CURSOR_POSITION_H_
