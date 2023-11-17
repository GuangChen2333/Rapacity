#pragma once
#include <string>

#include "../client/client.h"

class feature_base
{
public:
    explicit feature_base(const std::string& feature_name);

    std::string name;
    void enable();
    void disable();

    bool is_enabled = false;

    virtual void loop(LPVOID args) = 0;
    
    feature_base(const feature_base& other) = default;
    feature_base& operator=(const feature_base& other) = default;
    feature_base(feature_base&& other) noexcept = default;
    feature_base& operator=(feature_base&& other) noexcept = default;

    virtual ~feature_base() = default;
};
