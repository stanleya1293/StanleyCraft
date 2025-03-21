#include "Camera.h"

Camera::Camera(glm::vec3 position, const Window &window) :
	position(position),
	yaw(-90.0f),
	pitch(0.0f),
	direction(glm::vec3(0)),
	view(glm::mat4(0)),
	projection(glm::mat4(0))
{
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	glm::vec3 cameraFront = glm::normalize(direction);
	view = glm::lookAt(position, position + cameraFront, glm::vec3(0.0f, 1.0f, 0.0f));
	projection = glm::perspective(45.0f, window.getAspectRatio(), 0.1f, 100.0f);
}

void Camera::move(float xOffset, float zOffset) 
{
	position.x += xOffset;
	position.z += zOffset;
	view = glm::lookAt(position, position + direction, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::rotate(float yawOffset, float pitchOffset)
{
	yaw += yawOffset;
	pitch += pitchOffset;
	if (pitch > 89.0f)
		pitch = 89.0f;
	else if (pitch < -89.0f)
		pitch = -89.0f;
	view = glm::lookAt(position, position + direction, glm::vec3(0.0f, 1.0f, 0.0f));
}
