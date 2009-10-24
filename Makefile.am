## Copyright (c) 2009 libvtemm development team.

ACLOCAL_AMFLAGS = -I build ${ACLOCAL_FLAGS}
DISTCHECK_CONFIGURE_FLAGS = --enable-warnings=fatal

if MAINTAINER_MODE
src_subdirs = codegen libvte/src
else
src_subdirs =
endif

if ENABLE_DOCUMENTATION
doc_subdirs = docs
else
doc_subdirs =
endif

SUBDIRS = $(src_subdirs) libvte/libvtemm $(doc_subdirs) examples

include $(srcdir)/old_news_and_changelogs/filelist.am

text_files = 			\
	COPYING.examples 	\
	HACKING

old_news = $(addprefix old_news_and_changelogs/,$(news_files))
old_changelogs = $(addprefix old_news_and_changelogs/,$(changelog_files))

dist_noinst_DATA = 		\
	$(text_files) 		\
	$(old_news) 		\
	$(old_changelogs)

dist_noinst_SCRIPTS = autogen.sh

libvtemm_includedir = $(includedir)/$(LIBVTEMM_MODULE_NAME)
libvtemm_include_HEADERS = libvte/libvtemm.h
libvtemm_libincludedir = $(libdir)/$(LIBVTEMM_MODULE_NAME)/include
nodist_libvtemm_libinclude_HEADERS = libvte/libvtemmconfig.h

pkgconfigdir = $(libdir)/pkgconfig
nodist_pkgconfig_DATA = libvte/$(LIBVTEMM_MODULE_NAME).pc

include $(top_srcdir)/build/dist-changelog.am
