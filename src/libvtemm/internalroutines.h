/* internalroutines.h
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

#ifndef _LIBVTEMM_INTERNAL_ROUTINES_H_
#define _LIBVTEMM_INTERNAL_ROUTINES_H_

#include <libvtemm/shared.h>

namespace Gnome
{

namespace Vte
{

const char*
get_c_string(const std::string& cpp_string);

char**
get_c_string_vector(const StdStringArrayHandle& cpp_string_vector);

} // namespace Vte

} // namespace Gnome

#endif // _LIBVTEMM_INTERNAL_ROUTINES_H_
