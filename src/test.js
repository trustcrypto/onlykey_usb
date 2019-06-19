
var os = require('os');

var HID = require('../');

device = new HID.HID(0);

var messageA = [];
for(var i=0; i < 64; i++) {
    messageA[i] = 120 + i;
}

console.log('Sending message A: ', JSON.stringify(messageA))
var numsentA = device.write(messageA);
console.log('messageA len:', messageA.length, 'actual sent len:', numsentA);

console.log("Attaching receive 'data' handler");
device.on('data', function(data) {
    console.log("got data:");
    console.log(data);
    device.close();
});
device.on('error', function(err) {
      console.log("error:",err);
});

console.log("Waiting 2 seconds for data");
setTimeout( function() {
    console.log("Done");
    device.close();
}, 2000);
