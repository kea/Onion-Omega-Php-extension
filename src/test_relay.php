<?php

include(__DIR__.'/../examples/RelayExp.php');

$relay = new \Omega\RelayExp('100');

$relay->setAllChannels(1);
sleep(2);
$relay->setChannel(1, 0);
sleep(2);
$relay->setChannel(0, 0);
sleep(2);
$relay->setAllChannels(1);
sleep(2);
$relay->setAllChannels(0);