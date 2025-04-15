#include "Window.h"

Window::Window(int width, int height, const std::string& title) : 
	m_width(width), m_height(height), m_title(title), 
	m_aspectRatio((float) width / (float) height), m_window(nullptr) {

	glfwInit();
	m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(m_window);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	glViewport(0, 0, m_width, m_height);
	//glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glEnable(GL_DEPTH_TEST);
	glfwSetWindowUserPointer(m_window, this);
	glfwSetKeyCallback(m_window, keyCallback);
}

void Window::update() {
	glfwPollEvents();
	glfwSwapBuffers(m_window);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
}

void Window::addKeyCallback(Keys key, const std::function<void()>& callback) {
	m_callbacks[key] = callback;
}

void Window::onKeyCallback(int key) {
	Keys activeKey;
	switch (key) {
	case GLFW_KEY_A:
		activeKey = Keys::A;
		std::cout << "A";
		break;
	case GLFW_KEY_W:
		activeKey = Keys::W;
		std::cout << "W";
		break;
	case GLFW_KEY_S:
		activeKey = Keys::S;
		std::cout << "S";
		break;
	case GLFW_KEY_D:
		activeKey = Keys::D;
		std::cout << "D";
		break;
	}
	m_callbacks[activeKey]();
}

void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	Window* gameWindow = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
	gameWindow->onKeyCallback(key);
}

