cmake_minimum_required(VERSION 3.10.0)
project(BASMProject LANGUAGES NONE)

# Modules
include("cmake/project_module.cmake")

# Projects
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/basm/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/sandbox/")