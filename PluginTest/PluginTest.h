#pragma once

#include <iostream>
#include "../PluginManager/IPlugin.h"

class PluginTest: public IPlugin
{
public:
    void onLoad() override;
    std::string command(std::string command, std::string options) override;
};
