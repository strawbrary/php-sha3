#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "ext/hash/php_hash.h"
#include "KeccakHash.h"
#include "php_sha3.h"

#define PHP_SHA3_NAME "sha3"
#define PHP_SHA3_VERSION "0.2.0"
#define PHP_SHA3_STANDARD_VERSION "FIPS 202"

zend_function_entry sha3_functions[] = {
    PHP_FE(sha3, NULL)
    PHP_FE_END
};

PHP_MINFO_FUNCTION(sha3)
{
    php_info_print_table_start();
    php_info_print_table_row(2, "sha3 support", "enabled");
    php_info_print_table_row(2, "extension version",  PHP_SHA3_VERSION);
    php_info_print_table_row(2, "standard version", PHP_SHA3_STANDARD_VERSION);
    php_info_print_table_end();
}

zend_module_entry sha3_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_SHA3_NAME,
    sha3_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    PHP_MINFO(sha3),
#if ZEND_MODULE_API_NO >= 20010901
     PHP_SHA3_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SHA3
ZEND_GET_MODULE(sha3)
#endif

PHP_FUNCTION(sha3)
{
#if ZEND_MODULE_API_NO >= 20151012
    zend_long hashBitLength = 512;
    zend_long hashByteLength;
    size_t dataByteLength;
#else
    long hashBitLength = 512;
    long hashByteLength;
    int dataByteLength;
#endif
    char *data;
    zend_bool rawOutput = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|lb", &data, &dataByteLength, &hashBitLength, &rawOutput) == FAILURE) {
        return;
    }
    
    unsigned int capacity = hashBitLength * 2;
    unsigned int rate = SnP_width - capacity;

    hashByteLength = hashBitLength / 8;
    BitSequence hashVal[hashByteLength];

    Keccak_HashInstance hashInstance;
    HashReturn ret = Keccak_HashInitialize(&hashInstance, rate, capacity, hashBitLength, 0x06);
    
    if (ret != SHA3_SUCCESS) {
        zend_error(E_WARNING, "Unsupported sha3() output length");
        RETURN_FALSE;
    }
    
    Keccak_HashUpdate(&hashInstance, (unsigned char *) data, dataByteLength * 8);
    Keccak_HashFinal(&hashInstance, hashVal);

    if (rawOutput) {
#if ZEND_MODULE_API_NO >= 20151012
        RETVAL_STRINGL((char *)hashVal, hashByteLength);
#else
        RETURN_STRINGL((char *)hashVal, hashByteLength, 1);
#endif
    } else {
        char *hexDigest = safe_emalloc(hashByteLength, 2, 1);

        php_hash_bin2hex(hexDigest, hashVal, hashByteLength);
        hexDigest[2 * hashByteLength] = 0;
#if ZEND_MODULE_API_NO >= 20151012
        RETVAL_STRINGL(hexDigest, hashByteLength * 2);
#else
        RETURN_STRINGL(hexDigest, hashByteLength * 2, 1);
#endif
    }
}
