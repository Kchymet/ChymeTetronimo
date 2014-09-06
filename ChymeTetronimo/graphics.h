#ifndef CHYME_TETRONIMO_GRAPHICS_H
#define CHYME_TETRONIMO_GRAPHICS_H

#include <glew.h>
#include <glfw3.h>
#include "board.h"

namespace Tetronimo{
	struct Graphics{
		GLFWwindow *window;
		GLubyte *renderer;
		GLubyte *version;

		Graphics(GLFWwindow*,GLubyte*,GLubyte*);

		void renderBoard(Board b);
	};
}

#endif //CHYME_TETRONIMO_GRAPHICS_H