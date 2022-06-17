#pragma once

#include <memory>

#include <vector>
#include <filesystem>
#include "SafeModule.h"
#include "World.h"

using LoadPluginFunc = SafeModule *(*)();

struct SafeLoadedModule{
    std::shared_ptr<SafeModule> instance;
    std::string name;
    std::string version;

    SafeLoadedModule(std::shared_ptr<SafeModule> instance, char const* name, char const* version): instance(instance), name(name), version(version){

    }
};

#if defined(_WIN64) || defined(_WIN32)

    // WINDOWS
    #include <windows.h>

    #define HYBRIS_EVT_EXPORT __declspec(dllexport)
    #define HYBRIS_HANDLE_TYPE HMODULE
    #define HYBRIS_PROGRAM_HANDLE(x) LoadLibraryW(x);
    #define HYBRIS_LOAD_EXTERN(handleVar, toLoad) GetProcAddress(handleVar, toLoad)
    #define HYBRIS_CLOSE_EXTERN FreeLibrary
    #define HYBRIS_LIBRARY_SUFFIX L".dll"

#elif defined(__APPLE__) || defined(__linux)

    // APPLE & LINUX
    #include <dlfcn.h>

    #define HYBRIS_EVT_EXPORT
    #define HYBRIS_HANDLE_TYPE void*
    #define HYBRIS_PROGRAM_HANDLE(x) dlopen(x, RTLD_LAZY);
    #define HYBRIS_LOAD_EXTERN(handleVar, toLoad) dlsym(handleVar, toLoad)
    #define HYBRIS_CLOSE_EXTERN dlclose
    #define HYBRIS_LIBRARY_SUFFIX L".so"

#endif

class SafeModuleManager
{
    LoadPluginFunc _load;
    HYBRIS_HANDLE_TYPE handle;
    char* (*_get_name)();
    char* (*_get_version)();
    std::vector<SafeLoadedModule> instances;
    bool anyPluginNeedTickUpdate{false};
    std::string pathToPluginsFolder;

    void loadPlugin(std::wstring path);

public:
    explicit SafeModuleManager(std::string pathToPluginsFolder): pathToPluginsFolder(pathToPluginsFolder){}
    void loadPlugins();
    void sendTickUpdates(World& world);
};
