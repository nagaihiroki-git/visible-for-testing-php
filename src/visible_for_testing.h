#ifndef VISIBLE_FOR_TESTING_H
#define VISIBLE_FOR_TESTING_H

extern zend_module_entry visible_for_testing_module_entry;
#define phpext_visible_for_testing_ptr &visible_for_testing_module_entry

#define PHP_VISIBLE_FOR_TESTING_VERSION "0.1.0"

#if defined(ZTS) && defined(COMPILE_DL_VISIBLE_FOR_TESTING)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif /* VISIBLE_FOR_TESTING_H */
