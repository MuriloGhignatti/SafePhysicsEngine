#include "PluginHandle.h"

PluginHandle::PluginHandle(std::string filename)
{
    handle = HYBRIS_PROGRAM_HANDLE(std::wstring(filename.begin(), filename.end()).c_str())
    _load = (LoadPluginFunc) HYBRIS_LOAD_EXTERN(handle, "load");
    _get_name = (char*(*)()) HYBRIS_LOAD_EXTERN(handle, "get_name");
    _get_version = (char*(*)()) HYBRIS_LOAD_EXTERN(handle, "get_version");
}
