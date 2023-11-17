// ReSharper disable StringLiteralTypo
// ReSharper disable CommentTypo

#include "minecraft.h"

#include "../java/java.h"

jclass minecraft::get_minecraft_class()
{
    // Class:
    // ave => net/minecraft/client/Minecraft
    // public net.minecraft.client.Minecraft
    return java_instance.jni_env->FindClass("ave");
}

jobject minecraft::get_minecraft()
{
    // Function:
    // A => func_71410_x => getMinecraft
    // public net.minecraft.client.Minecraft func_71410_x()Lnet/minecraft/client/Minecraft;
    return java_instance.jni_env->CallStaticObjectMethod(
        get_minecraft_class(),
        java_instance.jni_env->GetStaticMethodID(
            get_minecraft_class(),
            "A",
            "()Lave"
        )
    );
}

jobject minecraft::get_world()
{
    // Class:
    // bdb => net/minecraft/client/multiplayer/WorldClient
    // public net.minecraft.client.multiplayer.WorldClient
    // Field:
    // f => field_71441_e => theWorld
    // public net.minecraft.client.Minecraft field_71441_e

    return java_instance.jni_env->GetObjectField(
        get_minecraft(),
        java_instance.jni_env->GetFieldID(
            get_minecraft_class(),
            "f",
            "Lbdb;"
        )
    );
}

jobject minecraft::get_player()
{
    // Class:
    // bew => net/minecraft/client/entity/EntityPlayerSP
    // public net.minecraft.client.entity.EntityPlayerSP
    // Field:
    // h => field_71439_g => thePlayer
    // public net.minecraft.client.Minecraft field_71439_g
    return java_instance.jni_env->GetObjectField(
        get_minecraft(),
        java_instance.jni_env->GetFieldID(
            get_minecraft_class(),
            "h",
            "Lbew;"
        )
    );
}
