#include "auto_sprint.h"
#include "../../3rdparty/loguru/loguru.hpp"

auto_sprint::auto_sprint()
{
    is_enabled = false;
}

void auto_sprint::enable()
{
    if (is_enabled)
    {
        return;
    }
    
    is_enabled = true;
    LOG_F(INFO, "%s Enabled", id.c_str());
}

void auto_sprint::disable()
{
    if (!is_enabled)
    {
        return;
    }

    is_enabled = false;
    LOG_F(INFO, "%s Disabled", id.c_str());
}

