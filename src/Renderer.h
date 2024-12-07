#ifndef RENDERER_H
#define RENDERER_H
#include "Camera.h"
#include "Mesh.h"
#include <iostream>
#include <vector>

class Renderer {
public:
  Renderer();
  Renderer(Camera camera);
  ~Renderer();
  void update();
  void addTarget(Mesh mesh);

private:
  std::vector<Mesh> m_targets;
  Camera m_camera;
};

#endif
