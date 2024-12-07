#ifndef CAMERA_H
#define CAMERA_H
#include "Libs.h"

enum Direction 
{ Left,	Right, Forward, Backward };

class Camera 
{
public:
  Camera();
  ~Camera();
  inline glm::mat4 getView() { return m_view; };
  inline glm::mat4 getProjection() { return m_projection; };
  void update();
  void move(Direction direction);

private:
  glm::mat4 m_view;
  glm::mat4 m_projection;
  glm::vec3 m_position;
  glm::vec3 m_front;
  glm::vec3 m_up;
};

#endif
