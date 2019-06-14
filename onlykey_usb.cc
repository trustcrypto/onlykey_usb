/*
 * Copyright (c) 2011-2013 Yubico AB.
 * All rights reserved.
 *
 * Author : Fredrik Thulin <fredrik@yubico.com>
 *          Dmitriy Kuptsov <dmitriy.kuptsov@vizly.net>
 *
 * Some basic code copied from ykpersonalize.c.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Standard C/C++ function declaratoins */
#include <stdio.h>
#include <time.h>

/* YubiKey specific function declarations */
#include "yubico-c/yubikey.h"
#include "yubikey-personalization/ykcore/ykdef.h"
#include "yubikey-personalization/ykcore/ykcore.h"
#include "yubikey-personalization/ykcore/ykstatus.h"

/* Node V8 function declarations */
#include <iostream>
#include "v8.h"
#include "node.h"
#include <string>
#include <vector>

using namespace std;
using namespace v8;
using namespace node;

#define CHALLENGE_LENGTH 64
#define RESPONSE_LENGTH SHA1_MAX_BLOCK_SIZE
#define RESPONSE_LENGTH_HEX SHA1_MAX_BLOCK_SIZE*2


static void challenge_response(YK_KEY * yk, int slot,
        const char * challenge,
        unsigned int challenge_len,
        unsigned char * response,
        unsigned int response_len,
        bool may_block)
{
    int yk_cmd = 0;
    switch(slot) {
    case 1:
        yk_cmd = SLOT_CHAL_HMAC1;
        break;
    case 2:
        yk_cmd = SLOT_CHAL_HMAC2;
        break;
    default:
        ThrowException(Exception::TypeError(String::New("Invalid slot number")));
    }
    if(! yk_challenge_response(yk, yk_cmd, may_block,
			       challenge_len,
                               (uint8_t *)challenge,
                               response_len,
                               response)) {
        ThrowException(Exception::TypeError(String::New("Failed to access OnlyKey")));
    }
}

Handle<Value>
okExchange(const Arguments& args) {
    HandleScope scope;
    YK_KEY *yk = NULL;

    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments. 1 arguments are expected")));
        return scope.Close(Undefined());
    }


    if (!yk_init()) {
        ThrowException(Exception::TypeError(String::New("Failed to initialize OnlyKey")));
        return scope.Close(Undefined());
    }

    static const int pids[] = {0x0486, 0x60fc};

    if ((yk = yk_open_key_vid_pid(0x16c0, pids, 2, 0)) == NULL) {
      if ((yk = yk_open_key_vid_pid(0x1d50, pids, 2, 0)) == NULL) {
        ThrowException(Exception::TypeError(String::New("Failed to open OnlyKey")));
        return scope.Close(Undefined());
      }
    }

    char chal[64];
    Local<Object> obj = args[0]->ToObject();
    int length = 0;
    if(obj->IsArray())
    {
        length = obj->Get(v8::String::New("length"))->ToObject()->Uint32Value();
    }

    for(int i = 0; i < length; i++)
    {
        v8::Local<v8::Value> element = obj->Get(i);
        chal[i]=element->NumberValue();
    }
    char * challenge = chal;
    unsigned char response[RESPONSE_LENGTH];
    unsigned char output_buf[RESPONSE_LENGTH_HEX];
    memset(response, 0, sizeof(response));
    memset(output_buf, 0, sizeof(output_buf));
    unsigned int expected_bytes = 64;
    bool may_block = false;
    challenge_response(yk, 1,
                       challenge,
                       CHALLENGE_LENGTH,
                       response,
		                   RESPONSE_LENGTH,
                       may_block);
    if (yk && !yk_close_key(yk)) {
       ThrowException(Exception::TypeError(String::New("Failed to close OnlyKey")));
       return scope.Close(Undefined());
    }

    if (!yk_release()) {
      ThrowException(Exception::TypeError(String::New("Failed to release OnlyKey")));
      return scope.Close(Undefined());
    }
    yubikey_hex_encode((char *)output_buf, (char *)response, expected_bytes);
    return String::New((const char *) output_buf);
}

void init(Handle<Object> exports, Handle<Object> module) {
    exports->Set(String::NewSymbol("okExchange"),
                 FunctionTemplate::New(okExchange)->GetFunction());
}

NODE_MODULE(onlykey_usb, init);
