#!/bin/sh

/usr/local/openwrt/staging_dir/host/usr/bin/phpize --clean && /usr/local/openwrt/staging_dir/host/usr/bin/phpize && \
./configure --with-php-config=/usr/local/openwrt/staging_dir/host/usr/bin/php-config  '--target=mips-openwrt-linux' '--host=mips-openwrt-linux' '--build=x86_64-linux-gnu' '--exec-prefix=/vagrant/src/phpsrc/staging/usr' 'build_alias=x86_64-linux-gnu' 'host_alias=mips-openwrt-linux' 'target_alias=mips-openwrt-linux' \
TOOLCHAIN_DIR="/usr/local/openwrt/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2" \
STAGING_DIR="/usr/local/openwrt/staging_dir/target-mips_34kc_uClibc-0.9.33.2" \
TARGET_DIR="/usr/local/openwrt/build_dir/target-mips_34kc_uClibc-0.9.33.2/php-5.6.16" \
CC="mips-openwrt-linux-uclibc-gcc" \
CFLAGS="-Os -pipe -mno-branch-likely -mips32r2 -mtune=34kc -fno-caller-saves -fhonour-copts -Wno-error=unused-but-set-variable -Wno-error=unused-result -msoft-float"  \
LDFLAGS="-L$TARGET_DIR/usr/lib -L$TARGET_DIR/lib -L$TOOLCHAIN_DIR/usr/lib -L$TOOLCHAIN_DIR/lib -L$TARGET_DIR/usr/lib/libiconv-stub/lib -L$TARGET_DIR/usr/lib/libintl-stub/lib -L$STAGING_DIR/usr/lib" \
CPPFLAGS="-I$TARGET_DIR/usr/include -I$TARGET_DIR/include -I$TOOLCHAIN_DIR/usr/include -I$TOOLCHAIN_DIR/include -I$TARGET_DIR/usr/lib/libiconv-stub/include -I$TARGET_DIR/usr/lib/libintl-stub/include -I$STAGING_DIR/usr/include" \
CXX="mips-openwrt-linux-uclibc-g++" \
CXXFLAGS="-Os  -pipe -mno-branch-likely -mips32r2 -mtune=34kc -fno-caller-saves -fhonour-copts -Wno-error=unused-but-set-variable -Wno-error=unused-result -msoft-float" \
LIBTOOL='/usr/local/openwrt/tools/libtool --tag=CC' \
PWM_DIR='/usr/local/openwrt/staging_dir/target-mips_34kc_uClibc-0.9.33.2/usr'

