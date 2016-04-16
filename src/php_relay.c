#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"

#include "php_relay.h"

PHP_FUNCTION(relayDriverInit)
{
    int addr;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &addr) == FAILURE)
    {
        RETURN_FALSE;
    }

    RETURN_BOOL(relayDriverInit(addr) != EXIT_FAILURE);
}

int phpRelayCheckInit(int addr, zval *bInitialized)
{
    int status;
    int bInitTmp;

    status = relayCheckInit(addr, &bInitTmp);
    Z_LVAL_P(bInitialized) = bInitTmp;

    return status;
}

PHP_FUNCTION(relayCheckInit)
{
    zval *bInitialized;
    int addr;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lz", &addr, &bInitialized) == FAILURE)
    {
        RETURN_FALSE;
    }

    RETURN_BOOL(phpRelayCheckInit(addr, bInitialized) != EXIT_FAILURE);
}

PHP_FUNCTION(relaySetChannel)
{
    int addr, channel, state;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lll", &addr, &channel, &state) == FAILURE)
    {
        RETURN_FALSE;
    }

    RETURN_BOOL(relaySetChannel(addr, channel, state) != EXIT_FAILURE);
}

PHP_FUNCTION(relaySetAllChannels)
{
    int addr, channel, state;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &addr, &state) == FAILURE)
    {
        RETURN_FALSE;
    }

    RETURN_BOOL(relaySetAllChannels(addr, state) != EXIT_FAILURE);
}
