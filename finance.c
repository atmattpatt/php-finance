/*
   +----------------------------------------------------------------------+
   | MIT License                                                          |
   +----------------------------------------------------------------------+
   +----------------------------------------------------------------------+
*/

#include "php_finance.h"
#include <math.h>

#if HAVE_FINANCE

/* {{{ finance_functions[] */
zend_function_entry finance_functions[] = {
	PHP_FE(finance_simple_interest, NULL)
	PHP_FE(finance_effective_rate, NULL)
	PHP_FE(finance_nominal_rate, NULL)
	PHP_FE(finance_pv, NULL)
	PHP_FE(finance_fv, NULL)
	{ NULL, NULL, NULL }
};
/* }}} */


/* {{{ finance_module_entry
 */
zend_module_entry finance_module_entry = {
	STANDARD_MODULE_HEADER,
	"finance",
	finance_functions,
	PHP_MINIT(finance),     /* Replace with NULL if there is nothing to do at php startup   */ 
	PHP_MSHUTDOWN(finance), /* Replace with NULL if there is nothing to do at php shutdown  */
	PHP_RINIT(finance),     /* Replace with NULL if there is nothing to do at request start */
	PHP_RSHUTDOWN(finance), /* Replace with NULL if there is nothing to do at request end   */
	PHP_MINFO(finance),
	PHP_FINANCE_VERSION, 
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_FINANCE
ZEND_GET_MODULE(finance)
#endif


/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(finance)
{

	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(finance)
{

	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(finance)
{
	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_RSHUTDOWN_FUNCTION */
PHP_RSHUTDOWN_FUNCTION(finance)
{
	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(finance)
{
	php_printf("The unknown extension\n");
	php_info_print_table_start();
	php_info_print_table_row(2, "Version",PHP_FINANCE_VERSION " (devel)");
	php_info_print_table_row(2, "Released", "2014-01-09");
	php_info_print_table_row(2, "CVS Revision", "$Id: $");
	php_info_print_table_end();
	/* add your stuff here */

}
/* }}} */

PHP_FUNCTION(finance_simple_interest)
{
	double pv, fv, rate;
	int time;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddl", &pv, &rate, &time) == FAILURE) {
		return;
	}

	fv = pv * rate * (double) time;

	RETURN_DOUBLE(fv);
}

PHP_FUNCTION(finance_effective_rate)
{
	double nrate, erate;
	int nper;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dl", &nrate, &nper) == FAILURE) {
		return;
	}

	erate = pow((1. + nrate / (double) nper), nper) - 1.;

	RETURN_DOUBLE(erate);
}

PHP_FUNCTION(finance_nominal_rate)
{
	double erate, nrate;
	int nper;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dl", &erate, &nper) == FAILURE) {
		return;
	}

	nrate = (double) nper * (pow((erate + 1.), (1. / (double) nper)) - 1.);

	RETURN_DOUBLE(nrate);
}

PHP_FUNCTION(finance_pv)
{
	double fv, pv, rate, per;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd", &fv, &rate, &per) == FAILURE) {
		return;
	}

	pv = fv / pow((1 + rate), per);
	
	RETURN_DOUBLE(pv);
}

PHP_FUNCTION(finance_fv)
{
	double pv, fv, rate, per;
	int nper = 1;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd|l", &pv, &rate, &per, &nper) == FAILURE) {
		return;
	}

	fv = pv * pow((1. + rate / (double) nper), ((double) nper * per));

	RETURN_DOUBLE(fv);
}

#endif /* HAVE_FINANCE */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
