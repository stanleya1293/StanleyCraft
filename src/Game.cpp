#include "Game.h"


namespace StanleyCraft
{
	Game::Game()
	{
		glfwInit();
		m_window = glfwCreateWindow(800, 800, "StanleyCraft", NULL, NULL); //might want to make resizable
		glfwMakeContextCurrent(m_window);
		gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
		
	}

	Game::~Game()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void Game::run()
	{
		while (!glfwWindowShouldClose(m_window))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}
	}
}
