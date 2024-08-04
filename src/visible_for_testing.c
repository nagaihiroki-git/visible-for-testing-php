#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_visible_for_testing.h"

ZEND_DECLARE_MODULE_GLOBALS(visible_for_testing)

PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("visible_for_testing.testing_mode",
     "0",
     PHP_INI_ALL,
     OnUpdateBool,
     testing_mode,
     zend_visible_for_testing_globals,
     visible_for_testing_globals)
PHP_INI_END()

PHP_MINIT_FUNCTION(visible_for_testing)
{
    REGISTER_INI_ENTRIES();
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(visible_for_testing)
{
    UNREGISTER_INI_ENTRIES();
    return SUCCESS;
}

PHP_RINIT_FUNCTION(visible_for_testing)
{
#if defined(ZTS) && defined(COMPILE_DL_VISIBLE_FOR_TESTING)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif
    return SUCCESS;
}

PHP_MINFO_FUNCTION(visible_for_testing)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "visible_for_testing support", "enabled");
    php_info_print_table_end();

    DISPLAY_INI_ENTRIES();
}

const zend_function_entry visible_for_testing_functions[] = {
    PHP_FE_END
};

zend_module_entry visible_for_testing_module_entry = {
    STANDARD_MODULE_HEADER,
    "visible_for_testing",
    visible_for_testing_functions,
    PHP_MINIT(visible_for_testing),
    PHP_MSHUTDOWN(visible_for_testing),
    PHP_RINIT(visible_for_testing),
    NULL,
    PHP_MINFO(visible_for_testing),
    PHP_VISIBLE_FOR_TESTING_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_VISIBLE_FOR_TESTING
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(visible_for_testing)
#endif
