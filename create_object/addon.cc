#include <nan.h>
#include "myobject.h"

namespace demo {


void CreateObject(const Nan::FunctionCallbackInfo<v8::Value>& args) {
  myobject::MyObject::NewInstance(args);
}

void InitAll(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
  Nan::SetMethod(module, "exports", CreateObject);
}

NODE_MODULE(addon, InitAll)

}  // namespace demo

