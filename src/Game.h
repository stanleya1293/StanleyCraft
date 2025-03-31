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
	
	void run();

	inline Renderer& getRenderer() { return m_renderer; };

private:
	
	Window m_window;
	
	Renderer m_renderer;

};

#endif
