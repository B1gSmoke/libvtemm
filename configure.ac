# configure.ac
#
#  This file tests for various compiler features needed to configure 
#  the gtkmm package.  Original skeleton was provided by Stephan Kulow.
#  All tests were written by Tero Pulkkinen, Mirko Streckenbach, and 
#  Karl Nelson.
#
#
#  Copyright 2001 Free Software Foundation
#  Copyright 1999 gtkmm Development Team
#  Copyright 1998 Stephan Kulow
#

#########################################################################
#  Version and initialization
#########################################################################
m4_define([PACKAGEMM_MAJOR_VERSION], [0])
m4_define([PACKAGEMM_MINOR_VERSION], [20])
m4_define([PACKAGEMM_MICRO_VERSION], [2])
m4_define([PACKAGEMM_RELEASE], [PACKAGEMM_MAJOR_VERSION.PACKAGEMM_MINOR_VERSION])
m4_define([PACKAGEMM_VERSION], [PACKAGEMM_RELEASE.PACKAGEMM_MICRO_VERSION])
m4_define([PACKAGEMM_API_MAJOR_VERSION], [1])
m4_define([PACKAGEMM_API_MINOR_VERSION], [0])
m4_define([PACKAGEMM_API_VERSION], [PACKAGEMM_API_MAJOR_VERSION.PACKAGEMM_API_MINOR_VERSION])
m4_define([PACKAGEMM_C_NAME], [vte])
m4_define([PACKAGEMM_NAME], [lib]PACKAGEMM_C_NAME[mm])
AC_INIT(PACKAGEMM_NAME, PACKAGEMM_VERSION, [krnowak@svn.gnome.org])
AC_CONFIG_SRCDIR([src/]PACKAGEMM_NAME[.h])
AC_CONFIG_MACRO_DIR([scripts])

#
# +1 : ? : +1  == new interface that does not break old one
# +1 : ? : 0   == new interface that breaks old one
#  ? : ? : 0   == no new interfaces, but breaks apps
#  ? :+1 : ?   == just some internal changes, nothing breaks but might work 
#                 better
# CURRENT : REVISION : AGE
LIBVTEMM_SO_VERSION=6:0:4

AC_SUBST([LIBVTEMM_SO_VERSION])

AC_CONFIG_AUX_DIR(scripts)

dnl For automake, pkg-config, Doxygen and config header
LIBVTEMM_C_PACKAGE_NAME=PACKAGEMM_C_NAME
LIBVTEMM_PACKAGE_NAME=PACKAGEMM_NAME
LIBVTEMM_VERSION=PACKAGEMM_VERSION
LIBVTEMM_DESCRIPTION="C++ wrapper for lib$LIBVTEMM_C_PACKAGE_NAME"
LIBVTEMM_API_VERSION=PACKAGEMM_API_VERSION
LIBVTEMM_REQUIRES="glibmm-2.4 gtkmm-2.4 vte"
LIBVTEMM_MAJOR_VERSION=PACKAGEMM_MAJOR_VERSION
LIBVTEMM_MINOR_VERSION=PACKAGEMM_MINOR_VERSION
LIBVTEMM_MICRO_VERSION=PACKAGEMM_MICRO_VERSION

AC_SUBST([LIBVTEMM_C_PACKAGE_NAME])
AC_SUBST([LIBVTEMM_PACKAGE_NAME])
AC_SUBST([LIBVTEMM_VERSION])
AC_SUBST([LIBVTEMM_DESCRIPTION])
AC_SUBST([LIBVTEMM_API_VERSION])
AC_SUBST([LIBVTEMM_REQUIRES])
AC_SUBST([LIBVTEMM_MAJOR_VERSION])
AC_SUBST([LIBVTEMM_MINOR_VERSION])
AC_SUBST([LIBVTEMM_MICRO_VERSION])

dnl Initialize automake stuff
# Initialize automake stuff
# tar-ustar asks it to use a sensible tar format that can handle long filenames.
AM_INIT_AUTOMAKE([1.9 tar-ustar])

#########################################################################
#  Configure arguments 
#########################################################################

# Add an --enable-reference configure option:
AL_ENABLE_REFERENCE

# Add an --enable-use-deprecations configure option:
AL_ENABLE_USE_DEPRECATIONS
	
# Add an --enable-deprecated-api configure option:
AL_ENABLE_DEPRECATED_API

#########################################################################
#  Environment Checks
#########################################################################
AC_PROG_CC
AC_PROG_CPP
AC_PROG_MAKE_SET
AC_CANONICAL_HOST

AL_CHECK_FOR_WIN32

AM_DISABLE_STATIC
AC_LIBTOOL_WIN32_DLL
AM_PROG_LIBTOOL

AL_PROG_GNU_M4(AC_MSG_ERROR([dnl
SUN m4 does not work for building libvtemm. 
Please install GNU m4.]))

AL_PROG_GNU_MAKE(AC_MSG_ERROR([dnl
SUN make does not work for building libvtemm.
Please install GNU make.]))

AL_PROG_PERL(AC_MSG_ERROR([Perl is required to build libvtemm.]))

AC_CHECK_PROGS(PERL, perl5 perl)

#########################################################################
#  Dependency checks
#########################################################################
PKG_CHECK_MODULES(LIBVTEMM, glibmm-2.4 >= 2.18.0 gtkmm-2.4 >= 2.14.0 vte >= 0.20.0)
AC_SUBST([LIBVTEMM_CFLAGS])
AC_SUBST([LIBVTEMM_LIBS])

GMM_PROCDIR=`pkg-config --variable=gmmprocdir glibmm-2.4`
AC_SUBST([GMM_PROCDIR])
GMM_PROC=$GMM_PROCDIR/gmmproc
AC_SUBST([GMM_PROC])

#########################################################################
#  C++ checks
#########################################################################
AC_PROG_CXX
AC_LANG_CPLUSPLUS

AL_DOXYGEN_INPUT_SUBDIRS([$LIBVTEMM_PACKAGE_NAME])

AC_CONFIG_FILES([
  Makefile

  src/Makefile
  src/libvtemmconfig.h
  src/libvtemm-1.0.pc
    src/libvtemm/Makefile
      src/libvtemm/g/Makefile
      src/libvtemm/private/Makefile
  
  tools/Makefile
    tools/extra_defs_gen/Makefile
    tools/m4/Makefile

  scripts/Makefile

  docs/Makefile
  docs/reference/Makefile
    docs/reference/Doxyfile

  examples/Makefile
    examples/simple/Makefile

  old_news_and_changelogs/Makefile
])

AC_OUTPUT

