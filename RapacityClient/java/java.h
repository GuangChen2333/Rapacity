#pragma once

#include "../3rdparty/java/include/jni.h"

enum java_method_type
{
    static_method,
    instance_method
};

enum java_field_type
{
    static_field,
    instance_field
};

class java
{
public:
    JavaVM* java_vm;
    JNIEnv* jni_env;

    JavaVMInitArgs args;
};

extern java java_instance;
