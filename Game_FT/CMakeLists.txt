set(HEADER_FILES
	
)

set(SOURCE_FILES
	main.cpp
)

add_executable(Game_FT ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_FT Pierogi)

include_directories(../Pierogi/include)