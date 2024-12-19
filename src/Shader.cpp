#include "Shader.h"


//Default Constructor
Shader::Shader() : m_shaderID(0)  
{}

/*
 * Intended constructor, pass in directory containing a .fs and .vs file 
 * of the same name, i.e. shaders/foo/foo.fs and shaders/foo/foo.vs, pass in "shaders/foo",
 * compiles a GLSL shader program from fragment and vertex shaders, stores in m_shaderID.
 */
Shader::Shader(const std::string &shaderDir) : m_shaderID(glCreateProgram()) 
{
	std::string vShaderDir = "../shaders/" + shaderDir + "/" + shaderDir + ".vs";
	std::string fShaderDir = "../shaders/" + shaderDir + "/" + shaderDir + ".fs";
	std::string vShaderSrcStr = getShaderSrc(vShaderDir);
	std::string fShaderSrcStr = getShaderSrc(fShaderDir);

	const char* vShaderSrc = vShaderSrcStr.c_str();
	const char* fShaderSrc = fShaderSrcStr.c_str();



	unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vShader, 1, &vShaderSrc, NULL);
	glShaderSource(fShader, 1, &fShaderSrc, NULL);
	
	int success;

	glCompileShader(vShader);
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(vShader, 512, NULL, infoLog);
		std::cerr << "ERROR COMPILING VERTEX SHADER: " << infoLog << std::endl;
	}

	glCompileShader(fShader);
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(fShader, 512, NULL, infoLog);
		std::cerr << "ERROR COMPILING FRAGMENT SHADER: " << infoLog << std::endl;
	}
	
	glAttachShader(m_shaderID, vShader);
	glAttachShader(m_shaderID, fShader);
	glLinkProgram(m_shaderID);

	glDeleteProgram(vShader);
	glDeleteProgram(fShader);
}

/*
 * Sets this object as the current active shader program.
 */ 
void Shader::use() 
{
	glUseProgram(m_shaderID);
}

/*
 * Helper function that reads shader content from a file and returns a std::string.
 */
const std::string Shader::getShaderSrc(const std::string &shaderPath) 
{
	std::ifstream shaderFile(shaderPath);
	if (!shaderFile.is_open())
	{
		std::cerr << "ERROR: INVALID SHADER PATH" << std::endl;
		std::exit(1);
	}
	std::stringstream shaderBuffer;
	shaderBuffer << shaderFile.rdbuf();
	std::string shaderSrc = shaderBuffer.str();
	shaderFile.close();
	return (shaderSrc);
}

Shader::~Shader() 
{
	glDeleteProgram(m_shaderID);
}
