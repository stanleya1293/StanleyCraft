#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Renderer.h"
#include "Camera.h"
#include "Block.h"
#include "InputHandler.h"

class Game 
{
public:
	static void initialize();
	static void run();
};

#endif
