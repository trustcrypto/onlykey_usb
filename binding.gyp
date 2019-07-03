
{
    'targets': [
        {
            'target_name': 'HID',
            'sources': [ './src/HID.cc' ],
            'defines': [
                '_LARGEFILE_SOURCE',
                '_FILE_OFFSET_BITS=64',
            ],
            "include_dirs" : [
                "<!(node -e \"require('nan')\")"
            ],
            'conditions': [
                [ 'OS=="mac"', {
            		"libraries": [
					"<!(pwd)/mac/lib/libykpers-1.a", "<!(pwd)/mac/lib/libyubikey.a"
			        ],
                    'LDFLAGS': [
                        '-framework IOKit',
                        '-framework CoreFoundation'
                    ],
                    'xcode_settings': {
                        'CLANG_CXX_LIBRARY': 'libc++',
                        'MACOSX_DEPLOYMENT_TARGET': '10.9',
                        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
                        'OTHER_LDFLAGS': [
                            '-framework IOKit',
                            '-framework CoreFoundation'
                        ],
                    },
                     "copies": [
                      {
                        "destination": "build/Release",
                        "files": [
                             "mac/lib/libykpers-1.a",
                             "mac/lib/libyubikey.a",
                              "mac/lib/libykpers-1.1.dylib",
                              "mac/lib/libyubikey.0.dylib"
                        ]
                      }
                    ]
                }], # OS==mac
                [ 'OS=="linux"', {
            		"libraries": [
					"<!(pwd)/linux/lib/libykpers-1.a", "<!(pwd)/linux/lib/libyubikey.a"
				    ],
                     "copies": [
                      {
                        "destination": "build/Release",
                        "files": [
                             "linux/lib/libykpers-1.so",
                             "linux/lib/libyubikey.so",
                             "linux/lib/libykpers-1.a",
                             "linux/lib/libyubikey.a",
                        ]
                      }
                    ]
                }], # OS==linux
                [ 'OS=="win"', {
                    'msvs_settings': {
                        'VCLinkerTool': {
                            'AdditionalLibraryDirectories': ['<!(echo %cd%)\\windows\\lib'],
                            'AdditionalDependencies': ['setupapi.lib']
                        }
                    },
                    'libraries': [
                      '-llibyubikey.dll.a',
                      '-llibyubikey.a',
                      '-llibykpers-1.dll.a',
                      '-llibykpers-1.a',
                      '-llibjson.a',
                      '-llibjson.dll.a',
                    ],
                    'direct_dependent_settings': {
                        'include_dirs': [
                        'windows/bin',
                        "<!(node -e \"require('nan')\")"
                        ]
                     },
                     "copies": [
                      {
                        "destination": "build/Release",
                        "files": [
                             "windows/bin/libykpers-1-1.dll",
                             "windows/bin/libyubikey-0.dll",
                             "windows/bin/libjson-c-2.dll",
                        ]
                      }
                    ]
                }] # OS==win
            ],
            'cflags!': ['-ansi', '-fno-exceptions' ],
            'cflags_cc!': [ '-fno-exceptions' ],
            'cflags': ['-g', '-exceptions'],
            'cflags_cc': ['-g', '-exceptions']
        } # target HID

    ]
}
