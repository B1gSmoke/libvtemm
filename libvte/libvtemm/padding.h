/* padding.h
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

#ifndef _LIBVTEMM_PADDING_H_
#define _LIBVTEMM_PADDING_H_

#include <libvtemmconfig.h>

#ifndef LIBVTEMM_DISABLE_DEPRECATED

namespace Gnome
{

namespace Vte
{
/** Padding - simple class holding padding.
 *
 * @deprecated Use "inner-border" style property instead.
 */
class Padding
{
public:
/** The only way to fill #Gnome::Vte::Padding class.
 * @param x_pad Left/right-edge padding.
 * @param y_pad Top/botton-edge padding.
 */
  Padding(int x_pad, int y_pad);
  virtual ~Padding();

/** Gets left/right-edge padding.
 * @return Left/right-edge padding.
 */
  int get_x_pad() const;

/** Gets top/bottom-edge padding.
 * @return Top/bottom-edge padding.
 */
  int get_y_pad() const;
private:
  long m_x_pad;
  long m_y_pad;
};

} // namespace Vte

} // namespace Gnome

#endif // LIBVTEMM_DISABLE_DEPRECATED

#endif // _LIBVTEMM_PADDING_H_
