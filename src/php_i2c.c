#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "ext/standard/php_array.h"

#include "php_i2c.h"

// generic function to write a buffer to the i2c bus
PHP_FUNCTION(i2cWriteBuffer)
{ /*
    int devNum;
    int devAddr;
    int addr;
    int size;
    int pos;
    int status;
    zval *buffer, *entry;
    int numBytes;
    uint8_t *tmpBuffer;
    zend_ulong num_idx;
    char *str_idx;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lllal", &devNum, &devAddr, &addr, &buffer, &size) == FAILURE)
    {
        RETURN_FALSE;
    }

    tmpBuffer = malloc(zend_hash_num_elements(Z_ARRVAL_P(buffer)) * sizeof *tmpBuffer);

    pos = 0;
    ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(buffer), num_idx, str_idx, entry) {
        ZVAL_DEREF(entry);
            if (!str_idx) {
                (tmpBuffer+pos) = Z_LVAL_P(entry);
            }
        }
    } ZEND_HASH_FOREACH_END();

    status = i2c_writeBuffer(devNum, devAddr, addr, tmpBuffer, size));

    free(tmpBuffer);

    RETURN_INT(status); */
    RETURN_INT(0);
}

// write n bytes to the i2c bus
PHP_FUNCTION(i2cWrite)
{
    int devNum;
    int devAddr;
    int addr;
    int val;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &devNum, &devAddr, &addr, &val) == FAILURE)
    {
        RETURN_FALSE;
    }

    RETURN_INT(i2c_write(devNum, devAddr, addr, val));
}

// write a specified number of bytes to the i2c bus
PHP_FUNCTION(i2cWriteBytes)
{
    int devNum;
    int devAddr;
    int addr;
    int val;
    int numBytes;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &devNum, &devAddr, &addr, &val, &numBytes) == FAILURE)
    {
        RETURN_FALSE;
    }

    RETURN_INT(i2c_writeBytes(devNum, devAddr, addr, val, numBytes));
}

// read a byte from the i2c bus
PHP_FUNCTION(i2cRead)
{ /*
    int devNum;
    int devAddr;
    int addr;
    int pos;
    zval *buffer, *entry;
    int numBytes;
    uint8_t *tmpBuffer;
    zend_ulong num_idx;
    zend_string *str_idx;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lllal", &devNum, &devAddr, &addr, &buffer, &numBytes) == FAILURE)
    {
        RETURN_FALSE;
    }

    tmpBuffer = malloc(zend_hash_num_elements(Z_ARRVAL_P(buffer)) * sizeof *tmpBuffer);

    pos = 0;
    ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(buffer), num_idx, str_idx, entry) {
        ZVAL_DEREF(entry);
            if (!str_idx) {
                (tmpBuffer+pos) = Z_LVAL_P(entry);
            }
        }
    } ZEND_HASH_FOREACH_END();

    status = i2c_read(devNum, devAddr, addr, tmpBuffer, numBytes);
    free(tmpBuffer);

    RETURN_INT(status); */

    RETURN_INT(0);
}

// read a single byte from the i2c bus
PHP_FUNCTION(i2cReadByte)
{
    int devNum;
    int devAddr;
    int addr;
    zval *val;
    int tmpVal;
    int status;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lllz", &devNum, &devAddr, &addr, &val) == FAILURE)
    {
        RETURN_FALSE;
    }

    status = i2c_readByte(devNum, devAddr, addr, &tmpVal);
    Z_LVAL_P(val) = tmpVal;

    RETURN_INT(status);
}



