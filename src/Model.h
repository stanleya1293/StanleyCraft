#ifndef MODEL_H
#define MODEL_H
#include "Libs.h"
#include "Shader.h"

class Model {
public:
  Model(const float vertexData[], const unsigned int vertexCount, Shader shader);
  ~Model(); 
  void render();
  inline int getUniform(const char* uniformName) { return glGetUniformLocation(m_shader.getShaderID(), uniformName); };
  void setPosition(float x, float y, float z); //default to {0.0f, 0.0f, 0.0f  }
  void setScale(float scale); //default to 1.0f
  inline glm::mat4 getModel() { return m_model; };
private:
  unsigned int m_VAO;
  unsigned int m_VBO;
  Shader m_shader;
  int m_vertexCount;
  glm::vec3 m_position;
  glm::mat4 m_model;
  float m_scale;
};

#endif
