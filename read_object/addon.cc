#include <nan.h>
#include <stdio.h>

void print_string_attribute(const v8::Local<v8::Value> value, char *name){
    v8::Local<v8::String> string = value->ToString();
    string->WriteUtf8(name);
    printf("%s", name);
}

void show_array_object(const v8::Local<v8::Value> value){
    v8::Local<v8::Array> arr = v8::Local<v8::Array>::Cast(value);
    char name[30];
    printf("[");
    for(unsigned int i=0; i<arr->Length(); i++){
        print_string_attribute(arr->Get(i), name);
        if(i<arr->Length()-1) printf(", ");
    }
    printf("]");
}

void show_object(const v8::Local<v8::Object> object){
    v8::Local<v8::Array> property = object->GetOwnPropertyNames();

    printf("{");
    char name[30];
    for(unsigned int i=0; i<property->Length(); i++){
        print_string_attribute(property->Get(i), name);
        printf(": ");
        v8::Local<v8::Value> value = object->Get(Nan::New<v8::String>(name).ToLocalChecked());
	
	if(value->IsArray()){
            show_array_object(value);
  	}else if(value->IsObject()){
            show_object(value->ToObject());         
        }else{
            print_string_attribute(object->Get(Nan::New<v8::String>(name).ToLocalChecked()), name);
        }
        if(i<property->Length()-1)printf(", ");
    }
    printf("}");
}

void readObject(const Nan::FunctionCallbackInfo<v8::Value>& info){
  v8::Local<v8::Object> obj = info[0]->ToObject();
  show_object(obj); 
  printf("\n");
}

void InitAll(v8::Local<v8::Object> exports) {
  Nan::HandleScope scope;
  Nan::SetMethod(exports, "readObject", readObject);
}

NODE_MODULE(filter, InitAll)

