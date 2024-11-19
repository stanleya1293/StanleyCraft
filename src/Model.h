#ifndef MODEL_H
#define MODEL_H
#include "Shader.h"

class Model {
public:
	Model();
	~Model();
	
private:
	unsigned int modelVao;
	Shader modelShader;
};

#endif