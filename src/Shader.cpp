#include "Shader.h"

Shader::Shader(std::string shaderName) : m_shader(0) {
  std::string vShaderPath =
      "../shaders/" + shaderName + "/" + shaderName + ".vs";
  std::string fShaderPath =
      "../shaders/" + shaderName + "/" + shaderName + ".fs";

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
  } catch (std::ifstream::failure e) {
    std::cout << "ERROR LOADING SHADER FILES" << std::endl;
  }

  unsigned int vShader;
  unsigned int fShader;

  const char *vShaderSrc = vShaderSrcStr.c_str();
  const char *fShaderSrc = fShaderSrcStr.c_str();

  vShader = glCreateShader(GL_VERTEX_SHADER);
  fShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(vShader, 1, &vShaderSrc, NULL);
  glShaderSource(fShader, 1, &fShaderSrc, NULL);

  int v_success;
  char v_infolog[512];
  int f_success;
  char f_infolog[512];

  glCompileShader(vShader);
  glGetShaderiv(vShader, GL_COMPILE_STATUS, &v_success);
  if (!v_success) {
    glGetShaderInfoLog(vShader, 512, NULL, v_infolog);
    std::cout << "ERROR COMPILING VERTEX SHADER: " << v_infolog << std::endl;
  }

  glCompileShader(fShader);
  glGetShaderiv(fShader, GL_COMPILE_STATUS, &f_success);
  if (!f_success) {
    glGetShaderInfoLog(fShader, 512, NULL, f_infolog);
    std::cout << "ERROR COMPILING FRAGMENT SHADER: " << f_infolog << std::endl;
  }

  m_shader = glCreateProgram();
  glAttachShader(m_shader, vShader);
  glAttachShader(m_shader, fShader);
  glLinkProgram(m_shader);

  glDeleteShader(vShader);
  glDeleteShader(fShader);
}

Shader::~Shader() { glDeleteProgram(m_shader); }

void Shader::use() const { glUseProgram(m_shader); }
