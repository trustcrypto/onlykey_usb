var transport = require('./build/Release/onlykey_usb');
console.log("Exchanging data with OnlyKey");
const OKSETTIME = 228;
var header = [0xFF, 0xFF, 0xFF, 0xFF, OKSETTIME];
var time = [0x5C, 0xF7, 0x17, 0x43];
var fill = [];
for (var i=0; i<55; i++){
  fill[i] = i;
}
request = header.concat(time);
request = request.concat(fill);
console.log("Request is: " + request);
var response = transport.okExchange(request);
console.log("Response is: " + response);
