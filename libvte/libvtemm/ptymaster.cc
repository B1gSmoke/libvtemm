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
#include "ptymaster.h"

namespace Gnome
{

namespace Vte
{

namespace Pty
{

Master::Master(int d, bool is_main)
:
  m_d(d),
  m_is_main(is_main)
{}

Master::Master(const Master& master)
:
  m_d(master.m_d),
  m_is_main(false)
{}

Master::~Master()
{
  if ((m_d != -1) && (m_is_main))
  {
    close();
  }
}

Master& Master::operator=(Master& master)
{
  this->m_d = master.m_d;
  this->m_is_main = false;
  return *this;
}

Glib::Pid
Master::open(const std::string& command,
             const StdStringArrayHandle& argv,
             const StdStringArrayHandle& env_add,
             const std::string& directory,
             int columns,
             int rows,
             bool lastlog,
             bool utmp,
             bool wtmp)
{
  Glib::Pid child = -1;
  const char* c_command = get_c_string(command);
  const char* c_directory = get_c_string(directory);
  char** c_env_add = get_c_string_vector(env_add);
  char** c_argv = get_c_string_vector(argv);
  m_d = _vte_pty_open(&child, c_env_add, c_command, c_argv, c_directory, columns, rows, static_cast<gboolean>(lastlog), static_cast<gboolean>(utmp), static_cast<gboolean>(wtmp));
  g_strfreev(c_env_add);
  g_strfreev(c_argv);
  m_is_main = true;
  return child;
}

Size
Master::get_size() const
{
  int columns, rows;
  int res = _vte_pty_get_size(m_d, &columns, &rows);
  if (res < 0)
  {
    return Size(-1, -1, false);
  }
  return Size(columns, rows);
}

bool
Master::set_size(int columns, int rows)
{
  int res = _vte_pty_set_size(m_d, columns, rows);
  if (res < 0)
  {
    return false;
  }
  return true;
}

void
Master::set_utf8(bool utf8)
{
  _vte_pty_set_utf8(m_d, static_cast<gboolean>(utf8));
}

int
Master::get_pty() const
{
  return m_d;
}

void
Master::close()
{
  _vte_pty_close(m_d);
  m_d = -1;
  m_is_main = false;
}

void
Master::set_is_main(bool setting)
{
  m_is_main = setting;
}

bool
Master::get_is_main() const
{
  return m_is_main;
}

} // namespace Pty

} // namespace Vte

} // namespace Gnome
