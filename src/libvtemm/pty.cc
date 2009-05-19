/* pty.cc
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

#include <glib.h>
#include <vte/pty.h>

#include "internalroutines.h"
#include "pty.h"

namespace Gnome
{

namespace Vte
{

namespace Pty
{

int _open(Glib::Pid& child, const StdStringArrayHandle& env_add,
          const std::string& command, const StdStringArrayHandle& argv,
          const std::string& directory,
          int columns, int rows,
          bool lastlog, bool utmp, bool wtmp)
{
  const char* c_command = get_c_string(command);
  const char* c_directory = get_c_string(directory);
  char** c_env_add = get_c_string_vector(env_add);
  char** c_argv = get_c_string_vector(argv);
  int master = _vte_pty_open(&child, c_env_add, c_command, c_argv, c_directory, columns, rows, static_cast<gboolean>(lastlog), static_cast<gboolean>(utmp), static_cast<gboolean>(wtmp));
  g_strfreev(c_env_add);
  g_strfreev(c_argv);
  return master;
}

int _get_size(int master, int& columns, int& rows)
{
  return _vte_pty_get_size(master, &columns, &rows);
}

int _set_size(int master, int columns, int rows)
{
  return _vte_pty_set_size(master, columns, rows);
}

void _set_utf8(int pty, bool utf8)
{
  _vte_pty_set_utf8(pty, static_cast<gboolean>(utf8));
}

void _close(int pty)
{
  _vte_pty_close(pty);
}

} // namespace Pty

} // namespace Vte

} // namespace Gnome
