#pragma once
#include <string>

class auto_sprint
{
public:
    auto_sprint();

    std::string id = "AutoSprint";
    
    void enable();
    void disable();

    bool is_enabled;
};
