#pragma once
#include "../3rdparty/java/include/jawt_md.h"
#include "../features/feature_manager.h"

class client
{
public:
    client();

    void static start();
private:
    unsigned long static loop(LPVOID args);
    
    feature_manager manager_;
};
