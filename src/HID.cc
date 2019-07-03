/* Modifications
 * Copyright (c) 2015-2019, CryptoTrust LLC.
 * All rights reserved.
 *
 * Author : Tim Steiner <t@crp.to>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by CryptoTrust LLC. for
 *    the OnlyKey Project (https://www.crp.to/ok)"
 *
 * 4. The names "OnlyKey" and "CryptoTrust" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    admin@crp.to.
 *
 * 5. Products derived from this software may not be called "OnlyKey"
 *    nor may "OnlyKey" or "CryptoTrust" appear in their names without
 *    specific prior written permission. For written permission, please
 *    contact admin@crp.to.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by CryptoTrust LLC. for
 *    the OnlyKey Project (https://www.crp.to/ok)"
 *
 * 7. Redistributions in any form must be accompanied by information on
 *    how to obtain complete source code for this software and any
 *    accompanying software that uses this software. The source code
 *    must either be included in the distribution or be available for
 *    no more than the cost of distribution plus a nominal fee, and must
 *    be freely redistributable under reasonable conditions. For a
 *    binary file, complete source code means the source code for all
 *    modules it contains.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS
 * ARE GRANTED BY THIS LICENSE. IF SOFTWARE RECIPIENT INSTITUTES PATENT
 * LITIGATION AGAINST ANY ENTITY (INCLUDING A CROSS-CLAIM OR COUNTERCLAIM
 * IN A LAWSUIT) ALLEGING THAT THIS SOFTWARE (INCLUDING COMBINATIONS OF THE
 * SOFTWARE WITH OTHER SOFTWARE OR HARDWARE) INFRINGES SUCH SOFTWARE
 * RECIPIENT'S PATENT(S), THEN SUCH SOFTWARE RECIPIENT'S RIGHTS GRANTED BY
 * THIS LICENSE SHALL TERMINATE AS OF THE DATE SUCH LITIGATION IS FILED. IF
 * ANY PROVISION OF THIS AGREEMENT IS INVALID OR UNENFORCEABLE UNDER
 * APPLICABLE LAW, IT SHALL NOT AFFECT THE VALIDITY OR ENFORCEABILITY OF THE
 * REMAINDER OF THE TERMS OF THIS AGREEMENT, AND WITHOUT FURTHER ACTION
 * BY THE PARTIES HERETO, SUCH PROVISION SHALL BE REFORMED TO THE MINIMUM
 * EXTENT NECESSARY TO MAKE SUCH PROVISION VALID AND ENFORCEABLE. ALL
 * SOFTWARE RECIPIENT'S RIGHTS UNDER THIS AGREEMENT SHALL TERMINATE IF IT
 * FAILS TO COMPLY WITH ANY OF THE MATERIAL TERMS OR CONDITIONS OF THIS
 * AGREEMENT AND DOES NOT CURE SUCH FAILURE IN A REASONABLE PERIOD OF
 * TIME AFTER BECOMING AWARE OF SUCH NONCOMPLIANCE. THIS SOFTWARE IS
 * PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Original License
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

// -*- C++ -*-

// Copyright Hans Huebner and contributors. All rights reserved.
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

/* Standard C/C++ function declaratoins */
#include <iomanip>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <node.h>
#include <nan.h>
//#include <unistd.h>
#include <time.h>
#include <stdio.h>

/* YubiKey specific function declarations */
#include "../include/yubikey.h"
#include "../include/ykcore/ykdef.h"
#include "../include/ykcore/ykcore.h"
#include "../include/ykcore/ykstatus.h"

/* Node V8 function declarations */
#include <iostream>
#include "v8.h"
#include "node.h"
#include <string>
#include <vector>

using namespace std;
using namespace v8;
using namespace node;

#define RESPONSE_LENGTH 64


// //////////////////////////////////////////////////////////////////
// Throwable error class that can be converted to a JavaScript
// exception
// //////////////////////////////////////////////////////////////////
class JSException
{
public:
  JSException(const string& text) : _message(text) {}
  virtual ~JSException() {}
  virtual const string message() const { return _message; }
  virtual void asV8Exception() const { Nan::ThrowError(message().c_str()); }

protected:
  string _message;
};

