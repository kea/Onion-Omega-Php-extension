#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"

#include "pwm-exp.h"
#include "php_pwm.h"

#define PHP_PWM_FREQUENCY_DEFAULT   50.0f
#define PHP_PWM_FREQUENCY_MIN       24.0f
#define PHP_PWM_FREQUENCY_MAX       1526.0f
#define PHP_PULSE_TOTAL_COUNT       4096
#define PHP_PWM_EXP_NUM_CHANNELS    16

// Setting verbosity
ZEND_BEGIN_ARG_INFO(arginfo_onionSetVerbosity, 0)
    ZEND_ARG_INFO(0, integer)
ZEND_END_ARG_INFO();

phpOnionSetVerbosity(long verbosity)
{
    onionSetVerbosity(verbosity);
}

PHP_FUNCTION(onionSetVerbosity)
{
    long verbosity;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &verbosity) == FAILURE)
    {
        RETURN_FALSE;
    }

    phpOnionSetVerbosity(verbosity);
}

// Driver init
int phpPwmDriverInit()
{
    int status;

    status = pwmDriverInit ();

    return status;
}

PHP_FUNCTION(pwmDriverInit)
{
    RETURN_LONG(phpPwmDriverInit());
}

// Check init
ZEND_BEGIN_ARG_INFO(arginfo_pwmCheckInit, 0)
    ZEND_ARG_INFO(1, bInit)
ZEND_END_ARG_INFO();

int phpPwmCheckInit(zval *bInit)
{
    int status;
    int bInitTmp;

    status = pwmCheckInit (&bInitTmp);
    Z_LVAL_P(bInit) = bInitTmp;

    return status;
}

PHP_FUNCTION(pwmCheckInit)
{
    zval *bInit;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &bInit) == FAILURE)
    {
        RETURN_FALSE;
    }

    RETURN_LONG(phpPwmCheckInit(bInit));
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
    RETURN_LONG(phpPwmDisableChip());
}

// program the prescale value for desired pwm frequency
ZEND_BEGIN_ARG_INFO(arginfo_pwmSetFrequency, 0)
    ZEND_ARG_INFO(1, float)
ZEND_END_ARG_INFO();

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

    RETURN_LONG(phpPwmSetFrequency(freq));
}

// perform PWM driver setup based on duty and delay
ZEND_BEGIN_ARG_INFO(arginfo_pwmSetupDriver, 0)
    ZEND_ARG_INFO(1, int)
    ZEND_ARG_INFO(1, float)
    ZEND_ARG_INFO(1, float)
ZEND_END_ARG_INFO();

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

    RETURN_LONG(phpPwmSetupDriver(driverNum, duty, delay));
}

zend_function_entry pwm_functions[] =
{
    ZEND_FE(onionSetVerbosity,arginfo_onionSetVerbosity)
    ZEND_FE(pwmCheckInit,arginfo_pwmCheckInit)
    ZEND_FE(pwmDriverInit,NULL)
    ZEND_FE(pwmDisableChip,NULL)
    ZEND_FE(pwmSetFrequency,arginfo_pwmSetFrequency)
    ZEND_FE(pwmSetupDriver,arginfo_pwmSetupDriver)
    {NULL,NULL,NULL} /* Marks the end of function entries */
};

/* {{{ PHP_MINIT_FUNCTION */
static PHP_MINIT_FUNCTION(pwm)
{
    REGISTER_DOUBLE_CONSTANT("PWM_FREQUENCY_DEFAULT", PHP_PWM_FREQUENCY_DEFAULT, CONST_CS|CONST_PERSISTENT);
    REGISTER_DOUBLE_CONSTANT("PWM_FREQUENCY_MIN", PHP_PWM_FREQUENCY_MIN, CONST_CS|CONST_PERSISTENT);
    REGISTER_DOUBLE_CONSTANT("PWM_FREQUENCY_MAX", PHP_PWM_FREQUENCY_MAX, CONST_CS|CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("PWM_EXP_NUM_CHANNELS", PHP_PWM_EXP_NUM_CHANNELS, CONST_CS|CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("PULSE_TOTAL_COUNT", PHP_PULSE_TOTAL_COUNT, CONST_CS|CONST_PERSISTENT);

    return SUCCESS;
}
/* }}} */

/* {{{ pwm_module_entry
 */
zend_module_entry pwm_module_entry = {
    STANDARD_MODULE_HEADER,
    "pwm",
    pwm_functions, /* Function entries */
    PHP_MINIT(pwm), /* Module init */
    NULL, /* Module shutdown */
    NULL, /* Request init */
    NULL, /* Request shutdown */
    NULL, /* Module information */
    "0.3", /* Replace with version number for your extension */
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PWM
ZEND_GET_MODULE(pwm)
#endif
