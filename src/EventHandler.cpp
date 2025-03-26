#include "EventHandler.h"

EventHandler::EventHandler() 
{
	
}

void EventHandler::handleCursorMovement(GLFWwindow *window, double xPos, double yPos)
{
	Camera *camera = reinterpret_cast<Camera*>(glfwGetWindowUserPointer(window));
	static bool first;
	static float xLast;
	static float yLast;
	if (first)
	{
		xLast = xPos;
		yLast = yPos;
		first = false;
	}
	else
	{
		camera->rotate(xPos - xLast, yPos - yLast);
	}
}

void EventHandler::handleKeys(GLFWwindow *window, int key, int scancode, int action, int mods) 
{
	Camera* camera = reinterpret_cast<Camera*>(glfwGetWindowUserPointer(window));
}