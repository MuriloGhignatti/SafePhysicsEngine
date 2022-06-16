#pragma once
#include <string>

#define SAFE_EXPORT_SYMBOL extern "C" __declspec (dllexport)

class SafeModule
{
public:
    SafeModule() = default;
    virtual ~SafeModule() = default;
    virtual void onLoad() = 0;
    virtual std::string command(std::string& command, std::string& options) = 0;
};

#define DEFINE_PLUGIN(classType, pluginName, pluginVersion) \
                                                            \
SAFE_EXPORT_SYMBOL SafeModule* load()                          \
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

