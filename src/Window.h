#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
	Window(int width, int height, const std::string &title);
	~Window();
private:
	int width;
	int height;
	std::string title;
	GLFWwindow* baseWindow;
};

#endif
