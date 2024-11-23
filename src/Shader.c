#include "Shader.h"


Shader loadShader(char* shader_name) {
	int shader_name_length = 2 * strlen(shader_name) + 16 * sizeof(char);

	char* vertex_path = (char*) malloc(shader_name_length);
	strcpy(vertex_path, "../shaders/");
	strcat(vertex_path, shader_name);
	strcat(vertex_path, "/");
	strcat(vertex_path, shader_name);
	strcat(vertex_path, ".vs");
	 
	char* fragment_path = (char*) malloc(shader_name_length);
	strcpy(fragment_path, "../shaders/");
	strcat(fragment_path,  shader_name);
	strcat(fragment_path, "/");
	strcat(fragment_path, shader_name);
	strcat(fragment_path, ".fs");  

	printf("Opening vertex shader file: %s\n", vertex_path);
	printf("Opening fragment shader file: %s\n", fragment_path);

	FILE* vertex_file = fopen(vertex_path, "r");
	if (vertex_file == NULL) {
		printf("Error opening vertex shader file!\n");
		return 0;
	}

	int vertex_file_count = 0;
	char c = fgetc(vertex_file);
	while (c != EOF) {
		vertex_file_count = vertex_file_count + 1;
		c = fgetc(vertex_file);
	}

	int vertex_file_size = (vertex_file_count + 1) * sizeof(char);
	char* vertex_src = (char*)malloc(vertex_file_size);
	
	freopen(vertex_path, "r", vertex_file);
	strcpy(vertex_src, "");
	while (c != EOF) {
		strcat(vertex_src, (char) fgetc(vertex_file));
	}
	fclose(vertex_file);


	FILE* fragment_file = fopen(fragment_path, "r");
	if (fragment_file == NULL) {
		printf("Error opening fragment shader file!\n");
		return 0;
	}

	int fragment_file_count = 0;
	c = fgetc(fragment_file);
	while (c != EOF) {
		fragment_file_count = fragment_file_count + 1;
		c = fgetc(fragment_file);
	}

	int fragment_file_size = (fragment_file_count + 1) * sizeof(char);
	char* fragment_src = (char*)malloc(fragment_file_size);

	freopen(fragment_path, "r", fragment_file);
	strcpy(fragment_src, "");
	while (c != EOF) {
		strcat(fragment_src, (char)fgetc(fragment_file));
	}
	fclose(fragment_file);

	printf("Initializing shaders\n");

	unsigned int vertex_shader;
	unsigned int fragment_shader;
	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(&vertex_shader, 1, vertex_src, NULL);
	glShaderSource(&fragment_shader, 1, fragment_src, NULL);

	printf("Starting vertex shader compilation\n");
	
	int vertex_success;
	char vertex_infolog[512];
	glCompileShader(vertex_shader);
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &vertex_success);
	if (!vertex_success) {
		glGetShaderInfoLog(vertex_shader, 512, NULL, vertex_infolog);
		printf("Error compiling vertex shader: %s\n", vertex_infolog);
	}

	printf("Starting fragment shader compilation\n");

	int fragment_success;
	char fragment_infolog[512];
	glCompileShader(fragment_shader);
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &fragment_success);
	if (!fragment_success) {
		glGetShaderInfoLog(fragment_shader, 512, NULL, fragment_infolog);
		printf("Error compiling vertex shader: %s\n", fragment_infolog);
	}
	
	printf("Starting program compilation\n");

	unsigned int shader_program;
	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);

	printf("Program compiled!\n");

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	free(vertex_path);
	free(fragment_path);
	free(vertex_src);
	free(fragment_src);
	return shader_program;
	
}

void useShader(Shader shader) {
	glUseProgram(shader);
}