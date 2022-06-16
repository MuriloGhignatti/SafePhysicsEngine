#include "PluginHandle.h"

PluginHandle::PluginHandle(std::string filename)
{
    handle = HYBRIS_PROGRAM_HANDLE(std::wstring(filename.begin(), filename.end()).c_str())
    _load = (LoadPluginFunc) HYBRIS_LOAD_EXTERN(handle, "load");
    _get_name = (char*(*)()) HYBRIS_LOAD_EXTERN(handle, "name");
    _get_version = (char*(*)()) HYBRIS_LOAD_EXTERN(handle, "version");
}

std::string PluginHandle::get_name()
{
    return _get_name();
}

std::string PluginHandle::get_version()
{
    return _get_version();
}


std::shared_ptr<IPlugin> PluginHandle::load()
{
    return std::shared_ptr<IPlugin>(_load());
}

