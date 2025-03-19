#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

#ifdef _WIN32
const std::string SOURCE_PATH = "C:/Users/Arden/source/repos/stanleya1293/StanleyCraft";
#endif

int main() {
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(1000, 800, "StanleyCraft", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	glViewport(0, 0, 1000, 800);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	Shader defaultShader(SOURCE_PATH + "/shaders/default.vertex", SOURCE_PATH + "/shaders/default.fragment");
	defaultShader.use();

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}