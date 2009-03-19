include $(srcdir)/Makefile_sublib.am_fragment
# defines:
#  sublib_name
#  sublib_libname

SUBDIRS = $(sublib_name)

EXTRA_DIST = README $(sublib_libname).pc.in $(sublib_name)config.h.in

libvtemm_includedir = $(includedir)/$(sublib_libname)
libvtemm_include_HEADERS = $(sublib_name).h

libvtemm_configdir = $(libdir)/$(sublib_libname)/include
libvtemm_config_DATA = $(sublib_name)config.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = $(sublib_libname).pc

