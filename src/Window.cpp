#include "Window.h"

Window::Window() : 
	m_width(0), 
	m_height(0), 
	m_title(""), 
	m_windowID(nullptr)
{}

Window::Window(int width, int height, const std::string &title) :
	m_width(width),
	m_height(height),
	m_title(title),
	m_windowID(nullptr)
{
	if (!glfwInit())
	{
		std::cerr << "ERROR INITIALIZING GLFW" << std::endl;
		std::exit(1);
	}
	
	m_windowID = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(m_windowID);
	
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
	{
		std::cerr << "ERROR INITIALIZING GLAD" << std::endl;
		std::exit(1);
	}
}

void Window::update() 
{
	glfwSwapBuffers(m_windowID);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT);
}

bool Window::running()
{
	return (!glfwWindowShouldClose(m_windowID));
}
