#pragma once
#include "../3rdparty/Java/include/jni.h"

class minecraft
{
public:
    static jobject get_minecraft();
    static jobject get_world();
    static jobject get_player();
private:
    static jclass get_minecraft_class();
};
