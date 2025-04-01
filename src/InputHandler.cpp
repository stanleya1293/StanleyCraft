#include "InputHandler.h"

void InputHandler::initialize() {
	glfwSetCursorPosCallback(Window::getBaseWindow(), handleCursorCallback);
}

void InputHandler::handleCursorCallback(GLFWwindow *window, double xPos, double yPos) {
	Camera &camera = Renderer::getCamera();
	if (firstCursor) {
		xCursor = xPos;
		yCursor = yPos;
		firstCursor = false;
	}
	else {
		camera.rotate(xPos - xCursor, yCursor - yPos);
		xCursor = xPos;
		yCursor = yPos;
	}
}

void InputHandler::processInput() {
	Camera& camera = Renderer::getCamera();
	glfwPollEvents();
	if (glfwGetKey(Window::getBaseWindow(), GLFW_KEY_W)) {
		camera.move(Camera::Forward);
	}
	if (glfwGetKey(Window::getBaseWindow(), GLFW_KEY_A)) {
		camera.move(Camera::Left);
	}
	if (glfwGetKey(Window::getBaseWindow(), GLFW_KEY_S)) {
		camera.move(Camera::Backward)
	}
	if (glfwGetKey(Window::getBaseWindow(), GLFW_KEY_D)) {
		camera.move(Camera::Right);
	}

}