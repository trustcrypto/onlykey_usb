
#{
#	"targets": [
#	{
#		"target_name": "onlykey_usb",
#		"sources": [ "onlykey_usb.cc" ],
#		'include_dirs': [
 #         'msys64/mingw64/bin',
  #        'home/admin/onlykey_usb/lib'
   #     ],
    #    'libraries': [
     #     'lib/libyubikey.dll.a',
      #    'lib/libyubikey.a'
       # ],
	#}]
#}


{
	"targets": [
	{
		"target_name": "onlykey_usb",
		"sources": [ "onlykey_usb.cc" ],
		'include_dirs': [
          'msys64/mingw64/bin',
          'home/admin/onlykey_usb/lib'
        ],
        'msvs_settings': {
        'VCLinkerTool': {
            'AdditionalLibraryDirectories': 'c:\\msys64\\mingw64\\lib'
        }
        },
        'libraries': [
          '-llibyubikey.dll.a',
          '-llibyubikey.a',
          '-llibykpers-1.dll.a',
          '-llibykpers-1.a',
        ],
	}]
}

