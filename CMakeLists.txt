# Project
cmake_minimum_required(VERSION 4.0.1)
project(NebulaEngine LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 20)

# Debug
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -gdwarf-4 -O0")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "-Wl,-debug")
endif()

# Directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Gives compile_commands.json for LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
include(FetchContent)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.17.0)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.5.1
)
FetchContent_MakeAvailable(glfw)


# Sub CMake files
add_subdirectory(src/core)
add_subdirectory(src/app)
