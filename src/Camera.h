#ifndef CAMERA_H
#define CAMERA_H

#include "dependencies.h"

class Camera 
{
public:
	Camera();
	Camera(glm::vec3 position, float aspectRatio);
	enum Direction {
		Left,
		Right,
		Forward,
		Backward
	};
	void move(Direction direction);
	void rotate(float yawOffset, float pitchOffset);
	inline glm::mat4 getView() const { return m_view; }
	inline glm::mat4 getProjection() const { return m_projection; }
private:
	glm::vec3 m_position;
	float m_yaw;
	float m_pitch;
	glm::vec3 m_front;
	glm::mat4 m_view;
	glm::mat4 m_projection;
	float m_sensitivity;
	float m_speed;
};

#endif