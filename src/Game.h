#ifndef GAME_H
#define GAME_H

#include "dependencies.h"

#include "Window.h"
#include "Renderer.h"
#include "Camera.h"
#include "Block.h"

class Game {
public:
	Game();
	void run();
private:
	std::unique_ptr<Window> m_window;
	std::unique_ptr<Renderer> m_renderer;
};

#endif
