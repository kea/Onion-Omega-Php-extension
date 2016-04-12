<?php

define('EXIT_FAILURE', 1);
define('ONION_VERBOSITY_NONE', 0);
define('ONION_VERBOSITY_NORMAL', 1);
define('ONION_SEVERITY_FATAL', 2);

class Relay
{
    const RELAY_EXP_NUM_CHANNELS = 2;
    private $state;
    private $initialized = false;
    private $switch = '000';

    /**
     * Relay constructor.
     * @param string $switch
     */
    public function __construct($switch = '000')
    {
        if (!preg_match('/^[01]{3}$/', $switch)) {
            throw new \InvalidArgumentException('Invalid switch, format bbb');
        }

        $this->switch = $switch;
        $this->address = 7 - bindec($switch[2].$switch[1].$switch[0]);
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
        return relayDriverInit($this->address) != EXIT_FAILURE;
    }

    public function checkInit()
    {
        $bInitialized = 0;
        $status = relayCheckInit($this->address, $bInitialized) != EXIT_FAILURE;
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

        return relaySetAllChannels($this->address, $state) != EXIT_FAILURE;
    }

    public function setChannel($channel, $state)
    {
        $this->assertChannel($channel);
        $this->assertState($state);

        return relaySetChannel($this->address, $channel, $state) != EXIT_FAILURE;
    }
}

$relay = new Relay('100');
$relay->checkInit();
if (!$relay->isInitialized()) {
    $relay->driverInit();
}
$relay->setAllChannels(1);
sleep(2);
$relay->setChannel(1, 0);
sleep(2);
$relay->setChannel(0, 0);
sleep(2);
$relay->setAllChannels(1);
sleep(2);
$relay->setAllChannels(0);