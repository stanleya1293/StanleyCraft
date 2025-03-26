#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "EventHandler.h"

class Window {
public:

	Window(int width, int height, const std::string &title);

	inline float getAspectRatio() const { return m_aspectRatio; }

	inline bool isOpen() const { return !glfwWindowShouldClose(m_window); }

	void update() const;

private:

	int m_width;

	int m_height;

	float m_aspectRatio;

	std::string m_title;

	GLFWwindow* m_window;

};

#endif
