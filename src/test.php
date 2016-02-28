<?php

define('EXIT_FAILURE', 1);
define('ONION_VERBOSITY_NONE', 0);
define('ONION_VERBOSITY_NORMAL', 1);
define('ONION_SEVERITY_FATAL', 2);

function onionPrint($level, $msg) {
    echo $msg."\n";
}

//$verbose = ONION_VERBOSITY_NORMAL; // ONION_VERBOSITY_NONE ONION_SEVERITY_FATAL
// set the defaults
$init = 0; // 1
$mode = MAIN_PWM_EXP_DUTY_MODE; //MAIN_PWM_EXP_PERIOD_MODE MAIN_PWM_EXP_SLEEP_MODE
$frequency = PWM_FREQUENCY_DEFAULT; // float
$delay = 0.0;

// set the verbosity
// pwmOnionSetVerbosity($verbose);

if ($init) {
    $status = pwmDriverInit();
    if ($status == EXIT_FAILURE) {
        onionPrint(ONION_SEVERITY_FATAL, "main-pwm-exp:: pwm init failed!\n");
    }

    return 0;
}

// check if setting sleep mode
if ($mode == MAIN_PWM_EXP_SLEEP_MODE) {
    $status = pwmDisableChip();
    if ($status == EXIT_FAILURE) {
        onionPrint(ONION_SEVERITY_FATAL, "main-pwm-exp:: pwm chip disable failed!\n");
    }

    return 0;
}


//// parse the real arguments
if ($mode == MAIN_PWM_EXP_DUTY_MODE) {

    $channel = 1; // 0-15
    $duty = 0.1; //0.0 100.0
    $delay = 0.1; //0.0 100.0

} elseif ($mode == MAIN_PWM_EXP_PERIOD_MODE) {

    $channel = 1;
    $periodOn = 2;
    $periodTotal = 5;
    $duty = ($periodOn / $periodTotal) * 100.0;

    // if (frequency < PWM_FREQUENCY_MIN || frequency > PWM_FREQUENCY_MAX) {
    $frequency = (1.0 / ($periodTotal / 1000.0) );
}


//// PWM PROGRAMMING
$bInitialized = 0;
$status = pwmCheckInit($bInitialized);

// exit the app if i2c reads fail
if ($status == EXIT_FAILURE) {
    onionPrint(ONION_SEVERITY_FATAL, "> ERROR: PWM Expansion not found!\n");

    return 0;
}

// perform initialization
if ($init == 1 || $bInitialized == 0) {
    echo "Initialize...";
    $status = pwmDriverInit();
    if ($status == EXIT_FAILURE) {
        onionPrint(ONION_SEVERITY_FATAL, "main-pwm-exp:: pwm init failed!\n");
        return 0;
    }
    echo " Ok\n";
}

// setup the frequency
$status = pwmSetFrequency($frequency);
if ($status == EXIT_FAILURE) {
    onionPrint(ONION_SEVERITY_FATAL, "main-pwm-exp:: pwm set frequency failed!\n");
}

// setup the driver
$status = pwmSetupDriver($channel, $duty, $delay);
if (status == EXIT_FAILURE) {
    onionPrint(ONION_SEVERITY_FATAL, "main-pwm-exp:: driver setup failed!\n");
}
