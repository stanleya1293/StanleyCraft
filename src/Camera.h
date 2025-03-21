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
	inline glm::mat4 getView() const { return view; }
	inline glm::mat4 getProjection() const { return projection; }
	void pollKeys() const;
private:
	glm::vec3 position;
	float yaw;
	float pitch;
	glm::vec3 direction;
	glm::mat4 view;
	glm::mat4 projection;
};

#endif