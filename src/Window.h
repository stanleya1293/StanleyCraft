#ifndef WINDOW_H
#define WINDOW_H

#include "dependencies.h"

enum Keys {
	W,
	A,
	S,
	D
};

class Window {
public:
	Window(int width, int height, const std::string &title);
	inline float getAspectRatio() { return m_aspectRatio; }
	inline bool isOpen() { return !glfwWindowShouldClose(m_window); }
	void update();
	inline GLFWwindow* getBaseWindow() { return m_window; }
	void addKeyCallback(Keys key, const std::function<void()>& callback);  
	void onKeyCallback(int key);
	
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
private:
	int m_width;
	int m_height;
	float m_aspectRatio;
	std::string m_title;
	GLFWwindow* m_window;

	std::map<Keys, std::function<void()>> m_callbacks;
};


#endif
