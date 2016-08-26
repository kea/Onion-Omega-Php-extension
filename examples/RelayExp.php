<?php

namespace Omega;

class RelayExp
{
    const RELAY_EXP_NUM_CHANNELS = 2;
    private $state;
    private $initialized = false;
    private $switch = '000';

    /**
     * Relay constructor.
     * @param string $switch
     * @param bool $initialize
     */
    public function __construct($switch = '000', $initialize = true)
    {
        if (!preg_match('/^[01]{3}$/', $switch)) {
            throw new \InvalidArgumentException('Invalid switch, format bbb');
        }

        $this->switch = $switch;
        $this->address = 7 - bindec($switch[2].$switch[1].$switch[0]);

        if ($initialize) {
            if ($this->checkInit() && !$this->isInitialized()) {
                $this->initialized = $this->driverInit();
            }
        }
    }

    public function assertChannel($channel)
    {
        if ($channel < -1 || $channel >= self::RELAY_EXP_NUM_CHANNELS) {
            throw new \InvalidArgumentException('Channel should be between 0 and '.self::RELAY_EXP_NUM_CHANNELS);
        }
    }

    public function assertState($state)
    {
        if ($state != 0 && $state != 1) {
            throw new \InvalidArgumentException('Status must be 0 or 1');
        }

        $this->state = $state;
    }

    public function driverInit()
    {
        return \relayDriverInit($this->address);
    }

    public function checkInit()
    {
        $bInitialized = 0;
        $status = \relayCheckInit($this->address, $bInitialized);
        $this->initialized = $bInitialized != 0;

        return $status;
    }

    public function isInitialized()
    {
        return $this->initialized;
    }

    public function setAllChannels($state)
    {
        $this->assertState($state);

        return \relaySetAllChannels($this->address, $state);
    }

    public function setChannel($channel, $state)
    {
        $this->assertChannel($channel);
        $this->assertState($state);

        return \relaySetChannel($this->address, $channel, $state);
    }
}
