set(HEADER_FILES
	include/Pierogi.h
	PierogiApp.h
	Utilities.h
)

set(SOURCE_FILES
	placeholder.cpp
)

add_definitions(-DPR_DEBUG=2)
add_definitions(-DPIEROGI_LIB)

add_library(Pierogi SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Pierogi PRIVATE pch.h)