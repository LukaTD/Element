#pragma once

#include <glfw3.h>

GLFWwindow* create_window(const char *title, const i32 width, const i32 height)
{
	GLFWwindow *win = glfwCreateWindow(width,height,title,NULL,NULL);

	if(!win)
	{
		printf("Window titled \"%s\" could not be created!",title);
		exit(-1);
	}

	return win;
}
