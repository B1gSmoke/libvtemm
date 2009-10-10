## Copyright (c) 2008, 2009 libvtemm development team.

AUTOMAKE_OPTIONS = subdir-objects

include $(srcdir)/m4/filelist.am

dist_noinst_DATA = $(addprefix m4/,$(files_codegen_m4))
noinst_PROGRAMS = extradefs/generate_extra_defs

extradefs_generate_extra_defs_SOURCES = extradefs/generate_extra_defs_libvte.cc
extradefs_generate_extra_defs_LDADD   = $(LIBVTEMM_LIBS) -lglibmm_generate_extra_defs-2.4

AM_CPPFLAGS = -I$(top_builddir) $(GTHREAD_CFLAGS) $(LIBVTEMM_CFLAGS)
AM_CXXFLAGS = $(LIBVTEMM_WXXFLAGS)

.DELETE_ON_ERROR:

