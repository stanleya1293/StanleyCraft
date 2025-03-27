#ifndef RENDERER_H
#define RENDERER_H

#include "dependencies.h"

#include "Camera.h"
#include "Shader.h"
#include "Block.h"


class Renderer {
public:
	Renderer();
	
	Renderer(Camera &camera, const Shader &shader);
	
	void addBlock(Block &block);
	
	void update();

	inline Camera& getCamera() { return m_activeCamera; };
private:
	
	Shader m_activeShader;
	
	Camera m_activeCamera;
	
	std::vector<Block> m_world;

};

#endif
