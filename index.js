var transport = null;

// Load the precompiled binary for windows.
if (process.platform == "win32" && process.arch == "x64") {
    transport = require('./bin/winx64/onlykeyusb');  
}
else {
	// Load the new built binary for other platforms.
	transport = require('./build/Release/onlykey_usb');  
}

module.exports = transport;