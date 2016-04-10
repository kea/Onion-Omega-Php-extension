#ifndef PHP_OLED_H
#define PHP_OLED_H

#include "php.h"
#include "oled-exp.h"

PHP_FUNCTION(oledCheckInit);
PHP_FUNCTION(oledDriverInit);
PHP_FUNCTION(oledClear);
PHP_FUNCTION(oledSetDisplayPower);
PHP_FUNCTION(oledSetDisplayMode);
PHP_FUNCTION(oledSetBrightness);
PHP_FUNCTION(oledSetDim);
PHP_FUNCTION(oledSetMemoryMode);
PHP_FUNCTION(oledSetCursor);
PHP_FUNCTION(oledSetColumnAddressing);
PHP_FUNCTION(oledWriteChar);
PHP_FUNCTION(oledWrite);
PHP_FUNCTION(oledDrawFromFile);
PHP_FUNCTION(oledScroll);
PHP_FUNCTION(oledScrollDiagonal);
PHP_FUNCTION(oledScrollStop);

ZEND_BEGIN_ARG_INFO(arginfo_oledSetDisplayPower, 0)
    ZEND_ARG_INFO(0, bOn)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_oledSetDisplayMode, 0)
    ZEND_ARG_INFO(0, bInvert)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_oledSetBrightness, 0)
    ZEND_ARG_INFO(0, brightness)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_oledSetDim, 0)
    ZEND_ARG_INFO(0, bDim)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_oledSetMemoryMode, 0)
    ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_oledSetCursor, 0)
    ZEND_ARG_INFO(0, row)
    ZEND_ARG_INFO(0, col)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_oledSetColumnAddressing, 0)
    ZEND_ARG_INFO(0, startPixel)
    ZEND_ARG_INFO(0, endPixel)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_oledWriteChar, 0)
    ZEND_ARG_INFO(0, char)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_oledWrite, 0)
    ZEND_ARG_INFO(0, string)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_oledDrawFromFile, 0)
    ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_oledScroll, 0)
    ZEND_ARG_INFO(0, direction)
    ZEND_ARG_INFO(0, scrollSpeed)
    ZEND_ARG_INFO(0, startPage)
    ZEND_ARG_INFO(0, stopPage)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_oledScrollDiagonal, 0)
    ZEND_ARG_INFO(0, direction)
    ZEND_ARG_INFO(0, scrollSpeed)
    ZEND_ARG_INFO(0, fixedRows)
    ZEND_ARG_INFO(0, scrollRows)
    ZEND_ARG_INFO(0, verticalOffset)
    ZEND_ARG_INFO(0, startPage)
    ZEND_ARG_INFO(0, stopPage)
ZEND_END_ARG_INFO();

#endif
