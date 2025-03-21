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

void Shader::use() const 
{
	glUseProgram(this->program);
}

void Shader::setMat4(const std::string &name, glm::mat4 data) const 
{
	int location = glGetUniformLocation(program, name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(data));
}

unsigned int Shader::loadFile(const std::string &path, Type type) const 
{
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
