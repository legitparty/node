#include "node.h"

namespace {

using v8::FunctionCallbackInfo;
using v8::Local;
using v8::Object;
using v8::Value;

void GetExecutionAsyncId(const FunctionCallbackInfo<Value>& args) {
  args.GetReturnValue().Set(
    node::AsyncHooksGetExecutionAsyncId(args.GetIsolate()));
}

void GetTriggerAsyncId(const FunctionCallbackInfo<Value>& args) {
  args.GetReturnValue().Set(
    node::AsyncHooksGetTriggerAsyncId(args.GetIsolate()));
}

void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "getExecutionAsyncId", GetExecutionAsyncId);
  NODE_SET_METHOD(exports, "getTriggerAsyncId", GetTriggerAsyncId);
}

}  // namespace

NODE_MODULE(binding, Initialize)
