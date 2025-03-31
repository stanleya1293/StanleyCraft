#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Renderer.h"
#include "Camera.h"
#include "Block.h"
#include "EventHandler.h"

class Game 
{
public:
	Game();
	static void run();
	static inline Renderer& getRenderer() { return m_renderer; };
	static inline Window& getWindow() { return m_window; }
private:
	static Window m_window;
	static Renderer m_renderer;
	static EventHandler m_eventHandler;
};

#endif
