#include "PluginTest.h"

std::string PluginTest::command(std::string command, std::string options)
{
    return command + " " + options;
}
