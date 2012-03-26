/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id: header 321634 2012-01-01 13:15:04Z felipe $ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_util.h"

/* If you declare any globals in php_util.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(util)
*/

/* True global resources - no need for thread safety here */
static int le_util;

/* {{{ util_functions[]
 *
 * Every user visible function must have an entry in util_functions[].
 */
zend_function_entry util_functions[] = { /* {{{ */
	PHP_FE(fibonacci,	NULL)
	PHP_FE(hexencode,	NULL)
	PHP_FE(hexdecode,	NULL)
	PHP_FE_END	/* Must be the last line in util_functions[] */
};
/* }}} */

/* {{{ util_module_entry
 */
zend_module_entry util_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"util",
	util_functions,
	PHP_MINIT(util),
	PHP_MSHUTDOWN(util),
	NULL,		/* Replace with NULL if there's nothing to do at request start */
	NULL,	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(util),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_UTIL
ZEND_GET_MODULE(util)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("util.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_util_globals, util_globals)
    STD_PHP_INI_ENTRY("util.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_util_globals, util_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_util_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_util_init_globals(zend_util_globals *util_globals)
{
	util_globals->global_value = 0;
	util_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
/* }}} */
PHP_MINIT_FUNCTION(util)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(util)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(util)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(util)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(util)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "util support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

int fib_aux(int n, int next, int result) {
	if(n == 0) { 
		return result;
	}
	return fib_aux(n - 1, next + result, next); 
}

const char *hexchars = "0123456789ABCDEF";
char *hexencode(char *in, int in_length) {
	char * result;
	int i;
	result = (char *) emalloc(2 * in_length + 1);
	for(i = 0; i < in_length; i++) {
		result[2*i] = hexchars[(in[i] & 0x000000f0) >> 4];
		result[2*i + 1] = hexchars[in[i] & 0x0000000f];
	}
	result[2*in_length] = '\0';
	return result;
}

static __inline__ int char2hex(char a) {
	return (a >= 'A' && a <= 'F')? ( a - 'A' + 10 ):( a - '0'); 
}

char *hexdecode(char *in, int in_length) {
	char *result; 
	int i;
	result = (char *) emalloc(in_length/2 + 1); 
	for(i = 0; i < in_length/2; i++) {
		result[i] = char2hex(in[2 * i]) * 16 + char2hex(in[2 * i + 1]); 
	}
	result[in_length/2] = '\0';
	return result;
}

PHP_FUNCTION(fibonacci) {
	long n;
	long retval;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &n) == FAILURE) {
		return; 
	}
	if(n < 0) {
		zend_error(E_WARNING, "Argument must be a positive integer"); RETURN_FALSE;
	}
	retval = fib_aux(n, 1, 0); RETURN_LONG(retval);
}

PHP_FUNCTION(hexencode) {
	char *in;
	char *out;
	int in_length;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &in, &in_length) == FAILURE) {
		return;
	}
	out = hexencode(in, in_length);
	RETURN_STRINGL(out, in_length * 2, 0);
}

PHP_FUNCTION(hexdecode) {
	char *in;
	char *out;
	int in_length;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &in, &in_length) == FAILURE) {
		return;
	}
	out = hexdecode(in, in_length);
	RETURN_STRINGL(out, in_length/2 + 1, 0);
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
