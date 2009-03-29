/* textandcharattrs.cc
 *
 * Copyright (C) 2008 libvtemm Development Team
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

#include <libvtemm/textandcharattrs.h>

namespace Gnome
{

namespace Vte
{

TextAndCharAttrs::TextAndCharAttrs(const Glib::ustring& src_text, const ArrayHandle_CharAttributes& src_attributes)
: attributes(src_attributes),
  text(src_text)
{
}

TextAndCharAttrs::~TextAndCharAttrs()
{
}

inline Glib::ustring TextAndCharAttrs::get_text()
{
  return text;
}

inline Glib::ustring TextAndCharAttrs::get_text() const
{
  return text;
}

inline ArrayHandle_CharAttributes TextAndCharAttrs::get_attributes()
{
  return attributes;
}

inline ArrayHandle_CharAttributes TextAndCharAttrs::get_attributes() const
{
  return attributes;
}

} // namespace Vte

} // namespace Gnome
