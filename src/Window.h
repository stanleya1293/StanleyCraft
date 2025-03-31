#ifndef WINDOW_H
#define WINDOW_H

#include "dependencies.h"

class Window {
public:
	static void initialize(int width, int height, const std::string &title);
	static inline float getAspectRatio() { return m_aspectRatio; }
	static inline bool isOpen() { return !glfwWindowShouldClose(m_window); }
	static void update();
	static inline GLFWwindow* getBaseWindow() { return m_window; }
private:
	inline static int m_width;
	inline static int m_height;
	inline static float m_aspectRatio;
	inline static std::string m_title;
	inline static GLFWwindow* m_window;
};


#endif
