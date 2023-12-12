set(HEADER_FILES
	include/Pierogi.h
	PierogiApp.h
	Events.h
	keys.h
	PRWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
	Picture.h
	PictureImplementation.h
	GLFWCode/OpenGLPicture.h
	Renderer.h
	RendererImplementation.h
	GLFWCode/OpenGLRenderer.h
	Shader.h
	ShaderImplementation.h
	GLFWCode/OpenGLShader.h
	Unit.h
	Utilities.h
)

set(SOURCE_FILES
	PRWindow.cpp
	GLFWCode/GLFWImplementation.cpp
	Events.cpp
	GLFWCode/OpenGLPicture.cpp
	GLFWCode/OpenGLRenderer.cpp
	GLFWCode/OpenGLShader.cpp
	Picture.cpp
	Renderer.cpp
	Shader.cpp
	Unit.cpp
)

add_definitions(-DPR_DEBUG=2)
add_definitions(-DPIEROGI_LIB)
add_definitions(-DPIEROGI_MSCPP)

include_directories(../Pierogi)
include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)

add_library(Pierogi SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Pierogi PRIVATE pch.h)

target_link_libraries(Pierogi glfw)
target_link_libraries(Pierogi glad)
target_link_libraries(Pierogi stbi)