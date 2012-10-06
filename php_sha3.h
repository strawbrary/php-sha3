#ifndef PHP_SHA3_H
#define PHP_SHA3_H

PHP_FUNCTION(sha3);

extern zend_module_entry sha3_module_entry;
#define phpext_sha3_ptr &sha3_module_entry

#endif

/* https://github.com/strawbrary/php-sha3 */