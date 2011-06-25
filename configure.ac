AC_INIT([libvtemm], [0.25.0],
        [http://bugzilla.gnome.org/enter_bug.cgi?product=libvtemm],
        [libvtemm])
AC_PREREQ([2.62])

AC_CONFIG_SRCDIR([libvte/libvtemm.h])
AC_CONFIG_AUX_DIR([build])
AC_CONFIG_MACRO_DIR([build])
AC_CONFIG_HEADERS([build/config.h libvte/libvtemmconfig.h])

AM_INIT_AUTOMAKE([1.9 -Wno-portability check-news dist-bzip2 no-define nostdinc tar-ustar])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
AM_MAINTAINER_MODE
AC_ARG_VAR([ACLOCAL_FLAGS], [aclocal flags, e.g. -I <macro dir>])

MM_PREREQ([0.9.5])
MM_INIT_MODULE([libvtemm-1.2])

# Copy the mm-common .pl scripts into docs/,
# and use them from there,
# so we can dist them to avoid a tarball-build dependency.
MM_CONFIG_DOCTOOL_DIR([docs])

# The string is of the form C:R:A.
# - If interfaces have been changed or added, but binary compatibility has
#   been preserved, change to C+1:0:A+1
# - If binary compatibility has been broken (e.g. removed or changed interfaces)
#   change to C+1:0:0
# - If the interface is the same as the previous version, change to C:R+1:A
AC_SUBST([LIBVTEMM_SO_VERSION], [11:0:2])

# AC_DISABLE_STATIC
# AC_LIBTOOL_WIN32_DLL
# AC_PROG_LIBTOOL
LT_INIT([win32-dll disable-static])
AC_PROG_CXX

AC_SUBST([LIBVTEMM_MODULES], ['glibmm-2.4 >= 2.22.0 pangomm-1.4 >= 2.24.0 gtkmm-2.4 >= 2.20.0 vte >= 0.24.0 giomm-2.4'])
PKG_CHECK_MODULES([LIBVTEMM], [$LIBVTEMM_MODULES])

MM_PKG_CONFIG_SUBST([GTHREAD_CFLAGS], [--cflags-only-other gthread-2.0])
MM_PKG_CONFIG_SUBST([GMMPROC_DIR], [--variable=gmmprocdir glibmm-2.4])

MM_ARG_DISABLE_DEPRECATED_API([LIBVTEMM])

MM_ARG_ENABLE_DOCUMENTATION
MM_ARG_WITH_TAGFILE_DOC([libstdc++.tag], [mm-common-libstdc++])
MM_ARG_WITH_TAGFILE_DOC([libsigc++-2.0.tag], [sigc++-2.0])
MM_ARG_WITH_TAGFILE_DOC([glibmm-2.4.tag], [glibmm-2.4])
MM_ARG_WITH_TAGFILE_DOC([pangomm-1.4.tag], [pangomm-1.4])
MM_ARG_WITH_TAGFILE_DOC([gtkmm-2.4.tag], [gtkmm-2.4])

AC_LANG([C++])
MM_ARG_ENABLE_WARNINGS([LIBVTEMM_WXXFLAGS],
                       [-Wall],
                       [-pedantic -Wall -Wextra],
                       [G PANGO ATK GDK GDK_PIXBUF GTK VTE])

AC_CONFIG_FILES([Makefile
                 codegen/Makefile
                 libvte/${LIBVTEMM_MODULE_NAME}.pc:libvte/libvtemm.pc.in
                 libvte/${LIBVTEMM_MODULE_NAME}-uninstalled.pc:libvte/libvtemm-uninstalled.pc.in
                 libvte/src/Makefile
                 libvte/libvtemm/Makefile
                 examples/Makefile
                 docs/Makefile
                 docs/reference/Doxyfile])

AC_OUTPUT
