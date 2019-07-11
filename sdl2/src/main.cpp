#include <stdio.h>
#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <entt/entt.hpp>
#ifdef __EMSCRIPTEN__
	#include <emscripten.h>
#endif

struct position {
	float x;
	float y;
};

void gameLoop(void* window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_KEYDOWN:
			printf("Key down ! \n");
			break;

		case SDL_MOUSEBUTTONDOWN:
			printf("Button down ! \n");
			break;
		}
	}

	SDL_GL_SwapWindow((SDL_Window*) window);
}

int main(int argc, char *argv[]) {
	// Init SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		printf("Cannot init SDL2 \n");
		return 1;
	}
	SDL_GL_LoadLibrary(NULL);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
	SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
	SDL_GL_SetSwapInterval(1);

	SDL_Window *window = SDL_CreateWindow(
		"Roll Goal",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		500, 500,
		SDL_WINDOW_OPENGL);
	if (window == nullptr)
	{
		printf("Cannot create window \n");
	}

	SDL_GLContext context = SDL_GL_CreateContext(window);
    if (context == nullptr) {
		printf("Context is null %s\n", SDL_GetError());

	}

	if (!gladLoadGLES2Loader(SDL_GL_GetProcAddress)) {
		printf("Glad not init ! \n");
	}

	// Test entt
	entt::registry registry;
	auto myentity = registry.create();

	registry.assign<position>(myentity, 0.0f, 0.0f);
	registry.view<position>().each([](auto& pos) {
		printf("Position x : %f \n", pos.x);
		pos.x += 5;
		printf("Position x : %f \n", pos.x);
	});

	// Test opengl
	glClearColor(1, 0, 0, 1);

	#ifdef __EMSCRIPTEN__
		emscripten_set_main_loop_arg(gameLoop, (void *) window, 0, 0);
	#else
	while (true) {
		gameLoop(window);
	}
	#endif

	return 0;
}


