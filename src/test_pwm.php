<?php

include(__DIR__.'/../examples/PwmExp.php');

$frequency = PWM_FREQUENCY_DEFAULT; // float
$channel = 1; // 0-15
$duty = 0.1; //0.0 100.0
$delay = 0.1; //0.0 100.0

$pwm = new \Omega\PwmExp();

if (!$pwm->isInitialized()) {
    echo "> ERROR: PWM Expansion not found!\n";

    exit(1);
}

if (!$pwm->setFrequency($frequency)) {
    echo "> ERROR: pwm set frequency failed!\n";
}

if (!$pwm->setupDriver($channel, $duty, $delay)) {
    echo "> ERROR: setup driver failed!\n";
}

sleep(5);

$pwm->disableChip();
