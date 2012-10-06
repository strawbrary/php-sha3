--TEST--
Verify sha3 256 bit output
--SKIPIF--
<?php if (!extension_loaded("sha3")) print "skip"; ?>
--FILE--
<?php
require dirname(__FILE__).DIRECTORY_SEPARATOR.'test_helper.php';
testSHA3(256);
?>
--EXPECT--
c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470
eead6dbfc7340a56caedc044696a168870549a6a7f6f56961e84a54bd9970b8a
a8eaceda4d47b3281a795ad9e1ea2122b407baf9aabcb9e18b5717b7873537d2
ce87a5173bffd92399221658f801d45c294d9006ee9f3f9d419c8d427748dc41
348fb774adc970a16b1105669442625e6adaa8257a89effdb5a802f161b862ea