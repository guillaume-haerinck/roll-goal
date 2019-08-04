#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <entt/entt.hpp>
#include <spdlog/spdlog.h>
#include <imgui.h>
#include <imgui/imgui_impl_sdl.h>
#include <imgui/imgui_impl_opengl3.h>
#ifdef __EMSCRIPTEN__
	#include <emscripten.h>
#endif
#ifdef _WIN32
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
#endif

#include "game.h"

// TEMP
#include <memory>
#include "graphics/gl-log-handler.h"
#include "graphics/buffer.h"
#include "graphics/shader.h"
#include "graphics/vertex-array.h"

void gameLoop(void* data);

int main(int argc, char *argv[]) {
	#ifdef _WIN32 // Check memory leaks
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	#endif

	Game* game = new Game();

	// TEMP
	VertexArray va;
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	std::shared_ptr<VertexBuffer> vb = std::make_shared<VertexBuffer>(vertices, sizeof(vertices));
	BufferLayout layout = {
		{ ShaderDataType::Float3, "position" }
	};
	vb->setLayout(layout);
	va.addVertexBuffer(vb);

	Shader shader;
	shader.bind();
	va.bind();

	#ifdef __EMSCRIPTEN__
		emscripten_set_main_loop_arg(gameLoop, (void *) game, 0, 0);
	#else
		while (game->isRunning()) {
			gameLoop((void *) game);
		}
	#endif

	delete game;
	return 0;
}

void gameLoop(void* data) {
	// TODO handle deltatime and sleep

	Game* game = static_cast<Game*>(data);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// TEMP
	GLCall(glDrawArrays(GL_POINTS, 0, 9));

	game->update();
	
	SDL_GL_SwapWindow(game->getWindow());
}
