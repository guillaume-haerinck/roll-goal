#pragma once

#include "vertex-array.h"
#include "renderer-api.h"

/**
 * @brief Store draw requests on a stack for each frame and send them at once to the GPU
 * @detail It do not sends raw draw calls to the graphic API, it uses RendererApi to abstract that
 */
class Renderer {
public:
    Renderer();
    ~Renderer();

	void beginScene();
	void endScene();

	void submit(const std::shared_ptr<VertexArray>& vertexArray);

private:
	RendererApi rendererApi;
};


