#include "Game.h"


namespace StanleyCraft
{
	Game::Game()
	{
		glfwInit();
		m_window = glfwCreateWindow(800, 800, "StanleyCraft", NULL, NULL); //might want to make resizable
		glfwMakeContextCurrent(m_window);
		gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

		const char vShaderSrc[] =
			"version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0";
		const char fShaderSrc[] =
			"version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
			"}\0";

		unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
		unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
		
		glShaderSrc(vShader, 1, &vShaderSrc, NULL);
		glShaderSrc(fShader, 1, &fShaderSrc, NULL);
		
		glCompileShader(vShader);
		glCompileShader(fShader);

		m_shader = glCreateProgram();
		

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
