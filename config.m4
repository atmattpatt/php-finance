dnl
dnl $ Id: $
dnl

PHP_ARG_ENABLE(finance, whether to enable finance functions,
[  --enable-finance         Enable finance support])

if test "$PHP_FINANCE" != "no"; then
  export OLD_CPPFLAGS="$CPPFLAGS"
  export CPPFLAGS="$CPPFLAGS $INCLUDES -DHAVE_FINANCE"

  AC_MSG_CHECKING(PHP version)
  AC_TRY_COMPILE([#include <php_version.h>], [
#if PHP_VERSION_ID < 40000
#error  this extension requires at least PHP version 4.0.0
#endif
],
[AC_MSG_RESULT(ok)],
[AC_MSG_ERROR([need at least PHP 4.0.0])])

  export CPPFLAGS="$OLD_CPPFLAGS"


  PHP_SUBST(FINANCE_SHARED_LIBADD)
  AC_DEFINE(HAVE_FINANCE, 1, [ ])

  PHP_NEW_EXTENSION(finance, finance.c , $ext_shared)

fi

