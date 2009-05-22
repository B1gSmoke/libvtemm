/* textandcharattrs.h
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

#ifndef _LIBVTEMM_TEXT_AND_CHAR_ATTRS_H_
#define _LIBVTEMM_TEXT_AND_CHAR_ATTRS_H_

#include <glibmm/arrayhandle.h>
#include <libvtemm/charattributes.h>

namespace Gnome
{

namespace Vte
{
/** TextAndCharAttrs - class storing string and its attributes.
 */
class TextAndCharAttrs
{
public:
/** The only way to fill #Gnome::Vte::TextAndCharAttrs class.
 * @param text String to store.
 * @param attributes Array of string's attributes.
 */
  TextAndCharAttrs(const Glib::ustring& text, const ArrayHandle_CharAttributes& attributes);
  virtual ~TextAndCharAttrs();

/** Gets stored string.
 * @return Stored string.
 */
  Glib::ustring get_text() const;

/** Gets stored attributes.
 * @return Stored attributes.
 */
  ArrayHandle_CharAttributes get_attributes() const;
  // well, setters are not needed.
private:
  ArrayHandle_CharAttributes m_attributes;
  Glib::ustring m_text;
};

} // namespace Vte

} // namespace Gnome

#endif // _LIBVTEMM_TEXT_AND_CHAR_ATTRS_H_
