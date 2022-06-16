add_library(test SHARED PluginTest.cpp)


target_link_libraries(test PRIVATE safeModule)