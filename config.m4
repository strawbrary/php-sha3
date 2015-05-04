PHP_ARG_ENABLE(sha3,
[Whether to enable SHA3 support],
[--enable-sha3           Enable SHA3 support])

if test "$PHP_SHA3" != "no"; then
    PHP_NEW_EXTENSION(sha3, php_sha3.c KeccakHash.c KeccakSponge.c KeccakF-1600-reference.c SnP-FBWL-default.c displayIntermediateValues.c, $ext_shared)
fi