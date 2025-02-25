#include "Shader.h"

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
	unsigned int vertexShader = loadFile(vertexPath, Vertex);
	unsigned int fragmentShader = loadFile(fragmentPath, Fragment);
	this->program = glCreateProgram();
	glAttachShader(this->program, vertexShader);
	glAttachShader(this->program, fragmentShader);
	glLinkProgram(this->program);
}

void Shader::use() const {
	glUseProgram(this->program);
}

unsigned int Shader::loadFile(const std::string &path, Type type) const {
	std::ifstream file(path);
	std::string shaderSrc;
	std::stringstream shaderStream;

	shaderStream << file.rdbuf();
	shaderSrc = shaderStream.str();
	const char* shaderSrcC = shaderSrc.c_str();
	unsigned int shader;

	if (type == Vertex) {
		shader = glCreateShader(GL_VERTEX_SHADER);
	}
	else if (type == Fragment) {
		shader = glCreateShader(GL_FRAGMENT_SHADER);
	}

	glShaderSource(shader, 1, &shaderSrcC, NULL);
	glCompileShader(shader);

	return shader;
}
