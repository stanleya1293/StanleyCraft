#ifndef SHADER_H
#define SHADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glad/glad.h>

typedef unsigned int Shader;

Shader loadShader(char* shader_name);

void useShader(Shader shader);

#endif