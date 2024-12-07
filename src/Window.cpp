#include "Window.h"

Window::Window() : m_window(NULL) {
  if (!glfwInit()) {
    std::cout << "ERROR: GLFW INIT FAILED" << std::endl;
  }
  m_window = glfwCreateWindow(800, 800, "StanleyCraft", NULL, NULL);
  if (!m_window) {
    std::cout << "ERROR: WINDOW CREATION FAILED" << std::endl;
  }
  glfwMakeContextCurrent(m_window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "ERROR: GLAD GL LOADING FAILED" << std::endl;
  }
}

Window::~Window() {
  glfwDestroyWindow(m_window);
  glfwTerminate();
}

bool Window::isRunning() { return (!glfwWindowShouldClose(m_window)); }

void Window::update() {
  glfwSwapBuffers(m_window);
  glfwPollEvents();
  glClear(GL_COLOR_BUFFER_BIT);
}
