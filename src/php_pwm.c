#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"

#include "php_pwm.h"

// Driver init
int phpPwmDriverInit()
{
    int status;

    status = pwmDriverInit ();

    return status;
}

PHP_FUNCTION(pwmDriverInit)
{
    RETURN_BOOL(phpPwmDriverInit() != EXIT_FAILURE);
}

int phpPwmCheckInit(zval *bInit)
{
    int status;
    int bInitTmp;

    status = pwmCheckInit (&bInitTmp);
    ZVAL_LONG(bInit, bInitTmp);

    return status;
}

PHP_FUNCTION(pwmCheckInit)
{
    zval bInit;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &bInit) == FAILURE)
    {
        RETURN_FALSE;
    }

    RETURN_BOOL(phpPwmCheckInit(&bInit) != EXIT_FAILURE);
}

// disable the chip - set oscillator to sleep
int phpPwmDisableChip()
{
    int status;

    status = pwmDisableChip ();

    return status;
}

PHP_FUNCTION(pwmDisableChip)
{
    RETURN_BOOL(phpPwmDisableChip() != EXIT_FAILURE);
}

int phpPwmSetFrequency(int freq)
{
    int status;

    status = pwmSetFrequency (freq);

    return status;
}

PHP_FUNCTION(pwmSetFrequency)
{
    double freq;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &freq) == FAILURE)
    {
        RETURN_FALSE;
    }

    RETURN_BOOL(phpPwmSetFrequency(freq) != EXIT_FAILURE);
}

int phpPwmSetupDriver(int driverNum, float duty, float delay)
{
    int status;

    status = pwmSetupDriver (driverNum, duty, delay);

    return status;
}

PHP_FUNCTION(pwmSetupDriver)
{
    long driverNum;
    double duty;
    double delay;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ldd", &driverNum, &duty, &delay) == FAILURE)
    {
        RETURN_FALSE;
    }

    RETURN_BOOL(phpPwmSetupDriver(driverNum, duty, delay) != EXIT_FAILURE);
}
