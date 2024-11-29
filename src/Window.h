#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
	Window();
	~Window();
	bool isRunning();
	void update();
private:
	GLFWwindow* m_window;
};

#endif
