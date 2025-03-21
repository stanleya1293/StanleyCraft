#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Block.h"
#include "Camera.h"
#include "Window.h"

#ifdef _WIN32
const std::string SOURCE_PATH = "C:/Users/Arden Stanley/Desktop/stanleya1293/StanleyCraft";
#endif

int main() {
	Window window(1000, 800, "Test");
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	Shader shader(SOURCE_PATH + "/shaders/default.vertex", SOURCE_PATH + "/shaders/default.fragment");
	shader.use();

	Block block("", { 0.0f, 0.0f, 0.0f });

	Camera camera({ 0.0f, 0.0f, 3.0f }, window);

	while (window.isOpen()) {
		shader.setMat4("model", block.getModel());
		shader.setMat4("view", camera.getView());
		shader.setMat4("projection", camera.getProjection());
		block.render();
		window.update();
	}

	return 0;
}