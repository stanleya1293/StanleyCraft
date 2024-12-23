project(StanleyCraft)

add_executable(StanleyCraft 
	src/main.cpp 
	src/Shader.cpp
	src/Window.cpp
	src/Game.cpp
	src/Model.cpp
	lib/glad/src/glad.c)

add_subdirectory(lib/glfw-3.4)
target_link_libraries(StanleyCraft glfw)

target_include_directories(StanleyCraft PUBLIC lib/glad/include)

add_subdirectory(lib/glm)
target_link_libraries(StanleyCraft glm)
