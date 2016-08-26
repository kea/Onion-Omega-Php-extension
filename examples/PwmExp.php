<?php

namespace Omega;

class PwmExp
{
    private $initialized = false;

    public function __construct($initialize = true)
    {
        if ($initialize) {
            if ($this->checkInit() && !$this->isInitialized()) {
                $this->initialized = $this->driverInit();
            }
        }
    }

    public function checkInit()
    {
        $bInitialized = 0;
        $status = \pwmCheckInit($bInitialized);
        $this->initialized = $bInitialized != 0;

        return $status;
    }

    public function isInitialized()
    {
        return $this->initialized;
    }

    public function driverInit()
    {
        return \pwmDriverInit();
    }

    public function disableChip()
    {
        return \pwmDisableChip();
    }

    public function setFrequency($frequency)
    {
        return \pwmSetFrequency($frequency);
    }

    public function setupDriver($channel, $duty, $delay)
    {
        return \pwmSetupDriver($channel, $duty, $delay);
    }
}
