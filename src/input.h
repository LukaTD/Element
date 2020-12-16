#pragma once

typedef struct mouse_t
{
	GLFWwindow *win;
	vec2 curr_pos, prev_pos, delta_pos;
} mouse_t;

void init_mouse(GLFWwindow *win, mouse_t *mouse)
{
	mouse->win = win; // assign cursor to a window

	f64 x, y;
	glfwGetCursorPos(win,&x,&y);
	mouse->curr_pos.x = (f32)x;
	mouse->curr_pos.y = (f32)y;
}

void get_mouse_input(mouse_t *mouse)
{
	mouse->prev_pos = mouse->curr_pos;

	f64 x, y;
	glfwGetCursorPos(mouse->win,&x,&y);
	mouse->curr_pos.x = (f32)x;
	mouse->curr_pos.y = (f32)y;
	//printf("x: %.0f, y: %.0f\n",mouse->curr_pos.data[0],mouse->curr_pos.data[1]);

	mouse->delta_pos = sub_vec2(mouse->curr_pos,mouse->prev_pos);
	//printf("dx: %.0f, dy: %.0f\n",mouse->delta_pos.data[0],mouse->delta_pos.data[1]);
}

typedef struct key_t
{
	i32 keycode;
	i32 prev_state;
	bool toggle;
} key_t;

#define num_keys 1u // number of keybinds used 
typedef struct keyboard_t
{
	GLFWwindow *win;
	key_t keys[num_keys];
} keyboard_t;


void init_keyboard(GLFWwindow *win, keyboard_t *keyboard)
{
	keyboard->win = win; // assign keyboard to a window

	keyboard->keys[0].keycode = GLFW_KEY_X;
	keyboard->keys[0].prev_state = GLFW_RELEASE;
	keyboard->keys[0].toggle = true;
}


void get_keyboard_input(keyboard_t *keyboard)
{
	for(u32 i = 0;i < num_keys;i++)
	{
		i32 curr_state = glfwGetKey(keyboard->win,keyboard->keys[i].keycode);

		if(keyboard->keys[i].toggle)
		{
			if(curr_state != keyboard->keys[i].prev_state)
			{
				if(curr_state == GLFW_PRESS)
					printf("a");

				keyboard->keys[i].prev_state = curr_state;
			}
		}
		else
		{
			printf("b");
		}
	}
}