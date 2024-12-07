#include "Model.h"

Model::Model(const float vertexData[], const unsigned int vertexCount, Shader shader)
    : m_VAO(0), m_VBO(0), m_vertexCount(vertexCount), m_shader(shader) , m_position(glm::vec3(0.0f, 0.0f, 0.0f)), m_scale(1.0f), m_model(glm::mat4(1.0f))
{
  glGenVertexArrays(1, &m_VAO);
  glBindVertexArray(m_VAO);

  glGenBuffers(1, &m_VBO);
  glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
  glBufferData(GL_ARRAY_BUFFER, m_vertexCount * sizeof(float), vertexData,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  m_model = glm::translate(m_model, m_position);
  m_model = glm::scale(m_model, glm::vec3(m_scale, m_scale, m_scale));
  // m_vertex_count = sizeof(vertex_data) / (5 * sizeof(vertex_data[0]));
}

Model::~Model() {}

void Model::render() 
{
  m_shader.use();
  glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
}

