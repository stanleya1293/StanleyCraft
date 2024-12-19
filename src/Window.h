#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window 
{
public:
	/*
	 * Default constructor for window, initializes to null values.
	 */
	Window();
	
	/*
	 * Intended Constructor.
	 * Initializes a window using GLFW with a specified width,
	 * height, and title, as specified in the arguments.
	 * Make sure that a window is created before
	 * using any other program functions, since a window
	 * is needed as a rendering target to initialize OpenGL
	 * functions with GLAD.
	 */
	Window(int width, int height, const std::string &title);

	/*
	 * Updates the window by rendering any specified targets,
	 * swapping the buffer to the behind frame,
	 * polling window events, and lastly clearing the screen buffer.
	 */
	void update();
	
	/*
	 * Polls and returns the state of the window
	 * at the moment to see if it is running (returns true),
	 * or if it is supposed to close (returns false).
	 */
	bool running();
private:
	GLFWwindow* m_windowID;
	int m_width;
	int m_height;
	std::string m_title;
};

#endif
