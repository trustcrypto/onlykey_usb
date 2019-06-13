# Node.js addon for generating OTPs with YubiKey

## Pre-requisites

Install needed dependencies

```
$ git clone git://github.com/Yubico/yubico-c.git
$ cd yubico-c
$ autoreconf --install
$ ./configure
$ make check
$ sudo make install
$ cd ..
$ git clone git://github.com/Yubico/yubikey-personalization.git
$ cd yubikey-personalization
$ autoreconf --install
$ ./configure
$ make check
$ sudo make install
```

## Configuring YubiKey

Configure your YubiKey in HMAC challenge-response mode:

```
$ slot=1
$ ykpersonalize -$slot -ochal-resp -ochal-hmac
```

Note, YubiKey has two slots, so one can configure both slots
in this mode if supporting 2 identities is required.

## Building the module

Compile the code:
```
$ make all
```

Run an example:
```
$ node example.js
```

# Installing from npm repository

```
$ npm install onlykey_usb
```

Test installation:

```
var m = require('onlykey_usb')
var slot = 1
var ts = new Date().getTime();
var otp = m.genOtp(ts, slot)
console.log('OTP for timestamp ' + ts + ' is ' + otp);
```
