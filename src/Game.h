#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Renderer.h"
#include "Camera.h"
#include "Block.h"

class Game 
{
public:
	
	Game();
	
	static const void run();

private:
	
	static Window m_window;
	
	static Renderer m_renderer;

};

#endif
