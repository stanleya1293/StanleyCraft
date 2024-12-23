#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <glad/glad.h>
#include <GL/gl.h>

class Shader 
{
public:
	Shader();
	Shader(const std::string &shaderDir);
	void use() const;
	~Shader();
private:
	const std::string getShaderSrc(const std::string &shaderPath);
private:
	unsigned int m_shaderID;
};

#endif
