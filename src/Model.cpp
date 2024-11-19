#include "Model.h"

Model::Model(const std::string shaderDir, const VertexBuffer data, const unsigned int vertexCount, float x, float y, float z) {
	modelPosition = glm::vec3(x, y, z);
	modelVertexCount = vertexCount;
	modelShader = Shader(shaderDir);

	glGenVertexArrays(1, &modelVao);
	glBindVertexArray(modelVao);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), &data, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) 0);
	glEnableVertexAttribArray(0);
}

Model::~Model() {}

void Model::use() {
	glUseProgram(modelShader.getShaderID());
	glBindVertexArray(modelVao);
	
}