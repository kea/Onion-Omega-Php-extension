#ifndef PHP_OMEGA_H
#define PHP_OMEGA_H

PHP_FUNCTION(onionSetVerbosity);

ZEND_BEGIN_ARG_INFO(arginfo_onionSetVerbosity, 0)
    ZEND_ARG_INFO(0, verbosity)
ZEND_END_ARG_INFO();

static PHP_MINIT_FUNCTION(omega);

#endif
