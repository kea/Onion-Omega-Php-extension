#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"

#include "php_oled.h"

PHP_FUNCTION(oledCheckInit)
{
	int 	status;

	status 	= oledCheckInit();

	RETURN_LONG(status);
}

PHP_FUNCTION(oledDriverInit)
{
	int 	status;

	status 	= oledDriverInit();

	RETURN_LONG(status);
}

PHP_FUNCTION(oledClear)
{
	int 	status;

	status 	= oledClear();

	RETURN_LONG(status);
}

PHP_FUNCTION(oledSetDisplayPower)
{
	int 	status, bOn;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &bOn) == FAILURE)
    {
        RETURN_FALSE;
    }

	status 	= oledSetDisplayPower(bOn);

	RETURN_LONG(status);
}

PHP_FUNCTION(oledSetDisplayMode)
{
	int 	status, bInvert;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &bInvert) == FAILURE)
    {
        RETURN_FALSE;
    }

	status 	= oledSetDisplayMode (bInvert);

	RETURN_LONG(status);
}

PHP_FUNCTION(oledSetBrightness)
{
	int 	status, brightness;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &brightness) == FAILURE)
    {
        RETURN_FALSE;
    }

	status 	= oledSetBrightness(brightness);

	RETURN_LONG(status);
}

PHP_FUNCTION(oledSetDim)
{
	int 	status, bDim;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &bDim) == FAILURE)
    {
        RETURN_FALSE;
    }

	status 	= oledSetDim (bDim);

	RETURN_LONG(status);
}

PHP_FUNCTION(oledSetMemoryMode)
{
	int 	status, mode;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &mode) == FAILURE)
    {
        RETURN_FALSE;
    }

	status 	= oledSetMemoryMode (mode);

	RETURN_LONG(status);
}


PHP_FUNCTION(oledSetCursor)
{
	int 	status, row, col;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &row, &col) == FAILURE)
    {
        RETURN_FALSE;
    }

	status 	= oledSetCursor(row, col);

	RETURN_LONG(status);
}

PHP_FUNCTION(oledSetColumnAddressing)
{
	int 	status, startPixel, endPixel;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &startPixel, &endPixel) == FAILURE)
    {
        RETURN_FALSE;
    }

	status 	= oledSetColumnAddressing(startPixel, endPixel);

	RETURN_LONG(status);
}


PHP_FUNCTION(oledWriteChar)
{
	int status;
    char *msg;
    int msg_len;
	char c;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &msg, &msg_len) == FAILURE)
    {
        RETURN_NULL();
    }
	c 	= (char)msg[0];

	status 	= oledWriteChar(c);

	RETURN_LONG(status);
}

PHP_FUNCTION(oledWrite)
{
	int status;
    char *msg;
    int msg_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &msg, &msg_len) == FAILURE)
    {
        RETURN_NULL();
    }

	status 	= oledWrite((char*)msg);

	RETURN_LONG(status);
}

PHP_FUNCTION(oledDrawFromFile)
{
	int 		status;
	uint8_t		*buffer;
	char 	*filename;
	int filename_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE)
    {
        RETURN_NULL();
    }

	// allocate memory for the buffer
	buffer 	= malloc(OLED_EXP_WIDTH*OLED_EXP_HEIGHT/8 * sizeof *buffer);

	// read LCD data from file
	status 	= oledReadLcdFile ((char*)filename, buffer);

	// draw data onto screen
	status 	= oledDraw (buffer, OLED_EXP_WIDTH*OLED_EXP_HEIGHT/8);


	RETURN_LONG(status);
}

PHP_FUNCTION(oledScroll)
{
	int 	status;
	int 	direction, scrollSpeed, startPage, stopPage;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &direction, &scrollSpeed, &startPage, &stopPage) == FAILURE)
    {
        RETURN_FALSE;
    }

	status 	= oledScroll(direction, scrollSpeed, startPage, stopPage);

	RETURN_LONG(status);
}

PHP_FUNCTION(oledScrollDiagonal)
{
	int 	status;
	int 	direction, scrollSpeed, fixedRows, scrollRows, verticalOffset, startPage, stopPage;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lllllll", &direction, &scrollSpeed, &fixedRows, &scrollRows, &verticalOffset, &startPage, &stopPage) == FAILURE)
    {
        RETURN_FALSE;
    }

	status 	= oledScrollDiagonal(direction, scrollSpeed, fixedRows, scrollRows, verticalOffset, startPage, stopPage);

	RETURN_LONG(status);
}

PHP_FUNCTION(oledScrollStop)
{
	int 	status;

	status 	= oledScrollStop ();

	RETURN_LONG(status);
}
