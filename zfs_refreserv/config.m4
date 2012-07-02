dnl $Id$
dnl config.m4 for extension zfs_refreserv

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(zfs_refreserv, for zfs_refreserv support,
dnl Make sure that the comment is aligned:
[  --with-zfs_refreserv             Include zfs_refreserv support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(zfs_refreserv, whether to enable zfs_refreserv support,
dnl Make sure that the comment is aligned:
dnl [  --enable-zfs_refreserv           Enable zfs_refreserv support])

if test "$PHP_ZFS_REFRESERV" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-zfs_refreserv -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/zfs_refreserv.h"  # you most likely want to change this
  dnl if test -r $PHP_ZFS_REFRESERV/$SEARCH_FOR; then # path given as parameter
  dnl   ZFS_REFRESERV_DIR=$PHP_ZFS_REFRESERV
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for zfs_refreserv files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       ZFS_REFRESERV_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$ZFS_REFRESERV_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the zfs_refreserv distribution])
  dnl fi

  dnl # --with-zfs_refreserv -> add include path
  dnl PHP_ADD_INCLUDE($ZFS_REFRESERV_DIR/include)

  dnl # --with-zfs_refreserv -> check for lib and symbol presence
  dnl LIBNAME=zfs_refreserv # you may want to change this
  dnl LIBSYMBOL=zfs_refreserv # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $ZFS_REFRESERV_DIR/lib, ZFS_REFRESERV_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_ZFS_REFRESERVLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong zfs_refreserv lib version or lib not found])
  dnl ],[
  dnl   -L$ZFS_REFRESERV_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(ZFS_REFRESERV_SHARED_LIBADD)

  PHP_NEW_EXTENSION(zfs_refreserv, zfs_refreserv.c, $ext_shared)
fi
