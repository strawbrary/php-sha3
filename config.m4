AC_DEFINE(PACKAGE_NAME, "SHA3")
AC_DEFINE(PACKAGE_VERSION, "0.1")

PHP_ARG_ENABLE(sha3,
[Whether to enable SHA3 support],
[--enable-sha3           Enable SHA3 Extension])

if test "$PHP_SHA3" != "no"; then
    PHP_NEW_EXTENSION(sha3, php_sha3.c KeccakNISTInterface.c KeccakSponge.c KeccakF-1600-opt64.c, $ext_shared)
fi