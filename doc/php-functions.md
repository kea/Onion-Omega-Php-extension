## Functions

    onionSetVerbosity($level);
    
    pwmDriverInit(int *bInitialized);
    pwmCheckInit();
    pwmSetFrequency(float freq);
    pwmSetupDriver(int driverNum, float duty, float delay);
    
    oledCheckInit();
    oledDriverInit();
    oledClear();
    oledSetDisplayPower($bOn);
    oledSetDisplayMode($bInvert);
    oledSetBrightness($brightness);
    oledSetDim($bDim);
    oledSetMemoryMode($mode);
    oledSetCursor($row, $col);
    oledSetColumnAddressing($startPixel, $endPixel);
    oledWriteChar($char);
    oledWrite($string);
    oledDrawFromFile($filename);
    oledScroll($direction, $scrollSpeed, $startPage, $stopPage);
    oledScrollDiagonal($direction, $scrollSpeed, $fixedRows, $scrollRows, $verticalOffset, $startPage, $stopPage);
    oledScrollStop();
    
    relayDriverInit($devAddress);
    relayCheckInit($devAddress, $bInitialized);
    relaySetAllChannels($devAddress, $state);
    relaySetChannel($devAddress, $channel, $state);
     
## Constants

    PWM_FREQUENCY_DEFAULT   50.0f
    PWM_FREQUENCY_MIN       24.0f
    PWM_FREQUENCY_MAX       1526.0f
    PULSE_TOTAL_COUNT       4096
    PWM_EXP_NUM_CHANNELS    16
    