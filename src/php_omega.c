#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"

#include "php_omega.h"
#include "php_pwm.h"
#include "php_oled.h"
#include "php_relay.h"
#include "php_i2c.h"

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

    ZEND_FE(oledCheckInit, NULL)
    ZEND_FE(oledDriverInit, NULL)
    ZEND_FE(oledClear, NULL)
    ZEND_FE(oledSetDisplayPower, arginfo_oledSetDisplayPower)
    ZEND_FE(oledSetDisplayMode, arginfo_oledSetDisplayMode)
    ZEND_FE(oledSetBrightness, arginfo_oledSetBrightness)
    ZEND_FE(oledSetDim, arginfo_oledSetDim)
    ZEND_FE(oledSetMemoryMode, arginfo_oledSetMemoryMode)
    ZEND_FE(oledSetCursor, arginfo_oledSetCursor)
    ZEND_FE(oledSetColumnAddressing, arginfo_oledSetColumnAddressing)
    ZEND_FE(oledWriteChar, arginfo_oledWriteChar)
    ZEND_FE(oledWrite, arginfo_oledWrite)
    ZEND_FE(oledDrawFromFile, arginfo_oledDrawFromFile)
    ZEND_FE(oledScroll, arginfo_oledScroll)
    ZEND_FE(oledScrollDiagonal, arginfo_oledScrollDiagonal)
    ZEND_FE(oledScrollStop, NULL)

    ZEND_FE(relayDriverInit, arginfo_relayDriverInit)
    ZEND_FE(relayCheckInit, arginfo_relayCheckInit)
    ZEND_FE(relaySetChannel, arginfo_relaySetChannel)
    ZEND_FE(relaySetAllChannels, arginfo_relaySetAllChannels)

    ZEND_FE(i2cWriteBuffer, arginfo_i2cWriteBuffer)
    ZEND_FE(i2cWrite, arginfo_i2cWrite)
    ZEND_FE(i2cWriteBytes, arginfo_i2cWriteBytes)
    ZEND_FE(i2cRead, arginfo_i2cRead)
    ZEND_FE(i2cReadByte, arginfo_i2cReadByte)

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
    "0.6", /* Version number */
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_OMEGA
ZEND_GET_MODULE(omega)
#endif
