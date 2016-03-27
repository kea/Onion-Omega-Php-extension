# Onion-Omega-Php-extension
PHP extension for Onion Omega IoT device https://onion.io/

## Done

* PWM expansion

## Todo

* Relay expansion
* Oled expansion

# Documentation

## Functions

    onionSetVerbosity($level);
    pwmDriverInit(int *bInitialized);
    pwmCheckInit();
    pwmSetFrequency(float freq);
    pwmSetupDriver(int driverNum, float duty, float delay);
    
## Constants

    PWM_FREQUENCY_DEFAULT   50.0f
    PWM_FREQUENCY_MIN       24.0f
    PWM_FREQUENCY_MAX       1526.0f
    PULSE_TOTAL_COUNT       4096
    PWM_EXP_NUM_CHANNELS    16

# Compile and test the extension

## Start the Vagrant machine

    $ vagrant up
    $ vagrant ssh

## Clone OpenWRT

    $ cd /usr/local
    $ git clone git://git.openwrt.org/15.05/openwrt.git 

## Setup the dev tools

    $ cd openwrt
    $ sudo apt-get install g++-multilib
    $ echo "src-git onion https://github.com/OnionIoT/OpenWRT-Packages.git" >> feeds.conf.default
    $ scripts/feeds update -a
    $ scripts/feeds install php5
    $ scripts/feeds install libonionpwmexp
    
    $ make tools/install # when menuconfig start, select language->php->php5 as M, php5-cli as M
    $ make toolchain/install
    $ make package/php5/compile
    $ make package/i2c-exp-driver/compile

## Configure the extension

    $ export PATH=/usr/local/openwrt/staging_dir/host/bin/:/usr/local/openwrt/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/bin:$PATH
    $ export TOOLCHAIN_DIR="/usr/local/openwrt/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2"
    $ export STAGING_DIR="/usr/local/openwrt/staging_dir/target-mips_34kc_uClibc-0.9.33.2"
    $ export TARGET_DIR="/usr/local/openwrt/build_dir/target-mips_34kc_uClibc-0.9.33.2/php-5.6.16"

    $ cd /vagrant/src
    $ /usr/local/openwrt/staging_dir/host/usr/bin/phpize --clean && /usr/local/openwrt/staging_dir/host/usr/bin/phpize && \
    rm aclocal.m4 && aclocal && autoconf \
    ./configure --with-php-config=/usr/local/openwrt/staging_dir/host/usr/bin/php-config  '--target=mips-openwrt-linux' '--host=mips-openwrt-linux' '--build=x86_64-linux-gnu' 'build_alias=x86_64-linux-gnu' 'host_alias=mips-openwrt-linux' 'target_alias=mips-openwrt-linux' \
    CC="mips-openwrt-linux-uclibc-gcc" \
    CFLAGS="-Os -pipe -mno-branch-likely -mips32r2 -mtune=34kc -fno-caller-saves -fhonour-copts -Wno-error=unused-but-set-variable -Wno-error=unused-result -msoft-float"  \
    LDFLAGS="-L$TARGET_DIR/usr/lib -L$TARGET_DIR/lib -L$TOOLCHAIN_DIR/usr/lib -L$TOOLCHAIN_DIR/lib -L$TARGET_DIR/usr/lib/libiconv-stub/lib -L$TARGET_DIR/usr/lib/libintl-stub/lib -L$STAGING_DIR/usr/lib" \
    CPPFLAGS="-I$TARGET_DIR/usr/include -I$TARGET_DIR/include -I$TOOLCHAIN_DIR/usr/include -I$TOOLCHAIN_DIR/include -I$TARGET_DIR/usr/lib/libiconv-stub/include -I$TARGET_DIR/usr/lib/libintl-stub/include -I$STAGING_DIR/usr/include" \
    CXX="mips-openwrt-linux-uclibc-g++" \
    CXXFLAGS="-Os  -pipe -mno-branch-likely -mips32r2 -mtune=34kc -fno-caller-saves -fhonour-copts -Wno-error=unused-but-set-variable -Wno-error=unused-result -msoft-float" \
    LIBTOOL='/usr/local/openwrt/tools/libtool --tag=CC' \
    OMEGA_DIR='/usr/local/openwrt/staging_dir/target-mips_34kc_uClibc-0.9.33.2/usr'

## Compile it

    $ make

## Copy the module to Onion Ω

    $ scp modules/omega.so root@onion-ABCD.local:

## Verify installation

    $ ssh root@omega-ABCD.local
    $ php-cli -d extension=/root/omega.so -m

You should see "omega" as part of the loaded extension.

    $ php-cli -d extension=/root/omega.so test.php
