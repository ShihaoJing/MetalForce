cmake_minimum_required(VERSION 3.7)
project(MetalForce)

set(CMAKE_CXX_STANDARD 11)
include(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})

include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(main ${SDL2_LIBRARIES})