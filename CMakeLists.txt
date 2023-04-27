cmake_minimum_required(VERSION 3.10.0)
project(NO_SENSE_NO_LANGUAGE_NO_ERRORS_BYEEEE LANGUAGES NONE)

# Modules
include(cmake/project_module.cmake)

# Projects
NewProject(TCIR CXX 0.1.0)
AddSource(TCIR "src/**.cpp")
ProjectProperty(TCIR CXX_STANDARD 11)