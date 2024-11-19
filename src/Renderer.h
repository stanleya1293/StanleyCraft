#ifndef RENDERER_H
#define RENDERER_H
#include <glad/glad.h>
#include "Model.h"

class Renderer {
public:
	Renderer();
	~Renderer();
	void draw(Model model);
};

#endif