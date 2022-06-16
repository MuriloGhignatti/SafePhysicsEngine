#include "PluginTest.h"

std::string PluginTest::command(std::string command, std::string options)
{
    return command + " " + options;
}

void PluginTest::onLoad()
{
    std::cout << "PluginTest Loaded" << "\n";
}

DEFINE_PLUGIN(PluginTest, "plugin safe", "0.0.1")