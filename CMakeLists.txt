# Minimum version for CMake
cmake_minimum_required(VERSION 2.8)

# Project name
project(tanks)

# Include headers
include_directories(include)

# Copy resource files
file(COPY res/ DESTINATION res/)

# Locate and include external libraries
include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
if (${SDL2_FOUND})
include_directories(${SDL2_INCLUDE_DIRS})
endif(${SDL2_FOUND})

pkg_search_module(SDL2IMAGE REQUIRED SDL2_image)
if(${SDL2IMAGE_FOUND})
include_directories(${SDL2IMAGE_INCLUDE_DIRS})
endif(${SDL2IMAGE_FOUND})

# Locate C++ source files
file(GLOB SOURCES "src/*.cpp")

# Specify main executable
add_executable(tanks ${SOURCES})

# Link external libraries
target_link_libraries(tanks ${SDL2_LIBRARIES})
target_link_libraries(tanks ${SDL2IMAGE_LIBRARIES})
