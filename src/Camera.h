#ifndef CAMERA_H
#define CAMERA_H

#include "dependencies.h"
#include "Window.h"

class Camera 
{
public:
	Camera();

	Camera(glm::vec3 position, const Window& window);
	
	void move(float xOffset, float yOffset);
	
	void rotate(float yawOffset, float pitchOffset);
	
	inline glm::mat4 getView() const { return m_view; }
	
	inline glm::mat4 getProjection() const { return m_projection; }

private:
	
	glm::vec3 m_position;
	
	float m_yaw;
	
	float m_pitch;
	
	glm::vec3 m_cameraFront;
	
	glm::mat4 m_view;
	
	glm::mat4 m_projection;

};

#endif