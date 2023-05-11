new_project(basm CXX 0.1.0)

project_add_library(basm "src/**.cpp;include/**.hpp")
target_include_directories(basm PUBLIC "include")
target_compile_options(basm PRIVATE "/std:c++17")