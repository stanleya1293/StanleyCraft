#ifndef GAME_H
#define GAME_H
#include "Window.h"
#include "Mesh.h"
#include "Shader.h"

class Game 
{
public:
	Game();
	~Game();
	void run();
private:
	Window m_window;
};

#endif
