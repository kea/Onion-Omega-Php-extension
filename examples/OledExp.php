<?php

namespace Omega;

class OledExp
{
    private $initialized = false;

    public function __construct($initialize = true)
    {
        if ($initialize) {
            if ($this->checkInit()) {
                $this->initialized = $this->driverInit();
            }
        }
    }

    public function checkInit()
    {
        return oledCheckInit();
    }

    public function isInitialized()
    {
        return $this->initialized;
    }

    public function driverInit()
    {
        return oledDriverInit();
    }

    public function clear()
    {
        return oledClear();
    }

    public function write($message)
    {
        return oledWrite($message);
    }
}
