#include "myobject.h"

Nan::Persistent<v8::Function> MyObject::constructor;

MyObject::MyObject(double value) : value_(value) {
}

MyObject::~MyObject() {
}

void MyObject::Init(v8::Local<v8::Object> exports){
  Nan::HandleScope scope;
  
  v8::Local<v8::FunctionTemplate> tp1 = Nan::New<v8::FunctionTemplate>(New);
  tp1->SetClassName(Nan::New("MyObject").ToLocalChecked());
  tp1->InstanceTemplate()->SetInternalFieldCount(1);

  Nan::SetPrototypeMethod(tp1, "value", GetValue);
  Nan::SetPrototypeMethod(tp1, "plusOne", PlusOne);
  Nan::SetPrototypeMethod(tp1, "multiply", Multiply);

  constructor.Reset(tp1->GetFunction());
  exports->Set(Nan::New("MyObject").ToLocalChecked(), tp1->GetFunction());
}

void MyObject::New(const Nan::FunctionCallbackInfo<v8::Value>& info){
  if(info.IsConstructCall()){
    double value = info[0]->IsUndefined() ? 0 : info[0]->NumberValue();
    MyObject* obj = new MyObject(value);
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  }else{
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = { info[0] };
    v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
    info.GetReturnValue().Set(cons->NewInstance(argc, argv));
  }
}

void MyObject::GetValue(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  MyObject* obj = ObjectWrap::Unwrap<MyObject>(info.Holder());
  info.GetReturnValue().Set(Nan::New(obj->value_));
}

void MyObject::PlusOne(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  MyObject* obj = ObjectWrap::Unwrap<MyObject>(info.Holder());
  obj->value_ += 1;
  info.GetReturnValue().Set(Nan::New(obj->value_));
}

void MyObject::Multiply(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  MyObject* obj = ObjectWrap::Unwrap<MyObject>(info.Holder());
  double multiple = info[0]->IsUndefined() ? 1 : info[0]->NumberValue();

  v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);

  const int argc = 1;
  v8::Local<v8::Value> argv[argc] = { Nan::New(obj->value_ * multiple) };

  info.GetReturnValue().Set(cons->NewInstance(argc, argv));
}
