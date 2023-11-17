#include "client.h"

#include <thread>
#include "../3rdparty/java/include/jawt_md.h"
#include "../3rdparty/loguru/loguru.hpp"
#include "../features/feature_manager.h"
#include "../minecraft/minecraft.h"

client::client()
{
    manager_ = feature_manager();
}


void client::start()
{
    client instance;
    
    LOG_F(INFO, "Waiting for game starting...");
    
    CreateThread(nullptr, 0, &loop, &instance, 0, nullptr);
}

unsigned long client::loop(const LPVOID args)
{
    auto instance = static_cast<client*>(args);
    bool minecraft_ready = false;
    while (true)
    {
        if (!minecraft::get_minecraft()) continue;
        if (!minecraft::get_player()) continue;
        if (!minecraft::get_world()) continue;

        if (!minecraft_ready)
        {
            minecraft_ready = true;
            LOG_F(INFO, "Minecraft Attached!");
        }

        
        
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
