#include "Camera.h"

Camera::Camera() {}

Camera::Camera(glm::vec3 position) :
	m_position(position),
	m_yaw(-90.0f),
	m_pitch(0.0f),
	m_view(glm::mat4(0)),
	m_cameraFront(glm::vec3(0)),
	m_projection(glm::mat4(0))
{
	glm::vec3 direction;
	direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	direction.y = sin(glm::radians(m_pitch));
	direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	m_cameraFront = glm::normalize(direction);
	m_view = glm::lookAt(m_position, m_position + m_cameraFront, glm::vec3(0.0f, 1.0f, 0.0f));
	m_projection = glm::perspective(45.0f, Window::getAspectRatio(), 0.1f, 100.0f);
}

void Camera::move(float xOffset, float zOffset) 
{
	m_position.x += xOffset;
	m_position.z += zOffset;
	m_view = glm::lookAt(m_position, m_position + m_cameraFront, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::rotate(float yawOffset, float pitchOffset)
{
	m_yaw += yawOffset;
	m_pitch += pitchOffset;
	if (m_pitch > 89.0f)
		m_pitch = 89.0f;
	else if (m_pitch < -89.0f)
		m_pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	direction.y = sin(glm::radians(m_pitch));
	direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	m_cameraFront = glm::normalize(direction);
	m_view = glm::lookAt(m_position, m_position + m_cameraFront, glm::vec3(0.0f, 1.0f, 0.0f));
}
