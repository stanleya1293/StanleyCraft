#include "EventHandler.h"
#include "Game.h"

EventHandler::EventHandler() 
{
	
}

void EventHandler::handleCursorMovement(GLFWwindow *window, double xPos, double yPos)
{
	Game *game = reinterpret_cast<Game *>(glfwGetWindowUserPointer(window));
	Camera &camera = game->getRenderer().getCamera();

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
		camera.rotate(xPos - xLast, yPos - yLast);
	}
}

void EventHandler::handleKeys(GLFWwindow *window, int key, int scancode, int action, int mods) 
{
	
}