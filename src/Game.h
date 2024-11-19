#ifndef GAME_H
#define GAME_H
#include "Window.h"
#include "Renderer.h"

class Game {
public:
	Game();
	~Game();
	void run();
private:
	Window gameWindow;
	Renderer gameRenderer;	
};

#endif