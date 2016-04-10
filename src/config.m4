dnl config.m4 for omega

PHP_ARG_ENABLE(omega, whether to enable omega support,
[  --enable-omega          Enable omega support])

if test "$PHP_OMEGA" != "no"; then

    SEARCH_PATH="$PHP_OMEGA /usr/local /usr"
    SEARCH_FOR="include/pwm-exp.h"

    AC_MSG_CHECKING([for pwm include files])
    if test -r $OMEGA_DIR/$SEARCH_FOR; then # path given as parameter
      OMEGA_DIR=$OMEGA_DIR
      AC_MSG_RESULT(found in $OMEGA_DIR)
    else
      for i in $SEARCH_PATH ; do
        if test -r $i/$SEARCH_FOR; then
          OMEGA_DIR=$i
          AC_MSG_RESULT(found in $i)
        fi
      done
    fi
    if test -z "$OMEGA_DIR"; then
      AC_MSG_RESULT([not found])
      AC_MSG_ERROR([Please reinstall the libonionpwmexp distribution])
    fi

    PHP_ADD_INCLUDE($OMEGA_DIR/include)

    LIB_NAME=onionpwmexp
    LIB_SYMBOL=pwmCheckInit

    PHP_CHECK_LIBRARY($LIB_NAME,$LIB_SYMBOL,
    [
      PHP_ADD_LIBRARY_WITH_PATH($LIB_NAME, $OMEGA_DIR, OMEGA_SHARED_LIBADD)
      AC_DEFINE(HAVE_PWM,1,[ ])
    ],[
      AC_MSG_ERROR([wrong libonionpwmexp lib version or lib not found])
    ],[
      -L$OMEGA_DIR/lib -l$LIB_NAME -lonioni2c -loniondebug -lm
    ])

    LIB_OLED_NAME=onionoledexp
    LIB_OLED_SYMBOL=oledCheckInit

    PHP_CHECK_LIBRARY($LIB_OLED_NAME,$LIB_OLED_SYMBOL,
    [
      PHP_ADD_LIBRARY_WITH_PATH($LIB_OLED_NAME, $OMEGA_DIR, OMEGA_SHARED_LIBADD)
      AC_DEFINE(HAVE_OLED,1,[ ])
    ],[
      AC_MSG_ERROR([wrong libonionoledexp lib version or lib not found])
    ],[
      -L$OMEGA_DIR/lib -l$LIB_OLED_NAME -lonioni2c -loniondebug -lm
    ])

    PHP_NEW_EXTENSION(omega, php_omega.c php_pwm.c php_oled.c, $ext_shared)
    PHP_SUBST(OMEGA_SHARED_LIBADD)
fi
