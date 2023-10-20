cmake_minimum_required(VERSION 3.24)

project(Game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(Pierogi)
add_subdirectory(Game_FT)
add_subdirectory(glfw)

if(WIN32)
	add_definitions(-DPIEROGI_MSCPP)
elseif(LINUX)
	add_definitions(-DPIEROGI_LINUX)
elseif(APPLE)
	add_definitions(-DPIEROGI_APPLE)
endif()

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Game_FT)

