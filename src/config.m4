dnl config.m4 for pwm

PHP_ARG_ENABLE(pwm, whether to enable pwm support,
[  --enable-pwm          Enable pwm support])

if test "$PHP_PWM" != "no"; then

    SEARCH_PATH="$PHP_PWM /usr/local /usr"
    SEARCH_FOR="include/pwm-exp.h"

    AC_MSG_CHECKING([for pwm include files])
    if test -r $PWM_DIR/$SEARCH_FOR; then # path given as parameter
      PWM_DIR=$PWM_DIR
      AC_MSG_RESULT(found in $PWM_DIR)
    else
      for i in $SEARCH_PATH ; do
        if test -r $i/$SEARCH_FOR; then
          PWM_DIR=$i
          AC_MSG_RESULT(found in $i)
        fi
      done
    fi
    if test -z "$PWM_DIR"; then
      AC_MSG_RESULT([not found])
      AC_MSG_ERROR([Please reinstall the libonionpwmexp distribution])
    fi

    PHP_ADD_INCLUDE($PWM_DIR/include)

    LIB_NAME=onionpwmexp
    LIB_SYMBOL=pwmCheckInit

    PHP_CHECK_LIBRARY($LIB_NAME,$LIB_SYMBOL,
    [
      PHP_ADD_LIBRARY_WITH_PATH($LIB_NAME, $PWM_DIR, PWM_SHARED_LIBADD)
      AC_DEFINE(HAVE_PWM,1,[ ])
    ],[
      AC_MSG_ERROR([wrong libonionpwmexp lib version or lib not found])
    ],[
      -L$PWM_DIR/lib -l$LIB_NAME -lonioni2c -loniondebug -lm
    ])

    PHP_SUBST(PWM_SHARED_LIBADD)

    PHP_NEW_EXTENSION(pwm, php_pwm.c, $ext_shared)
    PHP_SUBST(PWM_SHARED_LIBADD)
fi
