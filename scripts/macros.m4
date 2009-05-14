dnl
dnl Some macros needed for autoconf
dnl

dnl AL_PROG_GNU_M4(ACTION_NOT_FOUND)
dnl  Check for GNU m4.  (sun won't do.)
dnl
AC_DEFUN([AL_PROG_GNU_M4],
[
AC_CHECK_PROGS(M4, gm4 m4, no)

if test "x$M4" = "xno"
then
	AC_MSG_RESULT(no)
	$1
fi
if test "$M4" = "m4"
then
	AC_MSG_CHECKING(whether m4 is GNU m4)
	if $M4 --version 2>/dev/null | grep -i 'GNU m4' >/dev/null
	then
		AC_MSG_RESULT(yes)
	else
		AC_MSG_RESULT(no)
		if test "$host_vendor" = "sun"
		then
			$1
		fi
	fi
fi
])

dnl AL_PROG_PERL(ACTION_NOT_FOUND)
dnl   Check for perl
dnl   And set PERL_PATH
dnl
AC_DEFUN([AL_PROG_PERL],
[
AC_PATH_PROG(PERL_PATH, perl, no)
if test "$PERL_PATH" = "no"
then
	AC_PATH_PROG(PERL_PATH, perl5, no)
	if test "$PERL_PATH" = "no"
	then
		$1
	fi
fi
AC_SUBST(PERL_PATH)
])


dnl AL_PROG_GNU_MAKE(ACTION_NOT_FOUND)
dnl   Check for GNU make (no sun make)
dnl
AC_DEFUN([AL_PROG_GNU_MAKE],
[
AC_MSG_CHECKING(whether make is GNU Make)
if $ac_make --version 2>/dev/null | grep '^GNU Make ' >/dev/null
then
	AC_MSG_RESULT(yes)
else
	AC_MSG_RESULT(no)
	if test "$host_vendor" = "sun"
	then
		$1
	fi
fi
])

dnl AL_ENABLE_REFERENCE()
dnl   Check if we want to build reference
dnl
AC_DEFUN([AL_ENABLE_REFERENCE],
[
	AC_ARG_ENABLE(reference,
	              [AC_HELP_STRING([--enable-reference],
	                              [build the reference documentation [default=yes]])],
	              [],
	              [enable_reference=yes])
	AM_CONDITIONAL(BUILD_REFERENCE, test "x$enable_reference" = "xyes")
])

dnl AL_ENABLE_USE_DEPRECATIONS()
dnl   Check if we want to warn about using deprecated API
dnl
AC_DEFUN([AL_ENABLE_USE_DEPRECATIONS],
[
	AC_ARG_ENABLE(use_deprecations,
	              [AC_HELP_STRING([--enable-use-deprecations],
	                              [warn about deprecated usages [default=no]])],
	              [],
	              [enable_deprecations=no])
	
	if test "x$enable_use_deprecations" = "xyes"
	then
		DISABLE_DEPRECATED_CFLAGS="\
-DG_DISABLE_DEPRECATED \
-DGDK_DISABLE_DEPRECATED \
-DGTK_DISABLE_DEPRECATED \
-DGDK_PIXBUF_DISABLE_DEPRECATED \
-DGNOME_DISABLE_DEPRECATED \
-DVTE_DISABLE_DEPRECATED"
		AC_SUBST([DISABLE_DEPRECATED_CFLAGS])
	fi
])

dnl AL_ENABLE_DEPRECATED_API()
dnl   Check if we want to build and include deprecated API
dnl
AC_DEFUN([AL_ENABLE_DEPRECATED_API],
[
	AC_ARG_ENABLE(deprecated-api,
	              [AC_HELP_STRING([--enable-deprecated-api],
	                              [include (build) deprecated API in the libraries [default=yes]])],
	              [],
	              [enable_deprecated_api=yes])
	if test "x$enable_deprecated_api" = "xyes"
	then
		AC_MSG_WARN([Deprecated API will be built, for backwards-compatibility.])
		LIBVTEMM_DISABLE_DEPRECATED_DEF="/* #undef LIBVTEMM_DISABLE_DEPRECATED */"
	else
		AC_DEFINE(LIBVTEMM_DISABLE_DEPRECATED, 1, [Whether not to build deprecated API in libvtemm])
		LIBVTEMM_DISABLE_DEPRECATED_DEF="#define LIBVTEMM_DISABLE_DEPRECATED 1"
		DISABLE_DEPRECATED_API_CFLAGS="-DLIBVTEMM_DISABLE_DEPRECATED"
		AC_SUBST([DISABLE_DEPRECATED_API_CFLAGS])
		AC_MSG_WARN([Deprecated API will not be built, breaking backwards-compatibility. Do not use this build for distribution packages.])
	fi
	AC_SUBST([LIBVTEMM_DISABLE_DEPRECATED_DEF])
])

dnl AL_CHECK_FOR_WIN32()
dnl   Check if we are building on win32 platform
dnl
AC_DEFUN([AL_CHECK_FOR_WIN32],
[
	AC_MSG_CHECKING([for some Win32 platform])
	case "$host" in
	  *-*-mingw*|*-*-cygwin*)
	    platform_win32=yes
	    ;;
	  *)
	    platform_win32=no
	    ;;
	esac
	AC_MSG_RESULT([$platform_win32])
	AM_CONDITIONAL(PLATFORM_WIN32, test "$platform_win32" = "yes")

	AC_MSG_CHECKING([for native Win32])
	case "$host" in
	  *-*-mingw*)
	    os_win32=yes
	    ;;
	  *)
	    os_win32=no
	    ;;
	esac
	AC_MSG_RESULT([$os_win32])
	AM_CONDITIONAL(OS_WIN32, test "$os_win32" = "yes")
])

dnl AL_DOXYGEN_INPUT_SUBDIRS(list of src subdirectories)
dnl   Add directories for input to doxygen
dnl     Stolen from gtkmm and a bit modified
AC_DEFUN([AL_DOXYGEN_INPUT_SUBDIRS],
[
PACKAGEMM_DOXYGEN_INPUT=
packagemm_srcdir=`cd "$srcdir" >/dev/null && pwd`

packagemm_list="$@"
for packagemm_sublib in $packagemm_list
do
  PACKAGEMM_DOXYGEN_INPUT="$PACKAGEMM_DOXYGEN_INPUT ${packagemm_srcdir}/src/${packagemm_sublib}/"
done

AC_SUBST(PACKAGEMM_DOXYGEN_INPUT)
])


