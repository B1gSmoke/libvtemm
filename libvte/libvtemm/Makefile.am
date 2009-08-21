## Copyright (c) 2009
## The libvtemm development team.

lib_LTLIBRARIES = libvtemm-@LIBVTEMM_API_VERSION@.la

include $(srcdir)/../src/filelist.am
include $(srcdir)/filelist.am
include $(top_srcdir)/build/compile-binding.am

AM_CPPFLAGS = $(binding_includes) $(binding_cppflags) $(GTHREAD_CFLAGS) $(LIBVTEMM_CFLAGS)
AM_CXXFLAGS = $(LIBVTEMM_WXXFLAGS)

libvtemm_@LIBVTEMM_API_VERSION@_la_SOURCES = $(binding_sources) $(files_internal_cc)
libvtemm_@LIBVTEMM_API_VERSION@_la_LDFLAGS = -no-undefined -version-info $(LIBVTEMM_SO_VERSION)
libvtemm_@LIBVTEMM_API_VERSION@_la_LIBADD  = $(LIBVTEMM_LIBS)

dist_noinst_HEADERS = $(files_internal_h)
