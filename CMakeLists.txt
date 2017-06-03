cmake_minimum_required(VERSION 3.7)
project(MetalForce)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${MetalForce_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)
find_package(SDL2_Mixer REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR})

set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
target_link_libraries(main ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_MIXER_LIBRARY})

file(COPY "resources" DESTINATION "${CMAKE_BINARY_DIR}")