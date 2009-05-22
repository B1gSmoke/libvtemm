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
#include <libvtemm/ptysize.h>
#include <libvtemm/shared.h>

namespace Gnome
{

namespace Vte
{

namespace Pty
{

/** Master - class holding a descriptor for the master side of PTY pair.
 */
class Master
{
public:
  /** Sets descriptor for the master side of PTY pair to @a d. Use other than
   * default value at your own risk. Otherwise
   * use open() to set a descriptor.
   * @param d Descriptor for the master side of PTY pair. -1 by default.
   */
  Master(int d = -1);
  /** If master side of PTY pair is not equal to -1, it calls close().
   * Otherwise it do nothing.
   */
  ~Master();

  /** Start up the given binary (exact path, not interpreted at all) in a
   * pseudo-terminal of its own, returning the child's PID and logging the
   * session to the specified files.
   * @param command Command to be executed (not interpreted at all). If empty, fork will be executed.
   * @param argv Empty string terminated list of arguments given to executed binary (argv[0] should be a binary name). See Gnome::Vte::Terminal::fork_command() for description about format of this parameter.
   * @param env_add Empty string terminated list of environment variables to be added before executing a command. See Gnome::Vte::Terminal::fork_command() for description about format of this parameter.
   * @param directory Path where command have to be executed. If empty, path will be inherited from parent.
   * @param columns Number of columns of pty. If set to 0, compiled-in defaults will be used.
   * @param rows Number of rows of pty. If set to 0, compiled-in defaults will be used.
   * @param lastlog @c true if the session should be logged to the lastlog.
   * @param utmp @c true if the session should be logged to the utmp/utmpx log.
   * @param wtmp @c true if the session should be logged to the wtmp/wtmpx log.
   * @return Descriptor for the master side of the PTY pair.
   */
  Glib::Pid open(const std::string& command = std::string(),
                 const StdStringArrayHandle& argv = StdStringArrayHandle(0, Glib::OWNERSHIP_NONE),
                 const StdStringArrayHandle& env_add = StdStringArrayHandle(0, Glib::OWNERSHIP_NONE),
                 const std::string& directory = std::string(),
                 int columns = 0,
                 int rows = 0,
                 bool lastlog = false,
                 bool utmp = false,
                 bool wtmp = false);

  /** Attempts to read the pseudo terminal's window size. If something goes
   * wrong, Gnome::Vte::Pty::Size::is_ok() will return @c false and @c errno
   * will be set.
   * @return Gnome::Vte::Pty::Size instance holding number of columns and rows.
   */
  Size get_size() const;

  /** Attempts to resize the pseudo terminal's window size.  If successful, the
   * OS kernel will send @c SIGWINCH to the child process group, otherwise
   * @c false will be returned and @c errno will be set.
   * @param columns The desired number of columns.
   * @param rows The desired number of rows.
   * @return @c false if there was an error, otherwise @c true.
   */
  bool set_size(int columns, int rows);

  /** Try to let the kernel know that the terminal is or is not UTF-8.
   * @param utf8 @c true if the terminal is UTF-8.
   */
  void set_utf8(bool utf8 = true);
  
  /** Gets descriptor for the master side of the PTY pair.
   * @return Descriptor for the master side of the PTY pair.
   */
  int get_pty() const;

  /** Close a pty. This is also called in destructor.
   */
  void close();
private:
  int m_d;
};

} // namespace Pty

} // namespace Vte

} // namespace Gnome

#endif // _LIBVTEMM_PTY_H_
