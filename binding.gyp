
{
    "dll_files" : [
        'windows\bin\libykpers-1-1.dll',
        'windows\bin\libyubikey.dll'
    ],
    'targets': [
        {
            'target_name': 'HID',
            'sources': [ 'onlykey_usb.cc' ],
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
					"-lm", "-lykpers-1.1", "-lyubikey"
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
                    }
                }], # OS==mac
                [ 'OS=="linux"', {
            		"libraries": [
					"-lm", "-lykpers-1.1", "-lyubikey"
				    ]
                }], # OS==linux
                [ 'OS=="win"', {
                    'msvs_settings': {
                        'VCLinkerTool': {
                            'AdditionalLibraryDirectories': ['C:\\msys64\\mingw64\\lib'],
                            'AdditionalDependencies': ['setupapi.lib']
                        }
                    },
                    'libraries': [
                      '-llibyubikey.dll.a',
                      '-llibyubikey.a',
                      '-llibykpers-1.dll.a',
                      '-llibykpers-1.a',
                    ],
                }] # OS==win
            ],
            'cflags!': ['-ansi', '-fno-exceptions' ],
            'cflags_cc!': [ '-fno-exceptions' ],
            'cflags': ['-g', '-exceptions'],
            'cflags_cc': ['-g', '-exceptions']
        }, # target

    ]
}

