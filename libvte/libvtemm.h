/* libvtemm.h
 *
 * Copyright (C) 2008, 2009, 2010 libvtemm Development Team
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

#ifndef _LIBVTEMM_H_
#define _LIBVTEMM_H_

/** @mainpage libvtemm Reference Manual
 *
 * @section description Description
 *
 * vte is a library implementing Gtk+ widget emulating terminal. The libvtemm
 * C++ binding provides a C++ interface on top of the vte C library.
 *
 * @section overview Overview
 *
 * The libvtemm API provides a subset of vte functionality. It wraps only
 * @c VteTerminal, leaving @c VteReaper, which is deprecated, and
 * @c VteTerminalAccessible, which author does not see any purpose for
 * programmists using this widget.
 *
 * @section use Use
 *
 * To use libvtemm in your C++ application, include the central header file
 * <tt>\<libvtemm.h\></tt> or, for terminal widget only,
 * <tt>\<libvtemm/terminal.h\></tt>. The libvtemm package ships a @c pkg-config
 * file with the correct include path and link command-line for the compiler.
 *
 * The source code of the @ref simple/main.cc "Simple Terminal" and
 * @ref gettexter/main.cc "GetTexter" example programs demonstrate the
 * basic usage of the libvtemm API.
 *
 * @section contact Contact
 *
 * The best way to ask questions about libvtemm is to use one of below:
 *
 * @subsection mailinglist Mailing list
 *
 * Send a mail to gtkmm-list@gnome.org.
 *
 * @subsection irc IRC
 *
 * Join c++ channel on irc.gnome.org and ask away.
 *
 * @section sourcecode Source code
 *
 * Library is developed and placed on GNOME git repository and release tarballs
 * are put on GNOME FTP site.
 *
 * @subsection browse Browsing the source code
 *
 * See <tt>http://git.gnome.org/browse/libvtemm/</tt>.
 *
 * @subsection bleedingedge Getting bleeding edge source code
 *
 * <tt>git clone git://git.gnome.org/libvtemm libvtemm</tt>
 *
 * @subsection tarballs Getting release tarballs
 *
 * See <tt>http://download.gnome.org/sources/libvtemm/</tt>.
 *
 * @section license License
 *
 * libvtemm is licensed under GNU Lesser Public License version 3 or (at your
 * option) any later.
 *
 * @section authors Author
 *
 * This library was written and is maintained by Krzesimir Nowak.
 */

#include <gtkmm.h>

#include <libvtemm/charattributes.h>
#include <libvtemm/cursorposition.h>
#include <libvtemm/init.h>
#include <libvtemm/match.h>
#include <libvtemm/padding.h> // TODO: deprecated.
#include <libvtemm/ptymaster.h>
#include <libvtemm/ptysize.h>
#include <libvtemm/shared.h>
#include <libvtemm/terminal.h>
#include <libvtemm/textandcharattrs.h>
#include <libvtemm/wrap_init.h>

/** @example simple/main.cc
 * The simple terminal launching shell.
 *
 * @include simple.h
 * @include simple.cc
 */

/** @example gettexter/main.cc
 * A silly application getting text.
 *
 * @include gtterminal.h
 * @include gtterminal.cc
 * @include gettexter.h
 * @include gettexter.cc
 */

#endif // _LIBVTEMM_H_
