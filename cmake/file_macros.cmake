macro(WriteFile File Content)
    file(WRITE ${File} ${Content})
endmacro(WriteFile)

macro(AppendFile File Content)
    file(APPEND ${File} ${Content})
endmacro(AppendFile)

macro(ReadFile File Out)
    file(READ ${File} ${Content} ${Out})
endmacro(ReadFile)

macro(CollectFiles Out)
    if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.11.0")
        file(GLOB_RECURSE ${Out} CONFIGURE_DEPENDS ${ARGV})
    else()
        file(GLOB ${Out} ${ARGV})
    endif()
endmacro(CollectFiles)
