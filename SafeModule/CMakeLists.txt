add_library(safeModule STATIC SafeModule.cpp)

target_link_libraries(safeModule PUBLIC safeEngineCore)
target_include_directories(safeModule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})