#ifndef PHP_VISIBLE_FOR_TESTING_H
#define PHP_VISIBLE_FOR_TESTING_H

extern zend_module_entry visible_for_testing_module_entry;
#define phpext_visible_for_testing_ptr &visible_for_testing_module_entry

#define PHP_VISIBLE_FOR_TESTING_VERSION "0.1.0"

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_BEGIN_MODULE_GLOBALS(visible_for_testing)
    zend_bool testing_mode;
ZEND_END_MODULE_GLOBALS(visible_for_testing)

#define VISIBLE_FOR_TESTING_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(visible_for_testing, v)

#if defined(ZTS) && defined(COMPILE_DL_VISIBLE_FOR_TESTING)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif /* PHP_VISIBLE_FOR_TESTING_H */
