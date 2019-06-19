
var os = require('os');

var HID = require('../');

device = new HID.HID(0);

var challenge = [];
for (var i=0; i<64; i++){
  challenge[i] = i+1;
}
console.log('Challenge is: ', JSON.stringify(challenge))
//var cmd = 0x30; // HMAC Slot 1
var cmd = 0x38; // HMAC Slot 2
request = challenge.concat(cmd);

//Max size for request is 65 bytes, 64 bytes + cmd
var numsentA = device.write(request);

console.log("Attaching receive 'data' handler");
device.on('data', function(data) {
    console.log("HMACSHA1 Response is: ");
    console.log(data);
});
device.on('error', function(err) {
    console.log("error:",err);
});

console.log("Waiting 5 seconds for HMACSHA1 Response, press button on device");
setTimeout( function() {
    console.log("Done");
    device.close();
}, 5000);
