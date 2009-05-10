## Copyright (c) 2009
## The libvtemm development team.

include $(srcdir)/../g/Makefile_list_of_hg.am_fragment
# defined:
#  files_hg

generated_sources_private = $(files_hg:.hg=_p.h)
include $(top_srcdir)/src/Makefile_sublib.am_fragment
# defined:
#  sublib_name
#  sublib_libname

private_includedir = $(includedir)/$(sublib_libname)/$(sublib_name)/private
private_include_HEADERS = $(generated_sources_private)


-include $(top_srcdir)/git.mk
