set(HEADER_FILES
	BattleBoard.h
	Tile.h
)

set(SOURCE_FILES
	main.cpp
	BattleBoard.cpp
	Tile.cpp
)

add_executable(Game_FT ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_FT Pierogi)

include_directories(../Pierogi/include)
include_directories(../glad/include)
