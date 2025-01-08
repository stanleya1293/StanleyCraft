#ifndef GAME_H
#define GAME_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace StanleyCraft
{
	class Game
	{
	public:
		Game();
		~Game();
		void run();
	private:
		GLFWwindow* m_window;

	};
}

#endif
