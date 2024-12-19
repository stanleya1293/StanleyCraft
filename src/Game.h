#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Shader.h"

class Game 
{
public: 
	Game();
	void run();
private:
	Window m_window;	
};

#endif
