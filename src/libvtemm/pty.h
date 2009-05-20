/* pty.h
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

#ifndef _LIBVTEMM_PTY_H_
#define _LIBVTEMM_PTY_H_

#include <glibmm.h>
#include <libvtemm/shared.h>

namespace Gnome
{

namespace Vte
{

namespace Pty
{

/** Start up the given binary (exact path, not interpreted at all) in a
 * pseudo-terminal of its own, returning the descriptor for the master
 * side of the PTY pair, logging the session to the specified files, and
 * storing the child's PID in the given argument.
 * @param child Stored child's PID.
 * @param env_add Empty string terminated list of environment variables to be added before executing a command. See Gnome::Vte::Terminal::fork_command() for description about format of this parameter.
 * @param command Command to be executed (not interpreted at all). If empty, fork will be executed.
 * @param argv Empty string terminated list of arguments given to executed binary (argv[0] should be a binary name). See Gnome::Vte::Terminal::fork_command() for description about format of this parameter.
 * @param directory Path where command have to be executed. If empty, path will be inherited from parent.
 * @param columns Number of columns of pty.
 * @param rows Number of rows of pty.
 * @param lastlog %true if the session should be logged to the lastlog.
 * @param utmp %true if the session should be logged to the utmp/utmpx log.
 * @param wtmp %true if the session should be logged to the wtmp/wtmpx log.
 * @return Descriptor for the master side of the PTY pair.
 */
int _open(Glib::Pid& child, const StdStringArrayHandle& env_add,
          const std::string& command, const StdStringArrayHandle& argv,
          const std::string& directory,
          int columns, int rows,
          bool lastlog, bool utmp, bool wtmp);

/** Read the size of a terminal.
 * @param master Descriptor for the master side of the PTY pair.
 * @param columns Stored number of columns.
 * @param rows Stored number of rows.
 * @return Returns 0 on success, -1 on failure, with errno set to defined return codes from ioctl().
 */
int _get_size(int master, int& columns, int& rows);

/** Set the size of a terminal.
 * @param master Descriptor for the master side of the PTY pair.
 * @param columns Number of columns to set.
 * @param rows Number of rows to set.
 * @return Returns 0 on success, -1 on failure, with errno set to defined return codes from ioctl().
 */
int _set_size(int master, int columns, int rows);

/** Try to let the kernel know that the terminal is or is not UTF-8.
 * @param pty Descriptor for the master side of the PTY pair.
 * @param utf8 %TRUE if the terminal is UTF-8.
 */
void _set_utf8(int pty, bool utf8);

/** Close a pty
 * @param pty Descriptor for the master side of the PTY pair.
 */
void _close(int pty);

} // namespace Pty

} // namespace Vte

} // namespace Gnome

#endif // _LIBVTEMM_PTY_H_
