#include "Renderer.h"

Renderer::Renderer() 
{}

Renderer::Renderer(Camera camera) : m_camera(camera) 
{}

Renderer::~Renderer()
{}

void Renderer::update() 
{
	for (int i = 0; i < m_targets.size(); i++)
	{
		m_camera.update();
		glUniformMatrix4fv(m_targets[i].getUniform("model"), 1, GL_FALSE, glm::value_ptr(m_targets[i].getModel()));
		glUniformMatrix4fv(m_targets[i].getUniform("view"), 1, GL_FALSE, glm::value_ptr(m_camera.getView()));
		glUniformMatrix4fv(m_targets[i].getUniform("projection"), 1, GL_FALSE, glm::value_ptr(m_camera.getProjection()));
		m_targets[i].render();
	}
}

void Renderer::addTarget(Model model)
{
	m_targets.push_back(model);
}