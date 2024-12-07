#ifndef GAME_H
#define GAME_H
#include "Mesh.h"
#include "Renderer.h"
#include "Shader.h"
#include "Window.h"

class Game {
public:
  Game();
  ~Game();
  void run();

private:
  Window m_window;
  Renderer m_renderer;
};

#endif
