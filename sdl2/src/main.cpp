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

#include "game.h"

void gameLoop(void* data);

int main(int argc, char *argv[]) {
	Game* game = new Game();

	#ifdef __EMSCRIPTEN__
		emscripten_set_main_loop_arg(gameLoop, (void *) game, 0, 0);
	#else
		while (true) {
			gameLoop((void *) game);
		}
	#endif

	delete game;
	return 0;
}

void gameLoop(void* data) {
	Game* game = static_cast<Game*>(data);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame(game->getWindow());
		ImGui::NewFrame();
		ImGui::Begin("Main debug window");
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
	}
	
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_KEYDOWN:
			spdlog::info("Key down");
			break;

		case SDL_MOUSEBUTTONDOWN:
			spdlog::info("Button down");
			break;
		}
	}

	SDL_GL_SwapWindow(game->getWindow());
}
