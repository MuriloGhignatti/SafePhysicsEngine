cmake_minimum_required(VERSION 3.12.3)

project(SafeEngineCore)

set(CMAKE_CXX_STANDARD 17)

include_directories("C:\\Users\\muril\\Downloads\\eigen-3.4.0\\eigen-3.4.0\\Eigen")

add_executable(safePhysicsEngine main.cpp)

add_subdirectory(SafeModule)
add_subdirectory(SafeModuleManager)
add_subdirectory(SafeCollisionModule)
add_subdirectory(SafeEngineCore)

target_link_libraries(safePhysicsEngine PRIVATE safeModuleManager)