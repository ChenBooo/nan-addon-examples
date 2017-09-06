#ifndef MY_OBJCET_
#define MY_OBJECT_

#include "nan.h"

namespace myobject {

  class MyObject {
   public:
    static void NewInstance(const Nan::FunctionCallbackInfo<v8::Value>& args);
   private:
    static void Initialize();
    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static void say(const Nan::FunctionCallbackInfo<v8::Value>& args);
  };

} //namespace myobject
#endif  // NODE_PROFILE_

