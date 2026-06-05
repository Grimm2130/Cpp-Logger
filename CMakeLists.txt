cmake_minimum_required(VERSION 3.22.0)

set(DIR_EXT_MODS "${CMAKE_CURRENT_SOURCE_DIR}/ExternalModules")

set(LIB_SIMPLE_LOGGER "SimpleLogger")

project(Logger VERSION 1.0.0 LANGUAGES CXX )

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/Inc"
    "${DIR_EXT_MODS}/FileSystemUtils/Inc"
    "${DIR_EXT_MODS}/Templates"
)

add_subdirectory(${DIR_EXT_MODS}/Templates)
add_subdirectory(${DIR_EXT_MODS}/FileSystemUtils)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Src")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Tests")
