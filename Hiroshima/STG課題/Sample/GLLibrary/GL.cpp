#include "GL.h"

GLFWwindow* GL::window;
RECT GL::window_rect;
int GL::window_x;
int GL::window_y;
int GL::window_width;
int GL::window_height;
int GL::focus = GLFW_TRUE;
HWND GL::hWnd;
void GL::UpdateWindosRect(int x, int y, int w, int h) {
	window_x = x; window_y = y;
	window_width = w; window_height = h;
	window_rect.top = window_y + 32;
	window_rect.left = window_x + 16;
	window_rect.right = window_x + window_width - 16;
	window_rect.bottom = window_x + window_height - 24;
}