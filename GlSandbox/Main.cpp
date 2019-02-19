#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include "Shader.h"
#include "Vertex.h"
#include "Mesh.h"

#ifdef _MSC_VER
#	pragma comment(lib, "opengl32.lib")
#	pragma comment(lib, "glfw3.lib")
#endif

int main(void)
{
	if (!glfwInit()) return -1;
	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) return -1;

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0)),
						   Vertex(glm::vec3( 0  ,  0.5, 0)),
						   Vertex(glm::vec3( 0.5, -0.5, 0)) };
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./res/shaders/basic_shader");
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		shader.Bind();
		mesh.Draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}