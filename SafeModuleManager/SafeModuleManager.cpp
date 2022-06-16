#include "SafeModuleManager.h"

SafeModuleManager::SafeModuleManager(std::string pathToPluginsFolder)
{
    handle = HYBRIS_PROGRAM_HANDLE(std::wstring(pathToPluginsFolder.begin(), pathToPluginsFolder.end()).c_str())
    _load = (LoadPluginFunc) HYBRIS_LOAD_EXTERN(handle, "load");
    _get_name = (char*(*)()) HYBRIS_LOAD_EXTERN(handle, "name");
    _get_version = (char*(*)()) HYBRIS_LOAD_EXTERN(handle, "version");
}

std::string SafeModuleManager::get_name()
{
    return _get_name();
}

std::string SafeModuleManager::get_version()
{
    return _get_version();
}


std::shared_ptr<SafeModule> SafeModuleManager::load()
{
    return std::shared_ptr<SafeModule>(_load());
}

