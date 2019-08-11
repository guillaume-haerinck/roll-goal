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
#include <Ultralight/Ultralight.h>
#include "graphics/gl-log-handler.h"
#include "graphics/buffer.h"
#include "graphics/shader.h"
#include "graphics/vertex-array.h"
#include "graphics/ultralight-driver.h"

void gameLoop(void* data);

int main(int argc, char *argv[]) {
	#ifdef _WIN32 // Check memory leaks
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	#endif

	Game* game = new Game();

	// ---------------- TEMP -----------------
	// Setup ultralight
    auto& platform = ultralight::Platform::instance();
    platform.set_config(ultralight::Config());
    ultralight::UltralightDriver* driver = new ultralight::UltralightDriver(1.0f);
    platform.set_gpu_driver(driver);
    ultralight::Ref<ultralight::Renderer> renderer = ultralight::Renderer::Create();
    ultralight::Ref<ultralight::View> view = renderer->CreateView(500, 500, false);
    view->LoadHTML("<button style='color:red'>Click me</button>");

	// Vertex buffer
	float vertices[] = {
        // Position         // UV
        -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, // lower-left
         1.0f, -1.0f, 0.0f, 1.0f, 1.0f, // lower-right
        -1.0f,  1.0f, 0.0f, 0.0f, 0.0f, // top-left
         1.0f,  1.0f, 0.0f, 1.0f, 0.0f  // top-right
    };
	std::shared_ptr<VertexBuffer> vb = std::make_shared<VertexBuffer>(vertices, sizeof(vertices));
	BufferLayout layout = {
		{ ShaderDataType::Float3, "position" },
		{ ShaderDataType::Float2, "uv" }
	};
	vb->setLayout(layout);
	VertexArray va;
	va.addVertexBuffer(vb);

	// Index buffer
	unsigned int indexes[] = {
        0, 1, 2,
        2, 1, 3
    };
    std::shared_ptr<IndexBuffer> ib = std::make_shared<IndexBuffer>(indexes, 6);
    va.addIndexBuffer(ib);
    Shader shader("res/shaders/basic/texture.vert", "res/shaders/basic/texture.frag");

	// ------------- END TEMP ----------------

	#ifdef __EMSCRIPTEN__
		emscripten_set_main_loop_arg(gameLoop, (void *) game, 0, 0);
	#else
		while (game->isRunning()) {
			// gameLoop((void *) game);

			// ------------------ TEMP ----------------
			glClear(GL_COLOR_BUFFER_BIT);

			renderer->Update();
			driver->BeginSynchronize();
			
			renderer->Render();

			// Restore gl state, because render changes it
			glBindFramebuffer(GL_FRAMEBUFFER, 0);

			driver->EndSynchronize();

			if (driver->HasCommandsPending()) {
				driver->DrawCommandList();
			}

			// Render ultralight to texture
			shader.bind();
			va.bind();
			ultralight::RenderTarget renderTarget = view->render_target();
			glBindTexture(GL_TEXTURE_2D, renderTarget.texture_id);
			glActiveTexture(GL_TEXTURE0);
			GLCall(glDrawElements(GL_TRIANGLES, ib->getCount(), GL_UNSIGNED_INT, (void*) 0));

			game->update();

			// ------------------- END TEMP ----------------

			SDL_GL_SwapWindow(game->getWindow());
		}
	#endif

	delete driver;

	delete game;
	return 0;
}

void gameLoop(void* data) {
	// TODO handle deltatime and sleep

	Game* game = static_cast<Game*>(data);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	game->update();
	
	SDL_GL_SwapWindow(game->getWindow());
}
