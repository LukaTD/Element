#include <stdio.h>
#include <stdlib.h>

#include <glfw3.h>

#include "types.h"
#include "linear_ops.h"
#include "window.h"

i32 main()
{
	if(!glfwInit())
	{
		printf("GLFW library could not be loaded!");
		return -1;
	}

	GLFWwindow *win = create_window("Element",1280,720);
	glfwMakeContextCurrent(win);

	while(!glfwWindowShouldClose(win))
	{
		glfwSwapBuffers(win);
		glfwPollEvents();
	}

	glfwDestroyWindow(win);
	glfwTerminate();
	return 0;
}
