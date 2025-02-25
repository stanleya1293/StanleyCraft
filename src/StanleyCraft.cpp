#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

int main() {
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(1000, 800, "StanleyCraft", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	glViewport(0, 0, 1000, 800);
	glClearColor(0.0f, 0.8f, 1.0f, 1.0f);

	Shader meow("../../../shaders/default.vertex", "../../../shaders/default.fragment");

	meow.use();

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}