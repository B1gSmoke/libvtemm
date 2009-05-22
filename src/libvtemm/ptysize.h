/* ptysize.h
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

#ifndef _LIBVTEMM_PTY_SIZE_H_
#define _LIBVTEMM_PTY_SIZE_H_

namespace Gnome
{

namespace Vte
{

namespace Pty
{

/** Size - simple class holding size of a pseudo-terminal.
 */
class Size
{
public:
  /** The only way to fill #Gnome::Vte::Pty::Size class.
   * @param columns Pseudo-terminals number of columns.
   * @param rows Pseudo-terminals number of rows.
   */
  Size(int columns, int rows, bool ok = true);
  virtual ~Size();

  /** Gets number of columns.
   * @return Number of columns.
   */
  int get_columns() const;

  /** Gets number of rows.
   * @return Number of rows.
   */
  int get_rows() const;

  /** Checks if there was an error during getting size.
   * @return @c false if something went wrong, otherwise @c true.
   */
  bool is_ok() const;
private:
  int m_columns;
  int m_rows;
  bool m_ok;
};

} // namespace Pty

} // namespace Vte

} // namespace Gnome

#endif // _LIBVTEMM_PTY_SIZE_H_
