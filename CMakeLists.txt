cmake_minimum_required (VERSION 3.8)
project(StanleyCraft)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(StanleyCraft src/StanleyCraft.cpp src/Game.cpp src/Shader.cpp src/Window.cpp src/Block.cpp src/Camera.cpp src/Renderer.cpp  src/Texture.cpp "src/Chunk.h" "src/Chunk.cpp")

target_link_libraries(StanleyCraft PRIVATE glfw)
target_link_libraries(StanleyCraft PRIVATE glad::glad)
target_link_libraries(StanleyCraft PRIVATE glm::glm)

target_precompile_headers(StanleyCraft PRIVATE src/dependencies.h)
