#include "Renderer.h"


Renderer::Renderer(Camera& camera, const Shader& shader) : 
	m_activeShader(shader), m_activeCamera(camera)
{
	m_activeShader.use();
}

void Renderer::addBlock(Block &block) 
{
	m_world.push_back(block);
}

void Renderer::update()
{

	m_activeShader.setMat4("view", m_activeCamera.getView());
	m_activeShader.setMat4("projection", m_activeCamera.getProjection());
	
	for (Block block : m_world) {
		m_activeShader.setMat4("model", block.getModel());
		block.render();
	}
}