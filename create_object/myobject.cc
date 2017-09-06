#include "myobject.h"

namespace myobject{
  Nan::Persistent<v8::FunctionTemplate> MyObject::constructor;

  NAN_METHOD(EmptyMethod) {}

  void MyObject::Initialize () {
    Nan::HandleScope scope;

    v8::Local<v8::FunctionTemplate> f = Nan::New<v8::FunctionTemplate>(EmptyMethod);
    
    f->SetClassName(Nan::New<v8::String>("MyObject").ToLocalChecked());
    f->InstanceTemplate()->SetInternalFieldCount(1);

    // Prototype
    Nan::SetPrototypeMethod(f, "say", MyObject::say);
    constructor.Reset(f);
  }

  void MyObject::say(const Nan::FunctionCallbackInfo<v8::Value>& args){
    args.GetReturnValue().Set(Nan::New("hello world").ToLocalChecked());
  }

  void MyObject::NewInstance(const Nan::FunctionCallbackInfo<v8::Value>& args)
  {
    if (constructor.IsEmpty()) {
      MyObject::Initialize();
    }

    v8::Local<v8::Object> instance = Nan::New(constructor)->InstanceTemplate()->NewInstance();
    args.GetReturnValue().Set(instance);
  }

  
}
