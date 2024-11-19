#ifndef WINDOW_H
#define WIDNOW_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Window {
public:
	Window();
	~Window();
	void update();
	inline bool isRunning() { return glfwWindowShouldClose(windowID); };
private:
	GLFWwindow* windowID;
};

#endif