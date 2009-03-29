#!/bin/sh

dir=`echo "$0" | sed 's,[^/]*$,,'`
test "x${dir}" = "x" && dir='.'
if test "x`cd "${dir}" 2>/dev/null && pwd`" != "x`pwd`"
then
	echo "autogen.sh must be executed from it's directory."
	exit 1
fi

echo "Running autoreconf."
autoreconf -v -i -s || exit $?
echo "Running configure."
./configure "$@" || exit $?
echo
echo 'run "make"'
echo
