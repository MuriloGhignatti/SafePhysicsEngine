#pragma once

#include <iostream>
#include "SafeModule.h"

class PluginTest: public SafeModule
{
public:
    void onLoad() override;
    std::string command(std::string& command, std::string& options) override;
};
