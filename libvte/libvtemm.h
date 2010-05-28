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
 * libvtemm is a C++ interface VTE library implementing a terminal widget using
 * GTK+.
 *
 * @section basics Basic usage
 *
 * Include the libvtemm header:
 * @code
 * #include <libvtemm.h>
 * @endcode
 * This includes every header installed by libvtemmmm, so can slow down
 * compilation, but suffices for this simple example. Assuming that your
 * program source file is @c program.cc, compile it with:
 * @code
 * g++ program.cc -o program  `pkg-config --cflags --libs libvtemm-1.2`
 * @endcode
 * Alternatively, if using autoconf, use the following in @c configure.ac:
 * @code
 * PKG_CHECK_MODULES([LIBVTEMM], [libvtemm-1.2])
 * @endcode
 * Then use the generated @c LIBVTEMM_CFLAGS and @c LIBVTEMM_LIBS variables in
 * the project @c Makefile.am files. For example:
 * @code
 * program_CPPFLAGS = $(LIBVTEMM_CFLAGS)
 * program_LDADD = $(LIBVTEMM_LIBS)
 * @endcode
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
