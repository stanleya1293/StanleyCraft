#include "Block.h"

Block::Block(const std::string &dataPath) : 
	vbo(0), vao(0)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(block_vertices), &block_vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);

}

void Block::render(const Shader& shader) const 
{
	shader.mat4();
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}