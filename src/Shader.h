#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <sstream>
#include <fstream>
#include <glad/glad.h>

class Shader {
public:
	Shader(const std::string &vertexPath, const std::string &fragmentPath);
	void use() const;
private:
	enum Type {
		Vertex,
		Fragment
	};
	unsigned int program;
private: 
	unsigned int loadFile(const std::string &path, Type type) const;
};

#endif
