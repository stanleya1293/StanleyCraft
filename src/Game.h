#ifndef GAME_H
#define GAME_H
#include "Libs.h"
#include "Window.h"
#include "Renderer.h"
#include "Shader.h"
#include "Model.h"

class Game 
{
public:
  Game();
  ~Game();
  void run();

private:
  Window m_window;
  Renderer m_renderer;
};

#endif
