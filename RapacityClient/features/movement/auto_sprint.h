#pragma once

#include "../feature_base.h"

class auto_sprint final : public feature_base
{
public:
    auto_sprint();

    inline static std::string id = "AutoSprint";
    
    void loop(LPVOID args) override;
};
