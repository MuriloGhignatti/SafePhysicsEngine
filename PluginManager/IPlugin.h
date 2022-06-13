#pragma once
#include <string>
#include <memory>

class IPlugin
{
public:
    IPlugin() {}
    virtual ~IPlugin() {}
    virtual std::string command(std::string command, std::string options) {return "";}
};

#define DEFINE_PLUGIN(classType, pluginName, pluginVersion) \
extern "C" {                                                \
std::shared_ptr<IPlugin> load()                             \
{                                                           \
return std::make_shared<classType>();                       \
}                                                           \
                                                            \
const char* name()                                          \
{                                                           \
return pluginName;                                          \
}                                                           \
                                                            \
const char* version()                                       \
{                                                           \
return pluginVersion;                                       \
}                                                           \
}
