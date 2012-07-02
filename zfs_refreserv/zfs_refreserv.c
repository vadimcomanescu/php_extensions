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
#include "php_zfs_refreserv.h"

/* If you declare any globals in php_zfs_refreserv.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(zfs_refreserv)
*/

/* True global resources - no need for thread safety here */
static int le_zfs_refreserv;

/* {{{ zfs_refreserv_functions[]
 *
 * Every user visible function must have an entry in zfs_refreserv_functions[].
 */
const zend_function_entry zfs_refreserv_functions[] = {
	PHP_FE(zfs_refreservation,	NULL)
	PHP_FE_END	/* Must be the last line in zfs_refreserv_functions[] */
};
/* }}} */

/* {{{ zfs_refreserv_module_entry
 */
zend_module_entry zfs_refreserv_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"zfs_refreserv",
	zfs_refreserv_functions,
	PHP_MINIT(zfs_refreserv),
	PHP_MSHUTDOWN(zfs_refreserv),
	PHP_RINIT(zfs_refreserv),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(zfs_refreserv),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(zfs_refreserv),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_ZFS_REFRESERV
ZEND_GET_MODULE(zfs_refreserv)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("zfs_refreserv.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_zfs_refreserv_globals, zfs_refreserv_globals)
    STD_PHP_INI_ENTRY("zfs_refreserv.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_zfs_refreserv_globals, zfs_refreserv_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_zfs_refreserv_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_zfs_refreserv_init_globals(zend_zfs_refreserv_globals *zfs_refreserv_globals)
{
	zfs_refreserv_globals->global_value = 0;
	zfs_refreserv_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(zfs_refreserv)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(zfs_refreserv)
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
PHP_RINIT_FUNCTION(zfs_refreserv)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(zfs_refreserv)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(zfs_refreserv)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "zfs_refreserv support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_zfs_refreserv_compiled(string arg)
   Return a string to confirm that the module is compiled in */

PHP_FUNCTION(zfs_refreservation)
{
	long n=15;
	RETURN_LONG(n);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
