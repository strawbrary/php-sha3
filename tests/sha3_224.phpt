--TEST--
Verify sha3 224 bit output
--SKIPIF--
<?php if (!extension_loaded("sha3")) print "skip"; ?>
--FILE--
<?php
require dirname(__FILE__).DIRECTORY_SEPARATOR.'test_helper.php';
testSHA3(224);
?>
--EXPECT--
f71837502ba8e10837bdd8d365adb85591895602fc552b48b7390abd
a9cab59eb40a10b246290f2d6086e32e3689faf1d26b470c899f2802
615ba367afdc35aac397bc7eb5d58d106a734b24986d5d978fefd62c
62b10f1b6236ebc2da72957742a8d4e48e213b5f8934604bfd4d2c3a
5af56987ea9cf11fcd0eac5ebc14b037365e9b1123e31cb2dfc7929a