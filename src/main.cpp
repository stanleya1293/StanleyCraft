#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

int main(int argc, char* argv[]) 
{
	if (!glfwInit())
	{
		std::cerr << "ERROR INITIALIZING GLFW!" << std::endl;
	}
	
	GLFWwindow* window = glfwCreateWindow(800, 800, "Title", NULL, NULL);
	
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
	{
		std::cerr << "ERROR INTIALIZING GLAD!" << std::endl;
	}

	Shader shader("default");

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}
