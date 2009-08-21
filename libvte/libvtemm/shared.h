/* shared.h
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

#ifndef _LIBVTEMM_SHARED_H_
#define _LIBVTEMM_SHARED_H_

#include <glibmm/arrayhandle.h>

#include <string>

namespace Gnome
{

namespace Vte
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

struct StdStringNullTraits
{
  typedef std::string CppType;
  typedef const char* CType;
  typedef char* CTypeNonConst;

  static CType to_c_type(const std::string& str)
  {
    return (str.empty()) ? 0 : str.c_str();
  }
  static CType to_c_type(const Glib::ustring& str)
  {
    return (str.empty()) ? 0 : str.c_str();
  }
  static CType to_c_type(CType str)
  {
    return str;
  }
  static CppType to_cpp_type(CType str)
  {
    return (str) ? std::string(str) : std::string();
  }
  static void release_c_type(CType str)
  {
    g_free(const_cast<CTypeNonConst>(str));
  }
};

#endif // DOXYGEN_SHOULD_SKIP_THIS

/** StdStringArrayHandle - when converted to vector holding c strings, every
 * empty std::string in StdStringArrayHandle is converted to 0.
 */
typedef Glib::ArrayHandle<std::string, StdStringNullTraits> StdStringArrayHandle;

} // namespace Vte

} // namespace Gnome

#endif // _LIBVTEMM_SHARED_H_
