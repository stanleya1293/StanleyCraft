#ifndef SHADER_H
#define SHADER_H
#include "Libs.h"

class Shader 
{
public:
	Shader(std::string shaderName);
	~Shader();
	void use() const;
	inline unsigned int getShaderID() { return m_shader; };
private:
	unsigned int m_shader;
};

#endif
