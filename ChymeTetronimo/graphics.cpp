#include "graphics.h"

namespace Tetronimo{
	Graphics::Graphics(GLFWwindow *window, GLubyte *renderer, GLubyte *version){
		this->window = window;
		this->renderer = renderer;
		this->version = version;
	}

	void Graphics::renderBoard(Board b){

	}
}