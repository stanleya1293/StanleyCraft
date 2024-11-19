#ifndef MODEL_H
#define MODEL_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "Shader.h"

typedef std::vector<float> VertexBuffer;

class Model {
public:
	Model(float x, float y, float z);
	~Model();
	void use();
	inline unsigned int getVertexCount() { return modelVertexCount; };
private:
	unsigned int modelVertexCount;
	unsigned int modelVao;
	Shader modelShader;
	glm::vec3 modelPosition;
};

#endif