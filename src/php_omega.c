#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"

#include "php_omega.h"
#include "php_pwm.h"

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

zend_function_entry omega_functions[] =
{
    ZEND_FE(onionSetVerbosity, arginfo_onionSetVerbosity)

    ZEND_FE(pwmCheckInit, arginfo_pwmCheckInit)
    ZEND_FE(pwmDriverInit, NULL)
    ZEND_FE(pwmDisableChip, NULL)
    ZEND_FE(pwmSetFrequency, arginfo_pwmSetFrequency)
    ZEND_FE(pwmSetupDriver, arginfo_pwmSetupDriver)

    {NULL,NULL,NULL} /* Marks the end of function entries */
};


/* {{{ PHP_MINIT_FUNCTION */
static PHP_MINIT_FUNCTION(omega)
{
    REGISTER_LONG_CONSTANT("ONION_VERBOSITY_NONE", ONION_VERBOSITY_NONE, CONST_CS|CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("ONION_VERBOSITY_NORMAL", ONION_VERBOSITY_NORMAL, CONST_CS|CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("ONION_VERBOSITY_VERBOSE", ONION_VERBOSITY_VERBOSE, CONST_CS|CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("ONION_VERBOSITY_EXTRA_VERBOSE", ONION_VERBOSITY_EXTRA_VERBOSE, CONST_CS|CONST_PERSISTENT);

    REGISTER_DOUBLE_CONSTANT("PWM_FREQUENCY_DEFAULT", PHP_PWM_FREQUENCY_DEFAULT, CONST_CS|CONST_PERSISTENT);
    REGISTER_DOUBLE_CONSTANT("PWM_FREQUENCY_MIN", PHP_PWM_FREQUENCY_MIN, CONST_CS|CONST_PERSISTENT);
    REGISTER_DOUBLE_CONSTANT("PWM_FREQUENCY_MAX", PHP_PWM_FREQUENCY_MAX, CONST_CS|CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("PWM_EXP_NUM_CHANNELS", PHP_PWM_EXP_NUM_CHANNELS, CONST_CS|CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("PULSE_TOTAL_COUNT", PHP_PULSE_TOTAL_COUNT, CONST_CS|CONST_PERSISTENT);

    return SUCCESS;
}
/* }}} */

/* {{{ omega_module_entry
 */
zend_module_entry omega_module_entry = {
    STANDARD_MODULE_HEADER,
    "omega",
    omega_functions, /* Function entries */
    PHP_MINIT(omega), /* Module init */
    NULL, /* Module shutdown */
    NULL, /* Request init */
    NULL, /* Request shutdown */
    NULL, /* Module information */
    "0.4", /* Replace with version number for your extension */
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_OMEGA
ZEND_GET_MODULE(omega)
#endif
