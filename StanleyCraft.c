#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int argc, char* argv[]) {
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(1000, 800, "StanleyCraft", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return 0;
}