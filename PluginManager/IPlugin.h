#pragma once
#include <string>

class IPlugin
{
public:
    IPlugin() {}
    virtual ~IPlugin() {}
    virtual void onLoad() {}
    virtual std::string command(std::string command, std::string options) {return "";}
};

#define DEFINE_PLUGIN(classType, pluginName, pluginVersion) \
extern "C" {                                                \
IPlugin* load()                                             \
{                                                           \
return new classType();                                     \
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
