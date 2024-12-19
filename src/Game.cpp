#include "Game.h"

Game::Game() : 
	m_window(Window(800, 800, "Test")) //change later to make null Window, for now leave.
{}

void Game::run() 
{
	while (m_window.running())
	{
		m_window.update();
	}
}
