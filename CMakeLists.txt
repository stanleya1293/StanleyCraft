cmake_minimum_required (VERSION 3.8)
project("StanleyCraft")

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

add_executable(StanleyCraft src/StanleyCraft.cpp "src/Shader.h" "src/Shader.cpp" "src/Window.h" "src/Window.cpp")

target_link_libraries(StanleyCraft PRIVATE glfw)
target_link_libraries(StanleyCraft PRIVATE glad::glad)
