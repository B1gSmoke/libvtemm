## Copyright (c) 2009
## The libvtemm development team.

include $(top_srcdir)/libvte/src/filelist.am
include $(top_srcdir)/libvte/libvtemm/filelist.am

libvtemm_files_h = $(files_built_h) $(filter-out wrap_init.h,$(files_extra_h))

book_name = $(LIBVTEMM_MODULE_NAME)
doc_input = $(addprefix $(top_srcdir)/libvte/libvtemm/,$(libvtemm_files_h))

include $(top_srcdir)/build/doc-reference.am
