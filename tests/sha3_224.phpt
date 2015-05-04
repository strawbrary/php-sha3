--TEST--
Verify sha3 224 bit output
--SKIPIF--
<?php if (!extension_loaded("sha3")) print "skip"; ?>
--FILE--
<?php
require dirname(__FILE__) . DIRECTORY_SEPARATOR . 'test_helper.php';
testSHA3(224);
?>
--EXPECT--
6b4e03423667dbb73b6e15454f0eb1abd4597f9a1b078e3f5b5a6bc7
e642824c3f8cf24ad09234ee7d3c766fc9a3a5168d0c94ad73b46fdf
d15dadceaa4d5d7bb3b48f446421d542e08ad8887305e28d58335795
a67c289b8250a6f437a20137985d605589a8c163d45261b15419556e