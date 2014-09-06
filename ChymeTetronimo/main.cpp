#include <stdio.h>
#include <stdlib.h>
#include <glew.h>
#include <glfw3.h>

#include "board.h"
#include "tile.h"

using namespace Tetronimo;

int main(char argc, char **argv){
	//GL init ...
	if (!glfwInit()){
		fprintf(stderr, "ERROR: Could not start GLFW3");
		return EXIT_FAILURE;
	}

	GLFWwindow* window = glfwCreateWindow(1280, 720, "Hello Triangle", NULL, NULL);
	if (!window) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		return EXIT_FAILURE;
	}
	glfwMakeContextCurrent(window);

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	system("PAUSE");
	return EXIT_SUCCESS;
}