#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "ext/hash/php_hash.h"
#include "KeccakNISTInterface.h"
#include "php_sha3.h"

zend_function_entry sha3_functions[] = {
    PHP_FE(sha3, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry sha3_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PACKAGE_NAME,
    sha3_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PACKAGE_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SHA3
ZEND_GET_MODULE(sha3)
#endif

PHP_FUNCTION(sha3)
{
    long hashbitlen = 512;
    int hashbytelen;
    BitSequence *data;
    int databytelen;
    zend_bool rawoutput = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|lb", &data, &databytelen, &hashbitlen, &rawoutput) == FAILURE) {
        return;
    }

    hashbytelen = hashbitlen / 8;
    char hashval[hashbytelen];

    HashReturn result = Hash(hashbitlen, data, databytelen * 8, hashval);

    if (result == SHA3_SUCCESS) {
        if (rawoutput) {
            RETURN_STRINGL(hashval, hashbytelen, 1);
        } else {
            char hex[hashbytelen * 2 + 1];
            php_hash_bin2hex(hex, (unsigned char *) hashval, hashbytelen);
            hex[hashbytelen * 2] = '\0';

            RETURN_STRING(hex, 1);
        }
    } else {
        if (result == SHA3_BAD_HASHLEN) {
            zend_error(E_WARNING, "Unsupported sha3() output length");
        }

        RETURN_FALSE;
    }
}
/* https://github.com/strawbrary/php-sha3 */
