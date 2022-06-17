#pragma once
#include <string>
#include "World.h"

#define SAFE_EXPORT_SYMBOL extern "C" __declspec (dllexport)

class SafeModule
{
    bool pluginNeedTickUpdate{false};
protected:
    void setReceiveTickUpdate(bool value){pluginNeedTickUpdate = value;}
public:
    SafeModule() = default;
    virtual ~SafeModule() = default;
    virtual void onLoad() = 0;
    virtual void onTick(World& world) = 0;
    bool getReceiveTickUpdate(){return pluginNeedTickUpdate;}
};

#define DEFINE_PLUGIN(classType, pluginName, pluginVersion) \
                                                            \
SAFE_EXPORT_SYMBOL SafeModule* load()                       \
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
