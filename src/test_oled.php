<?php

define('EXIT_FAILURE', 1);

$init = 1;
$clear = 0;
$message = "Hello PHP world!";

// check if OLED Expansion is present
$status = oledCheckInit();

// exit the app if i2c reads fail
if ($status == EXIT_FAILURE) {
    echo "> ERROR: OLED Expansion not found!\n";
    return 0;
}

// initialize display
if ($init == 1 ) {
    $status = oledDriverInit();
    if ($status == EXIT_FAILURE) {
        echo "main-oled-exp:: display init failed!\n";
    }
}

// clear screen
if ($clear == 1 ) {
    echo "> Clearing display\n";
    $status = oledClear();
    if ($status == EXIT_FAILURE) {
        echo "main-oled-exp:: display clear failed!\n";
    }
}

$status	= oledWrite($message);
