#pragma once
#include <thread>

#include "../3rdparty/java/include/jawt_md.h"
#include "../features/feature_manager.h"
#include "../3rdparty/loguru/loguru.hpp"

class client
{
public:
    client();

    void static start();
private:
    unsigned long static loop(LPVOID args);
    
    feature_manager manager_;
};
