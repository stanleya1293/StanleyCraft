#include "Shader.h"

Shader load_shader(const char* vertex_shader_path, const char* fragment_shader_path) {
	FILE* vertex_shader_file = fopen(vertex_shader_path, "r");
	if (!vertex_shader_file) {
		printf("Error opening vertex shader file!\n");
	}
	FILE* fragment_shader_file = fopen(fragment_shader_path, "r");
	if (!fragment_shader_file) {
		printf("Error opening fragment shader file!\n");
	}
	fseek(vertex_shader_file, 0, SEEK_END);
	long vertex_file_size = ftell(vertex_shader_file);
	rewind(vertex_shader_file);
	char* vertex_src = (char*)malloc(vertex_file_size + 1);
	fread(vertex_src, sizeof(char), vertex_file_size, vertex_shader_file);
	vertex_src[vertex_file_size] = '\0';
	
	fseek(fragment_shader_file, 0, SEEK_END);
	long fragment_file_size = ftell(fragment_shader_file);
	rewind(fragment_shader_file);
	char* fragment_src = (char*)malloc(fragment_file_size + 1);
	fread(fragment_src, sizeof(char), fragment_file_size, fragment_shader_file);
	fragment_src[fragment_file_size] = '\0';

	fclose(vertex_shader_file);
	fclose(fragment_shader_file);

	unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_src, NULL);
	glShaderSource(fragment_shader, 1, &fragment_src, NULL);
	glCompileShader(vertex_shader);
	glCompileShader(fragment_shader);
	
	Shader program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);

	free(vertex_src);
	free(fragment_src);

	return program;
}

void use_shader(Shader shader) {
	glUseProgram(shader);
}