#pragma once

#include <iostream>
#include "../PluginManager/IPlugin.h"

class PluginTest: public IPlugin
{
public:
    void onLoad() override;
    std::string command(std::string command, std::string options) override;
};

DEFINE_PLUGIN(PluginTest, "MyPluginTest", "0.0.1")

extern "C" {
    IPlugin* create_plugin(){
        return new PluginTest();
    }
}