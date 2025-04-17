#include "Block.h"

Block::Block(const std::string& dataPath, glm::vec3 position) :
	m_vbo(0), m_vao(0),
	m_model(glm::mat4(1.0f))
{
	m_model = glm::translate(m_model, position);

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(block_vertices), block_vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}

void Block::render() const 
{
	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

