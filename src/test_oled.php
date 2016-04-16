<?php

include(__DIR__.'/../examples/OledExp.php');

$message = "Hello PHP world!";

$oled = new \Omega\OledExp();

if (!$oled->clear()) {
    echo "Error: display clear failed!\n";
}

if (!$oled->write($message)) {
    echo "Error: display write failed!\n";
}
