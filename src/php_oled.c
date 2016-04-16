#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"

#include "php_oled.h"

PHP_FUNCTION(oledCheckInit)
{
	RETURN_BOOL(oledCheckInit() != EXIT_FAILURE);
}

PHP_FUNCTION(oledDriverInit)
{
	RETURN_BOOL(oledDriverInit() != EXIT_FAILURE);
}

PHP_FUNCTION(oledClear)
{
	RETURN_BOOL(oledClear() != EXIT_FAILURE);
}

PHP_FUNCTION(oledSetDisplayPower)
{
	int 	bOn;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &bOn) == FAILURE)
    {
        RETURN_FALSE;
    }

	RETURN_BOOL(oledSetDisplayPower(bOn) != EXIT_FAILURE);
}

PHP_FUNCTION(oledSetDisplayMode)
{
	int 	bInvert;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &bInvert) == FAILURE)
    {
        RETURN_FALSE;
    }

	RETURN_BOOL(oledSetDisplayMode(bInvert) != EXIT_FAILURE);
}

PHP_FUNCTION(oledSetBrightness)
{
	int 	brightness;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &brightness) == FAILURE)
    {
        RETURN_FALSE;
    }

	RETURN_BOOL(oledSetBrightness(brightness) != EXIT_FAILURE);
}

PHP_FUNCTION(oledSetDim)
{
	int 	bDim;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &bDim) == FAILURE)
    {
        RETURN_FALSE;
    }

	RETURN_BOOL(oledSetDim (bDim) != EXIT_FAILURE);
}

PHP_FUNCTION(oledSetMemoryMode)
{
	int 	mode;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &mode) == FAILURE)
    {
        RETURN_FALSE;
    }

	RETURN_BOOL(oledSetMemoryMode(mode) != EXIT_FAILURE);
}


PHP_FUNCTION(oledSetCursor)
{
	int 	status, row, col;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &row, &col) == FAILURE)
    {
        RETURN_FALSE;
    }

	RETURN_BOOL(oledSetCursor(row, col) != EXIT_FAILURE);
}

PHP_FUNCTION(oledSetColumnAddressing)
{
	int 	startPixel, endPixel;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &startPixel, &endPixel) == FAILURE)
    {
        RETURN_FALSE;
    }

	RETURN_BOOL(oledSetColumnAddressing(startPixel, endPixel) != EXIT_FAILURE);
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

	RETURN_BOOL(oledWriteChar(c) != EXIT_FAILURE);
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

	RETURN_BOOL(oledWrite((char*)msg) != EXIT_FAILURE);
}

PHP_FUNCTION(oledDrawFromFile)
{
	uint8_t		*buffer;
	char 	*filename;
	int status, filename_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE)
    {
        RETURN_NULL();
    }

	// allocate memory for the buffer
	buffer 	= malloc(OLED_EXP_WIDTH*OLED_EXP_HEIGHT/8 * sizeof *buffer);

	// read LCD data from file
	status 	= oledReadLcdFile ((char*)filename, buffer);

	RETURN_BOOL(oledDraw(buffer, OLED_EXP_WIDTH*OLED_EXP_HEIGHT/8) != EXIT_FAILURE);
}

PHP_FUNCTION(oledScroll)
{
	int 	direction, scrollSpeed, startPage, stopPage;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &direction, &scrollSpeed, &startPage, &stopPage) == FAILURE)
    {
        RETURN_FALSE;
    }

	RETURN_BOOL(oledScroll(direction, scrollSpeed, startPage, stopPage) != EXIT_FAILURE);
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

	RETURN_BOOL(status != EXIT_FAILURE);
}

PHP_FUNCTION(oledScrollStop)
{
	RETURN_BOOL(oledScrollStop() != EXIT_FAILURE);
}
