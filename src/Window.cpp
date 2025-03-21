#include "Window.h"

Window::Window(int width, int height, const std::string& title) :
	width(width), height(height), title(title),
	aspectRatio((float) width / (float) height)
{
	glfwInit();
	baseWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(baseWindow);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	glViewport(0, 0, width, height);
}

void Window::update() const
{
	glfwSwapBuffers(baseWindow);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT);
}