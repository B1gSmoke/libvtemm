## Copyright (c) 2009
## The libvtemm development team.

SUBDIRS = g private

files_extra_h = wrap_init.h init.h textandcharattrs.h pty.h
files_extra_cc = init.cc textandcharattrs.cc pty.cc

include $(top_srcdir)/build_shared/Makefile_shared.am_fragment
#defined:
# generated_sources_h
# generated_sources_cc
# files_defs_from_g
# tools_m4
# run_gmmproc
# generated_private_headers

# # # #
# should not ever exist, but hack needs to be used
#
#h_p_name = hacky_patch
#run_sed_hack = $(SED) "s;~~~SRC_DIR~~~;$(srcdir);" $(srcdir)/g/$(h_p_name).tmpl >$(srcdir)/$(h_p_name)
#run_patch_hack = $(PATCH) -f -p0 <$(srcdir)/$(h_p_name)
#
# end of "should not ever exist"
# # # #

# # # #
# should be shared, but hack needs to be used
#
#BUILT_SOURCES = $(h_p_name) $(generated_sources_h) $(generated_sources_cc) $(generated_sources_private)
#
#$(srcdir)/private/%_p.h: %.h
#
#%.cc: %.h
#
#%.h: $(srcdir)/g/%.hg $(srcdir)/g/%.ccg $(tools_m4) $(files_defs_from_g) $(srcdir)/$(h_p_name)
#	$(run_gmmproc) $(notdir $*) $(srcdir)/g $(srcdir)
#	if test "x$*" = "xterminal"; then $(run_patch_hack); fi
#
# end of "should be shared"
# # # #

# # # #
# should not ever exist, but hack needs to be used
#
#$(h_p_name): $(srcdir)/g/$(h_p_name).tmpl
#	$(run_sed_hack)
#
# end of "should not ever exist"
# # # #

lib_LTLIBRARIES = libvtemm-1.0.la
libvtemm_1_0_la_SOURCES = $(files_extra_cc) $(generated_sources_cc)
libvtemm_1_0_la_LDFLAGS = $(common_ldflags)
libvtemm_1_0_la_LIBADD = @LIBVTEMM_LIBS@

# # # #
# should be shared, but hack needs to be used
#
#MOSTLYCLEANFILES = $(generated_sources_cc) $(generated_sources_h) $(h_p_name) $(generated_private_headers)
#
# end of "should be shared"
# # # #
