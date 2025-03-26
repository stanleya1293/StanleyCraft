#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Shader.h"
#include "Block.h"
#include "Camera.h"
#include "Window.h"
#include "Renderer.h"

#ifdef _WIN32
//const std::string SOURCE_PATH = "C:/Users/Arden Stanley/Desktop/stanleya1293/StanleyCraft";
const std::string SOURCE_PATH = "C:/Users/Arden/source/repos/stanleya1293/StanleyCraft";
#endif

int main() {
	Window window(1000, 800, "Test");
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	Shader shader = Shader(SOURCE_PATH + "/shaders/default.vertex", SOURCE_PATH + "/shaders/default.fragment");
	Camera camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f), window);

	Block block = Block("", glm::vec3(0.0f, 0.0f, 0.0f));

	Renderer renderer = Renderer(camera, shader);

	renderer.addBlock(block);

	while (window.isOpen()) {
		renderer.update();
		window.update();
	}

	return 0;
}