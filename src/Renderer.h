#ifndef RENDERER_H
#define RENDERER_H

#include "dependencies.h"

#include "Camera.h"
#include "Shader.h"
#include "Block.h"


class Renderer {
public:
	Renderer(Camera &camera, const Shader &shader);
	static void addBlock(Block &block);
	static void update();
	static inline Camera& getCamera() { return m_activeCamera; }
private:
	static Shader m_activeShader;
	static Camera m_activeCamera;
	static std::vector<Block> m_world;
};

#endif