class HID
  : public Nan::ObjectWrap
{
public:
  static void Initialize(Local<Object> target);

  typedef vector<unsigned char> databuf_t;

  int write(const databuf_t& message)
    throw(JSException);
  void close();

private:
  HID();
  ~HID() { close(); }

  static NAN_METHOD(New);
  static NAN_METHOD(read);
  static NAN_METHOD(write);
  static NAN_METHOD(close);

  static void recvAsync(uv_work_t* req);
  static void recvAsyncDone(uv_work_t* req);


  struct ReceiveIOCB {
    ReceiveIOCB(HID* hid, Nan::Callback *callback)
      : _hid(hid),
        _callback(callback),
        _error(0)
    {}

    ~ReceiveIOCB()
    {
      if (_error) {
        delete _error;
      }
    }

    HID* _hid;
    Nan::Callback *_callback;
    JSException* _error;
    vector<unsigned char> _data;
  };

  void readResultsToJSCallbackArguments(ReceiveIOCB* iocb, Local<Value> argv[]);

  YK_KEY *yk;
  unsigned char yk_cmd;
};

HID::HID()
{
  yk = NULL;
  yk_cmd = 0;

  if (!yk_init()) {
      throw JSException("Failed to initialize OnlyKey");
  }

  static const int pids[] = {0x0486, 0x60fc, 0x0010};

  if ((yk = yk_open_key_vid_pid(0x16c0, pids, 3, 0)) == NULL) {
    if ((yk = yk_open_key_vid_pid(0x1d50, pids, 3, 0)) == NULL) {
      if ((yk = yk_open_key_vid_pid(0x1050, pids, 3, 0)) == NULL) {
        throw JSException("Failed to initialize OnlyKey");
      }
    }
  }
}

void
HID::close()
{
  if (yk) {
    if (!yk_close_key(yk)) {
        throw JSException("Failed to close OnlyKey");
    }

    if (!yk_release()) {
      throw JSException("Failed to release OnlyKey");
    }
    yk=0;
  }
}

int
HID::write(const databuf_t& message)
  throw(JSException)
{
  if(!yk) {
    throw JSException("Cannot write to closed device");
  }
  //unsigned char buf[message.size()];


  unsigned char* buf = new unsigned char[message.size()];
  unsigned char* p = buf;

  for (vector<unsigned char>::const_iterator i = message.begin(); i != message.end(); i++) {
    *p++ = *i;
  }
  yk_cmd = buf[message.size()-1];
  if (! yk_write_to_key(yk, yk_cmd, buf, message.size()-1)) {
    throw JSException("Failed to write to OnlyKey");
  }

  delete[] buf;

  return message.size();  // return actual number of bytes written
}

void
HID::recvAsync(uv_work_t* req)
{
  ReceiveIOCB* iocb = static_cast<ReceiveIOCB*>(req->data);
  HID* hid = iocb->_hid;

  unsigned char response[RESPONSE_LENGTH] = {0};
  unsigned int flags = 0;
  flags |= YK_FLAG_MAYBLOCK;
  static unsigned int bytes_read = 1;
  unsigned int expected_bytes;
  if (hid->yk_cmd == 0x30 || hid->yk_cmd == 0x38) {
    expected_bytes = 22;
  } else {
    expected_bytes = RESPONSE_LENGTH;
  }

  if (bytes_read==1) {
    bytes_read=0; //In progress
    yk_read_response_from_key(hid->yk, hid->yk_cmd, flags,
          response, expected_bytes,
          expected_bytes,
          &bytes_read);
  }

  if (bytes_read == 0) {
     iocb->_error = new JSException("Failed to read any data from OnlyKey");
  } else if (bytes_read > 1 && bytes_read <= 64) {
    iocb->_data = vector<unsigned char>(response, response + bytes_read);
    bytes_read=255; //Done
  }
}

void
HID::readResultsToJSCallbackArguments(ReceiveIOCB* iocb, Local<Value> argv[])
{
  if (iocb->_error) {
    argv[0] = Exception::Error(Nan::New<String>(iocb->_error->message().c_str()).ToLocalChecked());
  } else {
    const vector<unsigned char>& message = iocb->_data;

    Local<Object> buf = Nan::NewBuffer(message.size()).ToLocalChecked();
    char* data = Buffer::Data(buf);

    int j = 0;
    for (vector<unsigned char>::const_iterator k = message.begin(); k != message.end(); k++) {
      data[j++] = *k;
    }
    argv[1] = buf;
  }
}

