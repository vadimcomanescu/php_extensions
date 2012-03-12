dnl $Id$
dnl config.m4 for extension util

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(util, for util support,
dnl Make sure that the comment is aligned:
dnl [  --with-util             Include util support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(util, whether to enable util support,
dnl Make sure that the comment is aligned:
dnl [  --enable-util           Enable util support])
PHP_ARG_ENABLE(util, wheter to enable util suppport,
[  --enable-util	Enable util support])
if test "$PHP_UTIL" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-util -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/util.h"  # you most likely want to change this
  dnl if test -r $PHP_UTIL/$SEARCH_FOR; then # path given as parameter
  dnl   UTIL_DIR=$PHP_UTIL
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for util files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       UTIL_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$UTIL_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the util distribution])
  dnl fi

  dnl # --with-util -> add include path
  dnl PHP_ADD_INCLUDE($UTIL_DIR/include)

  dnl # --with-util -> check for lib and symbol presence
  dnl LIBNAME=util # you may want to change this
  dnl LIBSYMBOL=util # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $UTIL_DIR/lib, UTIL_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_UTILLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong util lib version or lib not found])
  dnl ],[
  dnl   -L$UTIL_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(UTIL_SHARED_LIBADD)
  AC_DEFINE(HAVE_UTIL, 1,[Whether Util is present]) 
  PHP_NEW_EXTENSION(util, util.c, $ext_shared)
fi
