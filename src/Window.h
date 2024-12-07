#ifndef WINDOW_H
#define WINDOW_H
#include "Libs.h"

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
