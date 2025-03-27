cmake_minimum_required (VERSION 3.8)
project("StanleyCraft")

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(StanleyCraft src/StanleyCraft.cpp src/Game.cpp src/Shader.cpp src/Window.cpp src/Block.cpp src/Camera.cpp src/Renderer.cpp src/EventHandler.cpp)

target_link_libraries(StanleyCraft PRIVATE glfw)
target_link_libraries(StanleyCraft PRIVATE glad::glad)
target_link_libraries(StanleyCraft PRIVATE glm::glm)
