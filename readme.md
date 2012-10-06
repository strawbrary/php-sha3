PHP SHA-3 (Keccak) Extension
============================
This is a PHP extension which is a wrapper for the official implementation of the Keccak hash function, as submitted to the NIST hash function contest and selected to become the official SHA-3 algorithm. SHA-3 is intended to replace older general use hash functions such as SHA-2 and MD5. The algorithm was designed by Guido Bertoni, Joan Daemen, Michaël Peeters and Gilles Van Assche.

Installation
------------
1. git clone https://github.com/strawbrary/php-sha3
1. cd php-sha3
1. phpize
1. ./configure --enable-sha3
1. make && make install
1. Add the following line to your php.ini file

```
extension=sha3.so
```

You may need to restart your httpd to load the extension

Usage
----
```php
string sha3 ( string $str [, int $outputSize = 512, bool $rawOutput = false ] )
```

* $str: The string to hash
* $outputSize: The bit length of the output hash (accepted values: 224, 256, 384, 512)
* $rawOutput: If set to true, then the hash is returned in raw binary format

* Return value: A hex string containing the sha3 hash of the input string

Examples
--------
```php
echo sha3('');
```

0eab42de4c3ceb9235fc91acffe746b29c29a8c366b7c60e4e67c466f36a4304c00fa9caf9d87976ba469bcbe06713b435f091ef2769fb160cdab33d3670680e

```php
echo sha3('', 256);
```

c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470

```php
echo sha3('foobar', 384);
```

e8c02310ada7fbf1c550713cdaa0a3eaf02ee13990f73851e7e5a183f99df541d833424e702e4e22eb4306b7bcbeb965