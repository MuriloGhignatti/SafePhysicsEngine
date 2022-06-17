#include "SafeModuleManager.h"

void SafeModuleManager::loadPlugins() {
    std::filesystem::path const & root = std::filesystem::path(pathToPluginsFolder);
    if(std::filesystem::exists(root) && std::filesystem::is_directory(root)){
        for(auto const & entry: std::filesystem::recursive_directory_iterator(root)){
            if(std::filesystem::is_regular_file(entry) && entry.path().extension() == ".dll"){
                loadPlugin(entry.path().wstring());
            }
        }
    }
}

void SafeModuleManager::loadPlugin(std::wstring path) {
    handle = HYBRIS_PROGRAM_HANDLE(path.c_str())
    _load = (LoadPluginFunc) HYBRIS_LOAD_EXTERN(handle, "load");
    _get_name = (char*(*)()) HYBRIS_LOAD_EXTERN(handle, "name");
    _get_version = (char*(*)()) HYBRIS_LOAD_EXTERN(handle, "version");
    instances.emplace_back(std::shared_ptr<SafeModule>(_load()), _get_name(), _get_version());
    if(instances.back().instance->getReceiveTickUpdate()){
        anyPluginNeedTickUpdate = true;
    }
}

void SafeModuleManager::sendTickUpdates(World& world) {
    if (!anyPluginNeedTickUpdate){
        return;
    }
    for(auto& module: instances){
        if (module.instance->getReceiveTickUpdate()){
            module.instance->onTick(world);
        }
    }
}

