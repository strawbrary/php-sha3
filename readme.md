PHP SHA-3 (Keccak) Extension
============================

[![Build Status](https://travis-ci.org/strawbrary/php-sha3.svg?branch=master)](https://travis-ci.org/strawbrary/php-sha3)

This PHP extension is a wrapper for the reference implementation of the SHA-3 (Keccak) hash function. SHA-3 is intended to replace older general use hash functions such as SHA-2 and MD5. The algorithm was designed by Guido Bertoni, Joan Daemen, Michaël Peeters and Gilles Van Assche.

This extension uses the final FIPS 202 standard published on August 5, 2015.

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

You may need to restart your httpd/FPM to load the extension. You can verify it is loaded by looking for sha3 in your phpinfo.

Usage
----
```php
string sha3 ( string $str [, int $outputSize = 512, bool $rawOutput = false ] )
```

* $str: The string to hash
* $outputSize: The bit length of the output hash
* $rawOutput: If set to true, then the hash is returned in raw binary format

* Return value: A hex string containing the sha3 hash of the input string

Examples
--------
```php
echo sha3('');
```

a69f73cca23a9ac5c8b567dc185a756e97c982164fe25859e0d1dcc1475c80a615b2123af1f5f94c11e3e9402c3ac558f500199d95b6d3e301758586281dcd26

```php
echo sha3('', 256);
```

a7ffc6f8bf1ed76651c14756a061d662f580ff4de43b49fa82d80a4b80f8434a

```php
echo sha3('foobar', 384);
```

0fa8abfbdaf924ad307b74dd2ed183b9a4a398891a2f6bac8fd2db7041b77f068580f9c6c66f699b496c2da1cbcc7ed8


License
--------
[MIT](LICENSE)
