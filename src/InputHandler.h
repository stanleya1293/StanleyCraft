#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "dependencies.h"
#include "Renderer.h"
#include "Window.h"

class InputHandler {
public:
	static void initialize();
	static void handleCursorCallback(GLFWwindow* window, double xPos, double yPos);
	static void processInput();
private:
	inline static bool firstCursor = true;
	inline static float xCursor;
	inline static float yCursor;
	inline static struct {
		bool a = false;
		bool w = false;
		bool s = false;
		bool d = false;
	} held;
	

};

#endif
