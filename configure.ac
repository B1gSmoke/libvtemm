AC_INIT([libvtemm], [0.23.0],
        [http://bugzilla.gnome.org/enter_bug.cgi?product=libvtemm],
        [libvtemm])
AC_PREREQ([2.62])

AC_CONFIG_SRCDIR([libvte/libvtemm.h])
AC_CONFIG_AUX_DIR([build])
AC_CONFIG_MACRO_DIR([build])
AC_CONFIG_HEADERS([build/config.h libvte/libvtemmconfig.h])

AM_INIT_AUTOMAKE([1.9 -Wno-portability check-news dist-bzip2 no-define nostdinc tar-pax])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
AM_MAINTAINER_MODE
AC_ARG_VAR([ACLOCAL_FLAGS], [aclocal flags, e.g. -I <macro dir>])

MM_PREREQ([0.8])
MM_INIT_MODULE([libvtemm-1.2])

AC_SUBST([LIBVTEMM_SO_VERSION], [9:0:0])

# AC_DISABLE_STATIC
# AC_LIBTOOL_WIN32_DLL
# AC_PROG_LIBTOOL
LT_INIT([win32-dll disable-static])
AC_PROG_CXX

AC_SUBST([LIBVTEMM_MODULES], ['glibmm-2.4 >= 2.18.0 pangomm-1.4 >= 2.24.0 gtkmm-2.4 >= 2.19.2 vte >= 0.23.2'])
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
