#ifndef RENDERER_H
#define RENDERER_H
#include "Libs.h"
#include "Model.h"
#include "Camera.h"


class Renderer 
{
public:
  Renderer();
  Renderer(Camera camera);
  ~Renderer();
  void update();
  void addTarget(Model model);

private:
  std::vector<Model> m_targets;
  Camera m_camera;
};

#endif
