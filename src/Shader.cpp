#include "Shader.h"

Shader::Shader(std::string shaderName) : m_shader(0)
{
	std::string vShaderPath = "../shaders/" + shaderName + "/" + shaderName + ".vs";
	std::string fShaderPath = "../shaders/" + shaderName + "/" + shaderName + ".fs";

	std::stringstream vBuffer;
	std::stringstream fBuffer;
	
	std::ifstream vFile;
	std::ifstream fFile;
	vFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
 	
	std::string vShaderSrcStr;
	std::string fShaderSrcStr;
	try {
		vFile.open(vShaderPath);
		fFile.open(fShaderPath);

		vBuffer << vFile.rdbuf();
		fBuffer << fFile.rdbuf();
		
		vShaderSrcStr = vBuffer.str();
		fShaderSrcStr = fBuffer.str();

		vFile.close();
		fFile.close();
	}
	catch (std::ifstream::failure e) {
		std::cout << "ERROR LOADING SHADER FILES" << std::endl;
	}
	
	unsigned int vShader;
	unsigned int fShader;
	
	const char* vShaderSrc = vShaderSrcStr.c_str();
	const char* fShaderSrc = fShaderSrcStr.c_str();


	vShader = glCreateShader(GL_VERTEX_SHADER);
	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vShader, 1, &vShaderSrc, NULL);
	glShaderSource(fShader, 1, &fShaderSrc, NULL);
	
	glCompileShader(vShader);
	glCompileShader(fShader);
	
	m_shader = glCreateProgram();
	glAttachShader(m_shader, vShader);
	glAttachShader(m_shader, fShader);
	glLinkProgram(m_shader);
	
	glDeleteShader(vShader);
	glDeleteShader(fShader);
}

Shader::~Shader() 
{
	glDeleteProgram(m_shader);
}

void Shader::use() 
{
	glUseProgram(m_shader);
}
