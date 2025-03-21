#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
	Window(int width, int height, const std::string &title);
	inline float getAspectRatio() const { return aspectRatio; }
	inline bool isOpen() const { return !glfwWindowShouldClose(baseWindow); }
	void update() const;
private:
	int width;
	int height;
	float aspectRatio;
	std::string title;
	GLFWwindow* baseWindow;
};

#endif
