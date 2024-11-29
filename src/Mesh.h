#ifndef MESH_H
#define MESH_H
#include <glad/glad.h>

class Mesh 
{
public:
	Mesh(const float vertexData[]);
	~Mesh();
	void render();
private:
	unsigned int m_VAO;
	unsigned int m_VBO;
};

#endif
