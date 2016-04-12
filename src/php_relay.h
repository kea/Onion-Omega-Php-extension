#ifndef PHP_RELAY_H
#define PHP_RELAY_H

#include "php.h"
#include "relay-exp.h"

PHP_FUNCTION(relayDriverInit);
PHP_FUNCTION(relayCheckInit);
PHP_FUNCTION(relaySetChannel);
PHP_FUNCTION(relaySetAllChannels);

ZEND_BEGIN_ARG_INFO(arginfo_relayDriverInit, 0)
    ZEND_ARG_INFO(0, addr)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_relayCheckInit, 0)
    ZEND_ARG_INFO(0, addr)
    ZEND_ARG_INFO(0, bInitialized)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_relaySetChannel, 0)
    ZEND_ARG_INFO(0, addr)
    ZEND_ARG_INFO(0, channel)
    ZEND_ARG_INFO(0, state)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO(arginfo_relaySetAllChannels, 0)
    ZEND_ARG_INFO(0, addr)
    ZEND_ARG_INFO(0, state)
ZEND_END_ARG_INFO();

#endif
