/* pty.cc
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

#include <glib.h>
#include <vte/pty.h>
#include <libvtemm/pty.h>

namespace Gnome
{

namespace Vte
{

namespace Pty
{

int _open(Glib::Pid& child, const Glib::StringArrayHandle& env_add,
          const std::string& command, const Glib::StringArrayHandle& argv,
          const std::string& directory,
          int columns, int rows,
          bool lastlog, bool utmp, bool wtmp)
{
	return _vte_pty_open(&child, const_cast<char**>((env_add).data()), command.c_str(), const_cast<char**>((argv).data()), directory.c_str(), columns, rows, static_cast<int>(lastlog), static_cast<int>(utmp), static_cast<int>(wtmp));
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
	_vte_pty_set_utf8(pty, static_cast<int>(utf8));
}

void _close(int pty)
{
	_vte_pty_close(pty);
}

} // namespace Pty

} // namespace Vte

} // namespace Gnome
