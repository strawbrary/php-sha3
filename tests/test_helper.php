<?php

function testSHA3($outputSize = null)
{
    $testCases = array(
        '',
        'abc',
        'The quick brown fox jumps over the lazy dog',
        'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789',
    );

    foreach ($testCases as $t) {
        if (isset($outputSize)) {
            echo sha3($t, $outputSize) . PHP_EOL;
        } else {
            echo sha3($t) . PHP_EOL;
        }
    }
}