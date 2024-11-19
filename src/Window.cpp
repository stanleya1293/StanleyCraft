#include "Window.h"

Window::Window() {
	glfwInit();
	windowID = glfwCreateWindow(1000, 800, "StanleyCraft", NULL, NULL);
	glfwMakeContextCurrent(windowID);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

Window::~Window() {
	glfwDestroyWindow(windowID);
	glfwTerminate();
}

void Window::update() {
	
	glfwSwapBuffers(windowID);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT);
}