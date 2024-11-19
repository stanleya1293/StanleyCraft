#include "Renderer.h"

Renderer::Renderer() {
	glEnable(GL_DEPTH_TEST);
}

Renderer::~Renderer() {}

void Renderer::draw(Model model) {
	model.use();
	glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
}