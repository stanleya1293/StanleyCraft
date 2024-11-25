#include "Shader.h"

Shader::Shader(const std::string shaderName) : shaderProgram(0) {
	std::string shaderPath = "../shaders/" + shaderName + "/" + shaderName;
	std::string vertPath = shaderPath + ".vs";
	std::string fragPath = shaderPath + ".fs";

	std::ifstream vertFile(vertPath);
	std::ifstream fragFile(fragPath);

	vertFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	fragFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	std::string vertSrc;
	std::string fragSrc;

	try {		
		std::stringstream vertFileBuffer;
		vertFileBuffer << vertFile.rdbuf();
		vertSrc = vertFileBuffer.str();

		std::stringstream fragFileBuffer;
		fragFileBuffer << fragFile.rdbuf();
		fragSrc = fragFileBuffer.str();
	}
	catch (std::ifstream::failure e) {
		std::cout << "Error opening shader files!" << std::endl;
		return;
	}

	vertFile.close();
	fragFile.close();

	unsigned int vertShader;
	unsigned int fragShader;

	vertShader = glCreateShader(GL_VERTEX_SHADER);
	fragShader = glCreateShader(GL_FRAGMENT_SHADER);

	const char* vertShaderCode = vertSrc.c_str();
	const char* fragShaderCode = fragSrc.c_str();

	glShaderSource(vertShader, 1, &vertShaderCode, NULL);
	glShaderSource(fragShader, 1, &fragShaderCode, NULL);

	int success;
	char infoLog[512];
	glCompileShader(vertShader);
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
		std::cout << "Error compiling vertex shader: " << infoLog << std::endl;
	}	

	glCompileShader(fragShader);
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
		std::cout << "Error compiling fragment shader: " << infoLog << std::endl;
	}

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertShader);
	glAttachShader(shaderProgram, fragShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
}

void Shader::use() {
	glUseProgram(shaderProgram);
}

Shader::~Shader() {
	glDeleteProgram(shaderProgram);
}