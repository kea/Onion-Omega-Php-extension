#ifndef PHP_PWM_H
#define PHP_PWM_H

#include "php.h"
#include "pwm-exp.h"

#define PHP_PWM_FREQUENCY_DEFAULT   50.0f
#define PHP_PWM_FREQUENCY_MIN       24.0f
#define PHP_PWM_FREQUENCY_MAX       1526.0f
#define PHP_PULSE_TOTAL_COUNT       4096
#define PHP_PWM_EXP_NUM_CHANNELS    16

PHP_FUNCTION(pwmDriverInit);
PHP_FUNCTION(pwmCheckInit);
PHP_FUNCTION(pwmSetFrequency);
PHP_FUNCTION(pwmSetupDriver);
PHP_FUNCTION(pwmDisableChip);

ZEND_BEGIN_ARG_INFO(arginfo_pwmCheckInit, 0)
    ZEND_ARG_INFO(1, bInit)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_pwmSetFrequency, 0)
    ZEND_ARG_INFO(1, freq)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_pwmSetupDriver, 0)
    ZEND_ARG_INFO(1, driverNum)
    ZEND_ARG_INFO(1, duty)
    ZEND_ARG_INFO(1, delay)
ZEND_END_ARG_INFO();

#endif
