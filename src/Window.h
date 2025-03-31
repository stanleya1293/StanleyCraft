#ifndef WINDOW_H
#define WINDOW_H

#include "dependencies.h"
#include "EventHandler.h"

class Window {
public:
	Window(int width, int height, const std::string &title);
	static inline float getAspectRatio() { return m_aspectRatio; }
	static inline bool isOpen() { return !glfwWindowShouldClose(m_window); }
	static void update();
private:
	static int m_width;
	static int m_height;
	static float m_aspectRatio;
	static std::string m_title;
	static GLFWwindow* m_window;
};


#endif
