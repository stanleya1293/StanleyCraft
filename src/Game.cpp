#include "Game.h"

Game::Game() : 
	m_window(Window(800, 800, "Test")) //change later to make null Window, for now leave.
{}

void Game::run() 
{
	Shader shader = Shader("default");
	std::vector<Vertex> vertices = 
	{
		{-0.5f,  0.5f,  0.0f},
		{-0.5f, -0.5f,  0.0f},
		{ 0.5f,  0.5f,  0.0f},
		{ 0.5f, -0.5f,  0.0f},
		{-0.5f, -0.5f,  0.0f},
		{ 0.5f,  0.5f,  0.0f},
	};

	Model square(vertices);

	while (m_window.running())
	{
		square.draw(shader);
		m_window.update();
	}
}
