#pragma once
#include <string>

#define SAFE_EXPORT_SYMBOL extern "C" __declspec (dllexport)

class IPlugin
{
public:
    IPlugin() {}
    virtual ~IPlugin() {}
    virtual void onLoad() {}
    virtual std::string command(std::string command, std::string options) {return "";}
};

#define DEFINE_PLUGIN(classType, pluginName, pluginVersion) \
                                                            \
SAFE_EXPORT_SYMBOL IPlugin* load()                          \
{                                                           \
return new classType();                                     \
}                                                           \
                                                            \
SAFE_EXPORT_SYMBOL const char* name()                       \
{                                                           \
return pluginName;                                          \
}                                                           \
                                                            \
SAFE_EXPORT_SYMBOL const char* version()                    \
{                                                           \
return pluginVersion;                                       \
}                                                           \

