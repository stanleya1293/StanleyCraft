#include "EventHandler.h"
#include "Game.h"

EventHandler::EventHandler() {

}

void EventHandler::handleCursorMovement(GLFWwindow *window, double xPos, double yPos) {
	Camera camera = Renderer::getCamera();

	static bool first = true;
	static float xLast;
	static float yLast;
	if (first) {
		xLast = xPos;
		yLast = yPos;
		first = false;
	}
	else {
		camera.rotate(xPos - xLast, yPos - yLast);
	}
}

void EventHandler::handleKeys(GLFWwindow *window, int key, int scancode, int action, int mods) {
	
}