## Copyright (c) 2009
## The libvtemm development team.

lib_LTLIBRARIES = libvtemm-1.2.la

include $(srcdir)/../src/filelist.am
include $(srcdir/filelist.am
include $(top_srcdir)/build/compile_binding.am

AM_CPPFLAGS = $(binding_includes) $(binding_cppflags) $(GTHREAD_CFLAGS) $(LIBVTEMM_CFLAGS)
AM_CXXFLAGS = $(LIBVTEMM_WXXFLAGS)

libvtemm_1_2_la_SOURCES = $(binding_sources) $(files_internal_cc)
libvtemm_1_2_la_LDFLAGS = -no-undefined -version-info $(LIBVTEMM_SO_VERSION)
libvtemm_1_2_la_LIBADD  = $(LIBVTEMM_LIBS)

EXTRA_DIST = 			\
	$(files_internal_h) 	\
	$(files_internal_cc)
