## Copyright (c) 2009
## The libvtemm development team.

include $(srcdir)/Makefile_defs.am_fragment
# defined:
#  files_defs

include $(srcdir)/Makefile_list_of_hg.am_fragment
# defined:
#  files_hg
#  deprecated_hg

files_ccg = $(files_hg:.hg=.ccg)
deprecated_ccg = $(files_ccg:.h=.ccg)

EXTRA_DIST = $(files_defs) $(files_hg) $(files_ccg) Makefile_defs.am_fragment \
	Makefile_list_of_hg.am_fragment $(deprecated_hg) $(deprecated_ccg)

-include $(top_srcdir)/git.mk
