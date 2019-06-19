
var os = require('os');

var HID = require('../');

device = new HID.HID(0);

const OKSETTIME = 228;
var header = [0xFF, 0xFF, 0xFF, 0xFF, OKSETTIME];
var time = [0x5C, 0xF7, 0x17, 0x44];
var fill = [];
for (var i=0; i<55; i++){
  fill[i] = 0;
}
var cmd = 0x30;
request = header.concat(time);
request = request.concat(fill);
request = request.concat(cmd);

//Max size for request is 65 bytes, 64 bytes + cmd

console.log('Request is: ', JSON.stringify(request))
var numsentA = device.write(request);

console.log("Attaching receive 'data' handler");
device.on('data', function(data) {
    console.log("Response is: ", data.toString('ascii'));
});
device.on('error', function(err) {
    console.log("error:",err);
});

console.log("Waiting 100ms for response");
setTimeout( function() {
    console.log("Done");
    device.close();
}, 100);
