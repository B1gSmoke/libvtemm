/* match.h
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

#ifndef _LIBVTEMM_MATCH_H_
#define _LIBVTEMM_MATCH_H_

#include <glibmm.h>

namespace Gnome
{

namespace Vte
{
/** Match - simple class holding match and tag of matched regular expression.
 */
class Match
{
public:
/** The only way to fill #Gnome::Vte::Match class.
 * @param text A match.
 * @param tag Tag of matched expression.
 */
  Match(const Glib::ustring& text, int tag);
  virtual ~Match();

/** Gets match.
 * @return Match.
 */
  Glib::ustring get_text() const;

/** Gets tag.
 * @return Tag.
 */
  int get_tag() const;
private:
  Glib::ustring m_text;
  int m_tag;
};

} // namespace Vte

} // namespace Gnome

#endif // _LIBVTEMM_MATCH_H_
