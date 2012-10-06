<?php

function hex2string($h)
{
    $s='';

    for ($i = 0, $l = strlen($h) - 1; $i < $l; $i += 2) {
        $s .= chr(hexdec($h[$i].$h[$i+1]));
    }

    return $s;
}

function testSHA3($outputSize = NULL)
{
    $testCases = array(
        '',
        'cc',
        '41fb',
        '433c5303131624c0021d868a30825475e8d0bd3052a022180398f4ca4423b98214b6beaac21c8807a2c33f8c93bd42b092cc1b06cedf3224d5ed1ec29784444f22e08a55aa58542b524b02cd3d5d5f6907afe71c5d7462224a3f9d9e53e7e0846dcbb4ce',
        '3a3a819c48efde2ad914fbf00e18ab6bc4f14513ab27d0c178a188b61431e7f5623cb66b23346775d386b50e982c493adbbfc54b9a3cd383382336a1a0b2150a15358f336d03ae18f666c7573d55c4fd181c29e6ccfde63ea35f0adf5885cfc0a3d84a2b2e4dd24496db789e663170cef74798aa1bbcd4574ea0bba40489d764b2f83aadc66b148b4a0cd95246c127d5871c4f11418690a5ddf01246a0c80a43c70088b6183639dcfda4125bd113a8f49ee23ed306faac576c3fb0c1e256671d817fc2534a52f5b439f72e424de376f4c565cca82307dd9ef76da5b7c4eb7e085172e328807c02d011ffbf33785378d79dc266f6a5be6bb0e4a92eceebaeb1',
    );

    foreach ($testCases as $t) {
        if (isset($outputSize)) {
            echo sha3(hex2string($t), $outputSize).PHP_EOL;
        } else {
            echo sha3(hex2string($t)).PHP_EOL;
        }
    }
}