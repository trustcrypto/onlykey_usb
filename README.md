# Node.js addon for USB communication with OnlyKey

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

