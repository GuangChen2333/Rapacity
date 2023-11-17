#include <stdexcept>
#include <windows.h>
#include "java/java.h"
#include "client/client.h"
#include "3rdparty/loguru/loguru.hpp"

unsigned long initialize(LPVOID args)
{
    jsize size;

    // Check JVM
    if (JNI_GetCreatedJavaVMs(&java_instance.java_vm, 1, &size) != JNI_OK || size == 0)
    {
        LOG_F(ERROR, "Cannot get Java VM.");
        throw std::runtime_error("Cannot get Java VM.");
    }

    // Check if attach the thread to JVM
    if (
        const auto jni_env_ptr_ptr = reinterpret_cast<void**>(&java_instance.jni_env);
        java_instance.java_vm->GetEnv(jni_env_ptr_ptr, JNI_VERSION_1_6) == JNI_EDETACHED)
    {
        // Unattached
        LOG_F(INFO, "Attach the thread to Java VM.");
        if (
            const jint result = java_instance.java_vm->AttachCurrentThread(jni_env_ptr_ptr, nullptr);
            result != JNI_OK
        )
        {
            LOG_F(ERROR, "Cannot attach the thread to Java VM: %ld", result);
            throw std::runtime_error("Cannot attach the thread to Java VM.");
        }
    }

    // Check JNI Environment
    if (java_instance.jni_env == nullptr)
    {
        LOG_F(ERROR, "Cannot get Java Environment.");
        throw std::runtime_error("Cannot get Java Environment.");
    }

    LOG_F(INFO, "JVM Attached!");
    
    client::start();
    
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call != DLL_PROCESS_ATTACH)
    {
        CreateThread(nullptr, 0, &initialize, nullptr, 0, nullptr);
    }
    return TRUE;
}