void
HID::recvAsyncDone(uv_work_t* req)
{
  Nan::HandleScope scope;
  ReceiveIOCB* iocb = static_cast<ReceiveIOCB*>(req->data);

  Local<Value> argv[2];
  argv[0] = Nan::Undefined();
  argv[1] = Nan::Undefined();

  iocb->_hid->readResultsToJSCallbackArguments(iocb, argv);
  iocb->_hid->Unref();



  Nan::TryCatch tryCatch;
  //iocb->_callback->Call(2, argv);
  Nan::AsyncResource resource("node-hid recvAsyncDone");
  iocb->_callback->Call(2, argv, &resource);
  if (tryCatch.HasCaught()) {
      Nan::FatalException(tryCatch);
  }
  delete req;
  delete iocb->_callback;

  delete iocb;
}

NAN_METHOD(HID::read)
{
  Nan::HandleScope scope;

  if (info.Length() != 1
      || !info[0]->IsFunction()) {
    return Nan::ThrowError("need one callback function argument in read");
  }

  HID* hid = Nan::ObjectWrap::Unwrap<HID>(info.This());
  hid->Ref();

  uv_work_t* req = new uv_work_t;
  req->data = new ReceiveIOCB(hid, new Nan::Callback(Local<Function>::Cast(info[0])));;
  uv_queue_work(uv_default_loop(), req, recvAsync, (uv_after_work_cb)recvAsyncDone);

  return;
}


NAN_METHOD(HID::New)
{
  Nan::HandleScope scope;

  if (!info.IsConstructCall()) {
    return Nan::ThrowError("HID function can only be used as a constructor");
  }

  if (info.Length() < 1) {
    return Nan::ThrowError("HID constructor requires at least one argument");
  }

  try {
    HID* hid;
    if (info.Length() == 1) {
      // open by path
      hid = new HID();
    } else {
      wchar_t wserialstr[100]; // FIXME: is there a better way?
      wchar_t* wserialptr = NULL;
      if (info.Length() > 2) {
        char* serialstr = *Nan::Utf8String(info[2]);
        mbstowcs( wserialstr, serialstr, 100);
        wserialptr = wserialstr;
      }
      hid = new HID();
    }
    hid->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  }
  catch (const JSException& e) {
    e.asV8Exception();
  }
}

NAN_METHOD(HID::close)
{
  Nan::HandleScope scope;

  try {
    HID* hid = Nan::ObjectWrap::Unwrap<HID>(info.This());
    hid->close();
    return;
  }
  catch (const JSException& e) {
    e.asV8Exception();
  }
}


NAN_METHOD(HID::write)
{
  Nan::HandleScope scope;

  if (info.Length() != 1) {
    return Nan::ThrowError("HID write requires one argument");
  }

  try {
    HID* hid = Nan::ObjectWrap::Unwrap<HID>(info.This());

    vector<unsigned char> message;
    Local<Array> messageArray = Local<Array>::Cast(info[0]);
    for (unsigned i = 0; i < messageArray->Length(); i++) {
      Local<Value> v = Nan::Get(messageArray, i).ToLocalChecked();
      if (!v->IsNumber()) {
        throw JSException("unexpected array element in array to send, expecting only integers");
      }
      uint32_t b = Nan::To<uint32_t>(v).FromJust();
      message.push_back((unsigned char) b);
    }
    int returnedLength = hid->write(message); // returns number of bytes written

    info.GetReturnValue().Set(Nan::New<Integer>(returnedLength));
  }
  catch (const JSException& e) {
    e.asV8Exception();
  }
}


static void
deinitialize(void*)
{
  // Do nothing
}


void
HID::Initialize(Local<Object> target)
{
  Nan::HandleScope scope;

  // Do nothing

  node::AtExit(deinitialize, 0);

  Local<FunctionTemplate> hidTemplate = Nan::New<FunctionTemplate>(HID::New);
  hidTemplate->InstanceTemplate()->SetInternalFieldCount(1);
  hidTemplate->SetClassName(Nan::New<String>("HID").ToLocalChecked());

  Nan::SetPrototypeMethod(hidTemplate, "close", close);
  Nan::SetPrototypeMethod(hidTemplate, "read", read);
  Nan::SetPrototypeMethod(hidTemplate, "write", write);

  Nan::Set( target,
            Nan::New<String>("HID").ToLocalChecked(),
            Nan::GetFunction( hidTemplate ).ToLocalChecked() );
}


extern "C" {

  static void init (Local<Object> target)
  {
    Nan::HandleScope scope;

    HID::Initialize(target);
  }

  NODE_MODULE(HID, init);
}
