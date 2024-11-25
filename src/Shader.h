#ifndef SHADER_H
#define SHADER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>

class Shader {
public:
	Shader(const std::string shaderName);
	~Shader();
	void use();
private:
	unsigned int shaderProgram;
};

#endif