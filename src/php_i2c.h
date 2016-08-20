#ifndef PHP_I2C_H
#define PHP_I2C_H

#include "php.h"
#include "onion-i2c.h"

PHP_FUNCTION(i2cWriteBuffer);
PHP_FUNCTION(i2cWrite);
PHP_FUNCTION(i2cWriteBytes);
PHP_FUNCTION(i2cRead);
PHP_FUNCTION(i2cReadByte);

ZEND_BEGIN_ARG_INFO(arginfo_i2cWriteBuffer, 0)
    ZEND_ARG_INFO(1, devNum)
    ZEND_ARG_INFO(1, devAddr)
    ZEND_ARG_INFO(1, addr)
    ZEND_ARG_INFO(1, buffer)
    ZEND_ARG_INFO(1, size)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_i2cWrite, 0)
    ZEND_ARG_INFO(1, devNum)
    ZEND_ARG_INFO(1, devAddr)
    ZEND_ARG_INFO(1, addr)
    ZEND_ARG_INFO(1, val)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_i2cWriteBytes, 0)
    ZEND_ARG_INFO(1, devNum)
    ZEND_ARG_INFO(1, devAddr)
    ZEND_ARG_INFO(1, addr)
    ZEND_ARG_INFO(1, val)
    ZEND_ARG_INFO(1, numBytes)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_i2cRead, 0)
    ZEND_ARG_INFO(1, devNum)
    ZEND_ARG_INFO(1, devAddr)
    ZEND_ARG_INFO(1, addr)
    ZEND_ARG_INFO(1, buffer)
    ZEND_ARG_INFO(1, numBytes)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_i2cReadByte, 0)
    ZEND_ARG_INFO(1, devNum)
    ZEND_ARG_INFO(1, devAddr)
    ZEND_ARG_INFO(1, addr)
    ZEND_ARG_INFO(1, val)
ZEND_END_ARG_INFO();

#endif
