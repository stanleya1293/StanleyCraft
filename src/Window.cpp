#include "Window.h"

Window::Window(int width, int height, const std::string& title)
{
	m_width = width;
	m_height = height;
	m_title = title;
	m_aspectRatio = (float) width / (float) height;
	glfwInit();
	m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(m_window);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	glViewport(0, 0, m_width, m_height);
}

const void Window::update()
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT);
}

