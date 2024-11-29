#ifndef SHADER_H
#define SHADER_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <glad/glad.h>

class Shader 
{
public:
	Shader(std::string shaderName);
	~Shader();
	void use();
private:
	unsigned int m_shader;
};

#endif
