#include "Mesh.h"

Mesh::Mesh(const float vertex_data[], const unsigned int vertex_count) : m_VAO(0), m_VBO(0), m_vertex_count(vertex_count) 
{
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, m_vertex_count * sizeof(float), vertex_data, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//m_vertex_count = sizeof(vertex_data) / (5 * sizeof(vertex_data[0]));
}

Mesh::~Mesh()
{}

void Mesh::render(const Shader& shader) 
{
	shader.use();
	glDrawArrays(GL_TRIANGLES, 0, m_vertex_count);
}
