#include "feature_manager.h"

#include "movement/auto_sprint.h"

feature_manager::feature_manager()
{
    register_feature(auto_sprint::id, std::make_shared<auto_sprint>());
}

void feature_manager::register_feature(const std::string& id, const std::shared_ptr<feature_base>& instance)
{
    features_[id] = instance;
}

std::shared_ptr<void> feature_manager::get_feature(const std::string& id)
{
    if (!features_.contains(id))
    {
        return nullptr;
    }

    return features_[id];
}
