#include "Camera.h"

Camera::Camera(glm::vec3 position, float aspectRatio) :
	m_position(position), m_yaw(-90.0f),
	m_pitch(0.0f), m_view(glm::mat4(0)),
	m_front(glm::vec3(0)), m_projection(glm::mat4(0)),
	m_sensitivity(0.1), m_speed(0.1) {
	glm::vec3 direction;
	direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	direction.y = sin(glm::radians(m_pitch));
	direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	m_front = glm::normalize(direction);
	m_view = glm::lookAt(m_position, m_position + m_front, glm::vec3(0.0f, 1.0f, 0.0f));
	m_projection = glm::perspective(45.0f, aspectRatio, 0.1f, 100.0f);
}

void Camera::move(Direction direction) {
	switch (direction) {
	case Forward:
		m_position += m_front * m_speed;
		break;
	case Backward:
		m_position -= m_front * m_speed;
		break;
	case Left:
		m_position -= glm::normalize(glm::cross(m_front, glm::vec3(0.0f, 1.0f, 0.0f))) * m_speed;
		std::cout << "moved left!" << std::endl;
		break;
	case Right:
		m_position += glm::normalize(glm::cross(m_front, glm::vec3(0.0f, 1.0f, 0.0f))) * m_speed;
		break;
	}
	m_view = glm::lookAt(m_position, m_position + m_front, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::rotate(float yawOffset, float pitchOffset) {
	m_yaw += yawOffset * m_sensitivity;
	m_pitch += pitchOffset * m_sensitivity;
	if (m_pitch > 89.0f)
		m_pitch = 89.0f;
	else if (m_pitch < -89.0f)
		m_pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	direction.y = sin(glm::radians(m_pitch));
	direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	m_front = glm::normalize(direction);
	m_view = glm::lookAt(m_position, m_position + m_front, glm::vec3(0.0f, 1.0f, 0.0f));
}
