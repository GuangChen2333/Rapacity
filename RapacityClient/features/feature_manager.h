#pragma once
#include <memory>
#include <unordered_map>
#include <string>

#include "feature_base.h"

class feature_manager
{
public:
    feature_manager();

    void register_feature(const std::string& id, const std::shared_ptr<feature_base>& instance);
    std::shared_ptr<void> get_feature(const std::string& id);

private:
    std::unordered_map<std::string, std::shared_ptr<void>> features_;
};
