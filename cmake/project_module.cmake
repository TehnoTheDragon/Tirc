# Includes
include(cmake/file_macros.cmake)

# Module
function(NewProject ProjectName LanguageName Version)
    project(${ProjectName} VERSION ${Version} LANGUAGES ${LanguageName})
endfunction(NewProject)

function(AddSource ProjectName)
    CollectFiles(_SOURCE ${ARGV})
    add_executable(${ProjectName} ${_SOURCE})
endfunction(AddSource)

macro(IncludeDirs)
    target_include_directories(${ARGV})
endmacro(IncludeDirs)

function(ProjectProperty ProjectName Property Value)
    set_property(TARGET ${ProjectName} PROPERTY ${Property} ${Value})
endfunction(ProjectProperty)
