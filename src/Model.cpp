#include "Model.h"

Model::Model() : 
	m_vertices({}), m_vbo(0), m_vao(0) 
{}

Model::Model(std::vector<Vertex> vertices) :
	m_vertices(vertices), m_vbo(0), m_vao(0)
{
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);
		


	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(
		GL_ARRAY_BUFFER, 
		m_vertices.size() * sizeof(Vertex), 
		&m_vertices.front(), 
		GL_STATIC_DRAW
	);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), (void*) 0);
	glEnableVertexAttribArray(0);

	
}

void Model::draw(const Shader &shader) 
{
	shader.use();
	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());
}
