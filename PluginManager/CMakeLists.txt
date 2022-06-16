add_library(plugin_manager STATIC PluginHandle.cpp IPlugin.cpp)

target_include_directories(plugin_manager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})