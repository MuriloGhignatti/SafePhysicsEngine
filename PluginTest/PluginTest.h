#pragma once

#include "../PluginManager/IPlugin.h"

class PluginTest: public IPlugin
{
public:
    std::string command(std::string command, std::string options) override;
};

DEFINE_PLUGIN(PluginTest, "MyPluginTest", "0.0.1")
