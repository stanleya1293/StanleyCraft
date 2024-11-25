#include "Window.h"

Window::Window(int width, int height, std::string title) {
	if (!glfwInit()) {
		std::cout << "Error initializing GLFW!" << std::endl;
	}
	windowID = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (!windowID) {
		std::cout << "Error creating window!" << std::endl;
	}
	glfwMakeContextCurrent(windowID);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Error initializing GLAD!" << std::endl;
	}

	glViewport(0, 0, width, height);
}

bool Window::isRunning() {
	if (glfwWindowShouldClose(windowID)) {
		return false;
	}
	else {
		return true;
	}
}

void Window::update() {
	glfwSwapBuffers(windowID);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT);
}

Window::~Window() {
	glfwDestroyWindow(windowID);
	glfwTerminate();
}