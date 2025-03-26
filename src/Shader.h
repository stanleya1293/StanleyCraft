#ifndef SHADER_H
#define SHADER_H
#include "dependencies.h"

class Shader {
public:
	
	Shader(const std::string &vertexPath, const std::string &fragmentPath);
	
	void use() const;
	
	void setMat4(const std::string &name, glm::mat4 data) const;
private:
	
	enum Type {
		Vertex,
		Fragment
	};
	
	unsigned int m_program;

private: 
	
	unsigned int loadFile(const std::string &path, Shader::Type type) const;

};

#endif
