cmake_minimum_required(VERSION 3.10.0)
project(NO_SENSE_NO_LANGUAGE_NO_ERRORS_BYEEEE LANGUAGES NONE)

# Modules
include("cmake/project_module.cmake")

# Projects
NewProject(TIRC CXX 0.1.0)
AddSource(TIRC "src/**.cpp" "include/**.hpp")
IncludeDirs(TIRC PUBLIC "include/")
ProjectProperty(TIRC CXX_STANDARD 11)