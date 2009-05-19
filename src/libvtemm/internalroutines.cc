/* internalroutines.cc
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

#include "internalroutines.h"

namespace Gnome
{

namespace Vte
{

const char*
get_c_string(const std::string& cpp_string)
{
  if (cpp_string.empty())
  {
    return 0;
  }
  return cpp_string.c_str();
}

char**
get_c_string_vector(const StdStringArrayHandle& cpp_string_vector)
{
  if (cpp_string_vector.empty())
  {
    return 0;
  }
  unsigned int cpp_string_vector_len = cpp_string_vector.size();
  char** c_string_vector = reinterpret_cast<char**>(g_malloc0(cpp_string_vector_len + 1));
  const char* const * temp_c_string_vector = cpp_string_vector.data();
  for (unsigned int iter = 0; iter < cpp_string_vector_len; iter++)
  {
    c_string_vector[iter] = g_strdup(temp_c_string_vector[iter]);
  }
  return c_string_vector;
}

} // namespace Vte

} // namespace Gnome
