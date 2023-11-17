#pragma once
#include <memory>
#include <unordered_map>

#include "movement/auto_sprint.h"

class feature_manager
{
public:
    feature_manager();
    
    auto_sprint feature_auto_sprint;
private:
    template<typename T>
    using feature_ptr = std::shared_ptr<T>;
    std::unordered_map<std::string, feature_ptr<void>> features_;
};
