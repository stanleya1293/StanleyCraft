#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Window.h"

class Camera 
{
public:
	Camera(glm::vec3 position, const Window &window);
	void move(float xOffset, float yOffset);
	void rotate(float yawOffset, float pitchOffset);
	inline glm::mat4 getView() const { return m_view; }
	inline glm::mat4 getProjection() const { return m_projection; }

	void processCursorMovement(double xPos, double yPos);

	static void cursorMovementHandler(GLFWwindow* window, double xPos, double yPos);
private:
	glm::vec3 m_position;
	float m_yaw;
	float m_pitch;
	glm::vec3 m_direction;
	glm::mat4 m_view;
	glm::mat4 m_projection;
};

#endif