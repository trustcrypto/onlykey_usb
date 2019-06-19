# Node.js addon for USB communication with OnlyKey

## Installing from npm repository

```
$ npm install onlykey_usb
```

## Installing from source

### Pre-requisites

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

Build from source code:
```
$ npm install --build-from-source
```

## Run an example:

```
$ node ./src/hmacsha1.js

Challenge is:  [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64]
Attaching receive 'data' handler
Waiting 5 seconds for HMACSHA1 Response, press button on device
HMACSHA1 Response is: 
<Buffer be 1f 74 10 c8 ff cc 26 8f 83 1b bf 7c 5e 98 1d 8e fe 89 ab 82>
```

```
$ node ./src/settime.js 

Request is:  [255,255,255,255,228,92,247,23,68,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,48]
Attaching receive 'data' handler
Waiting 100ms for data
Response is:  UNLOCKEDv0.2-beta.8c
Done
```
