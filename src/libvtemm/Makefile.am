## Copyright (c) 2009
## The libvtemm development team.

SUBDIRS = g private

files_extra_h = cursorposition.h init.h match.h padding.h ptymaster.h ptysize.h \
	textandcharattrs.h wrap_init.h shared.h
files_extra_cc = cursorposition.cc init.cc match.cc padding.cc ptymaster.cc ptysize.cc \
	textandcharattrs.cc

files_internal_h = internalroutines.h
files_internal_cc = internalroutines.cc

include $(top_srcdir)/build_shared/Makefile_shared.am_fragment
#defined:
# generated_sources_cc

lib_LTLIBRARIES = libvtemm-1.1.la
libvtemm_1_1_la_SOURCES = $(files_extra_cc) $(generated_sources_cc) $(files_internal_cc)
libvtemm_1_1_la_LDFLAGS = $(common_ldflags)
libvtemm_1_1_la_LIBADD = @LIBVTEMM_LIBS@

-include $(top_srcdir)/git.mk
