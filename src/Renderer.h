#ifndef RENDERER_H
#define RENDERER_H

#include "dependencies.h"

#include "Camera.h"
#include "Shader.h"
#include "Block.h"


class Renderer {
public:
	static void initialize(Camera &camera, const Shader &shader);
	static void addBlock(Block &block);
	static void update();
	static inline Camera& getCamera() { return m_activeCamera; }
private:
	inline static Shader m_activeShader;
	inline static Camera m_activeCamera;
	inline static std::vector<Block> m_world;
};

#endif
