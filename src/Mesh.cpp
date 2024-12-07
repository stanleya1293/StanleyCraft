#include "Mesh.h"

Mesh::Mesh(const float vertexData[], const unsigned int vertexCount,
           Shader shader)
    : m_VAO(0), m_VBO(0), m_vertexCount(vertexCount), m_shader(shader) {
  glGenVertexArrays(1, &m_VAO);
  glBindVertexArray(m_VAO);

  glGenBuffers(1, &m_VBO);
  glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
  glBufferData(GL_ARRAY_BUFFER, m_vertexCount * sizeof(float), vertexData,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  // m_vertex_count = sizeof(vertex_data) / (5 * sizeof(vertex_data[0]));
}

Mesh::~Mesh() {}

void Mesh::render() {
  m_shader.use();
  glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
}
