#pragma once

#include "../3rdparty/java/include/jni.h"

class java
{
public:
    JavaVM* java_vm;
    JNIEnv* jni_env;

    JavaVMInitArgs args;
};

extern java java_instance;
