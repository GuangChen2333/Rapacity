#include "feature_base.h"

feature_base::feature_base(const std::string& feature_name)
{
    name = feature_name;
}

void feature_base::enable()
{
    if (!is_enabled) is_enabled=true;
}

void feature_base::disable()
{
    if(is_enabled) is_enabled=false;
}


