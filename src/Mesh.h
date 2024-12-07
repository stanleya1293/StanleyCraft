#ifndef MESH_H
#define MESH_H
#include "Shader.h"
#include <glad/glad.h>

class Mesh {
public:
  Mesh(const float vertexData[], const unsigned int vertexCount, Shader shader);
  ~Mesh();
  void render();

private:
  unsigned int m_VAO;
  unsigned int m_VBO;
  Shader m_shader;
  int m_vertexCount;
};

#endif
