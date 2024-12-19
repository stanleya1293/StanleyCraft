#include "Game.h"

Game::Game() : 
	m_window(Window(800, 800, "Test")) //change later to make null Window, for now leave.
{}

void Game::run() 
{
	Shader shader = Shader("default");	
	while (m_window.running())
	{
		shader.use();
		m_window.update();
	}
}
