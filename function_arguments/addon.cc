#include <nan.h>

void Add(const Nan::FunctionCallbackInfo<v8::Value>& info){
    if(info.Length() < 2){
        Nan::ThrowTypeError("Wrong number of arguments");
        return;
    }

    if(!info[0]->IsNumber() || !info[1]->IsNumber()){
	Nan::ThrowTypeError("Wrong arguments");
   	return;
    }

    double arg0 = info[0]->NumberValue();
    double arg1 = info[1]->NumberValue();
    v8::Local<v8::Number> num = Nan::New(arg0 + arg1);
    
    info.GetReturnValue().Set(num);
}

void Init(v8::Local<v8::Object> exports){
  Nan::HandleScope scope;
  
  Nan::SetMethod(exports, "add", Add);
}

NODE_MODULE(addon, Init)
