#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>
#include <stdio.h>

typedef unsigned int Shader;

Shader load_shader(const char* vertex_shader_path, const char* fragment_shader_path);

void use_shader(Shader shader);

#endif
