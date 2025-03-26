#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "dependencies.h"
#include "Camera.h"

class EventHandler {
public:
	
	EventHandler();
	
	static void handleCursorMovement(GLFWwindow* window, double xPos, double yPos);
	
	static void handleKeys(GLFWwindow* window, int key, int scancode, int action, int mods);

	
};

#endif
