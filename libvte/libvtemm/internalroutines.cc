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
  unsigned int cpp_string_vector_size = cpp_string_vector.size();
  const char* const* data = cpp_string_vector.data();
  if ((!cpp_string_vector_size) || (!(data[0])))
  {
    return 0;
  }
  if (!(data[cpp_string_vector_size - 1]))
  {
    cpp_string_vector_size--;
  }
  char** dup = reinterpret_cast<char**>(g_malloc0((cpp_string_vector_size + 1) * sizeof(char*)));
  for (unsigned int iter = 0; iter < cpp_string_vector_size; iter++)
  {
    dup[iter] = g_strdup(data[iter]);
  }
  return dup;
}

} // namespace Vte

} // namespace Gnome
