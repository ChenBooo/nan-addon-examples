#include <nan.h>

void Method(const Nan::FunctionCallbackInfo<v8::Value>& info){
  info.GetReturnValue().Set(Nan::New("world").ToLocalChecked());
}

void Init(v8::Local<v8::Object> exports){
  Nan::HandleScope scope;
  
  Nan::SetMethod(exports, "hello", Method);
}

NODE_MODULE(hello, Init)
