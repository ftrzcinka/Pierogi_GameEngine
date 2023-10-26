set(HEADER_FILES
	include/Pierogi.h
	PierogiApp.h
	Utilities.h
	PRWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
)

set(SOURCE_FILES
	PRWindow.cpp
	GLFWCode/GLFWImplementation.cpp
)

add_definitions(-DPR_DEBUG=2)
add_definitions(-DPIEROGI_LIB)
add_definitions(-DPIEROGI_MSCPP)

include_directories(../Pierogi)
include_directories(../glfw/include)

add_library(Pierogi SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Pierogi PRIVATE pch.h)

target_link_libraries(Pierogi glfw)