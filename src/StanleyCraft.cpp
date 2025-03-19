#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Block.h"

#ifdef _WIN32
const std::string SOURCE_PATH = "C:/Users/Arden Stanley/Desktop/stanleya1293/StanleyCraft";
#endif

int main() {
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(1000, 800, "StanleyCraft", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	glViewport(0, 0, 1000, 800);
	glClearColor(0.5f, 0.0f, 0.0f, 1.0f);

	Shader defaultShader(SOURCE_PATH + "/shaders/default.vertex", SOURCE_PATH + "/shaders/default.fragment");
	defaultShader.use();

	Block grassBlock("", { 0.0f, 0.0f, 0.0f });

	while (!glfwWindowShouldClose(window)) {
		grassBlock.render(defaultShader);
		glfwSwapBuffers(window);
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
	}

	return 0;
}