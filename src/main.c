#include <stdio.h>
#include <stdlib.h>

#include <glfw3.h>

#include "types.h"
#include "linear_ops.h"
#include "window.h"
#include "input.h"

i32 main()
{
	if(!glfwInit())
	{
		printf("GLFW library could not be loaded!");
		return -1;
	}

	glfwWindowHint(GLFW_RESIZABLE,false);
	GLFWwindow *win = create_window("Element",1280,720);


	mouse_t mouse;
	init_mouse(win,&mouse);

	keyboard_t keyboard;
	init_keyboard(win,&keyboard);

	glfwMakeContextCurrent(win);

	while(!glfwWindowShouldClose(win))
	{
		get_mouse_input(&mouse);
		get_keyboard_input(&keyboard);
		process_mouse_input(&mouse);
		process_keyboard_input(&keyboard);


		glfwSwapBuffers(win);
		glfwPollEvents();
	}

	glfwDestroyWindow(win);
	glfwTerminate();
	return 0;
}
