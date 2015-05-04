--TEST--
Verify sha3 256 bit output
--SKIPIF--
<?php if (!extension_loaded("sha3")) print "skip"; ?>
--FILE--
<?php
require dirname(__FILE__) . DIRECTORY_SEPARATOR . 'test_helper.php';
testSHA3(256);
?>
--EXPECT--
a7ffc6f8bf1ed76651c14756a061d662f580ff4de43b49fa82d80a4b80f8434a
3a985da74fe225b2045c172d6bd390bd855f086e3e9d525b46bfe24511431532
69070dda01975c8c120c3aada1b282394e7f032fa9cf32f4cb2259a0897dfc04
a79d6a9da47f04a3b9a9323ec9991f2105d4c78a7bc7beeb103855a7a11dfb9f