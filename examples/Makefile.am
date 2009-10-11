## Copyright (c) 2008, 2009 libvtemm development team.

AUTOMAKE_OPTIONS = subdir-objects

check_PROGRAMS = 		\
	simple/example		\
	gettexter/example

libvtemm_includes = -I$(top_builddir)/libvte $(if $(srcdir:.=),-I$(top_srcdir)/libvte)
local_cppflags    = -I$(top_builddir) $(libvtemm_includes)

AM_CPPFLAGS = $(local_cppflags) $(GTHREAD_CFLAGS) $(LIBVTEMM_CFLAGS)
AM_CXXFLAGS = $(LIBVTEMM_WXXFLAGS)

local_libvtemm = $(top_builddir)/libvte/libvtemm/libvtemm-$(LIBVTEMM_API_VERSION).la

LDADD = $(LIBVTEMM_LIBS) $(local_libvtemm)

simple_example_src =	 	\
	simple/simple.cc 	\
	simple/simple.h 	\
	simple/main.cc

gettexter_example_src = 	\
	gettexter/gtterminal.cc	\
	gettexter/gtterminal.h	\
	gettexter/gettexter.cc	\
	gettexter/gettexter.h	\
	gettexter/main.cc

simple_example_SOURCES = $(simple_example_src)
gettexter_example_SOURCES = $(gettexter_example_src)

example_path = $(datadir)/$(LIBVTEMM_MODULE_NAME)/examples

simplecodedir = $(example_path)/simple
simplecode_DATA = $(simple_example_src)

gettextercodedir = $(example_path)/gettexter
gettextercode_DATA = $(gettexter_example_src)
