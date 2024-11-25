#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
	Window(int width, int height, std::string title);
	~Window();
	bool isRunning();
	void update();
private:
	GLFWwindow* windowID;
};

#endif WINDOW_H