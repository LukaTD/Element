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

void process_mouse_input(mouse_t *mouse)
{
	const vec2 zero = zeros_vec2();
	if(!equal_vec2(mouse->delta_pos,zero))
	{
		printf("Mouse moved in direction:\n");
		print_vec2(mouse->delta_pos);
	}
}

typedef struct key_t
{
	i32 keycode;
	i32 prev_state;
	bool toggle;
} key_t;

#define NUM_KEYS 2u // number of keybinds used, may be replaced later with a file with keybinds
typedef struct keyboard_t
{
	GLFWwindow *win;
	key_t keys[NUM_KEYS];
	bool pressed[NUM_KEYS];
} keyboard_t;

void init_key(key_t *key, const i32 keycode, const bool toggle)
{
	key->keycode = keycode;
	key->toggle = toggle;

	if(toggle)
		key->prev_state = GLFW_RELEASE;
}

void init_keyboard(GLFWwindow *win, keyboard_t *keyboard)
{
	keyboard->win = win; // assign keyboard to a window

	init_key(&keyboard->keys[0],GLFW_KEY_X,true);
	init_key(&keyboard->keys[1],GLFW_KEY_C,false);

	for(u32 i = 0;i < NUM_KEYS;i++)
		keyboard->pressed[i] = false;
}

void get_keyboard_input(keyboard_t *keyboard)
{
	for(u32 i = 0;i < NUM_KEYS;i++)
	{
		i32 curr_state = glfwGetKey(keyboard->win,keyboard->keys[i].keycode);

		if(keyboard->keys[i].toggle)
		{
			if(curr_state != keyboard->keys[i].prev_state)
			{
				if(curr_state == GLFW_PRESS)
					keyboard->pressed[i] = true;
					
				keyboard->keys[i].prev_state = curr_state;
			}
			else
				keyboard->pressed[i] = false;
		}
		else
			keyboard->pressed[i] = curr_state == GLFW_PRESS ? true : false;
	}
}

void process_keyboard_input(keyboard_t *keyboard /* possible additional parameters*/)
{
	for(u32 i = 0;i < NUM_KEYS;i++)
	{
		if(keyboard->pressed[i])
			printf("x");
	}
}