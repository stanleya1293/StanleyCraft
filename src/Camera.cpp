#include "Camera.h"

Camera::Camera(glm::vec3 position, const Window &window) :
	m_position(position),
	m_yaw(-90.0f),
	m_pitch(0.0f),
	m_direction(glm::vec3(0)),
	m_view(glm::mat4(0)),
	m_projection(glm::mat4(0))
{
	m_direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	m_direction.y = sin(glm::radians(m_pitch));
	m_direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	glm::vec3 cameraFront = glm::normalize(m_direction);
	m_view = glm::lookAt(position, position + cameraFront, glm::vec3(0.0f, 1.0f, 0.0f));
	m_projection = glm::perspective(45.0f, window.getAspectRatio(), 0.1f, 100.0f);
}

void Camera::move(float xOffset, float zOffset) 
{
	m_position.x += xOffset;
	m_position.z += zOffset;
	m_view = glm::lookAt(m_position, m_position + m_direction, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::rotate(float yawOffset, float pitchOffset)
{
	m_yaw += yawOffset;
	m_pitch += pitchOffset;
	if (m_pitch > 89.0f)
		m_pitch = 89.0f;
	else if (m_pitch < -89.0f)
		m_pitch = -89.0f;
	m_view = glm::lookAt(m_position, m_position + m_direction, glm::vec3(0.0f, 1.0f, 0.0f));
}


void Camera::processCursorMovement();

static void Camera::cursorMovementHandler(GLFWwindow* window, double xPos, double yPos) 
{
	
}
