add_library(safeEngineCore STATIC Objects/SafeObject/SafeObject.cpp Objects/SafeSphere/SafeSphere.cpp World.cpp World.h)

target_include_directories(safeEngineCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})