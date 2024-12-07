#include "Camera.h"

Camera::Camera()
    : m_position(glm::vec3(0.0f, 0.0f, 3.0f)), m_front(glm::vec3(0.0f, 0.0f, -1.0f)), m_up(glm::vec3(0.0f, 1.0f, 0.0f)) 
{
  m_view = glm::lookAt(m_position, m_position + m_front, m_up);
  m_projection =
      glm::perspective(glm::radians(45.0f), 800.0f / 800.0f, 0.1f, 100.0f);
}

Camera::~Camera() 
{}

void Camera::update() {
  m_view = glm::lookAt(m_position, m_position + m_front, m_up);
}

void Camera::move(Direction direction) {
  const float cameraSpeed = 0.05f;

  switch (direction) {
  case Left:
    m_position -= glm::normalize(glm::cross(m_front, m_up)) * cameraSpeed;
    break;
  case Right:
    m_position += glm::normalize(glm::cross(m_front, m_up)) * cameraSpeed;
    break;
  case Forward:
    m_position += cameraSpeed * m_front;
    break;
  case Backward:
    m_position -= cameraSpeed * m_front;
    break;
  }
}
