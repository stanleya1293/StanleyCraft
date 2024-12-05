#ifndef MESH_H
#define MESH_H
#include <glad/glad.h>
#include "Shader.h"

class Mesh 
{
public:
	Mesh(const float vertex_data[], const unsigned int vertex_count);
	~Mesh();
	void render(const Shader& shader);
private:
	unsigned int m_VAO;
	unsigned int m_VBO;
	int m_vertex_count;
};

#endif
