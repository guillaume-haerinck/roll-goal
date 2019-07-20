#include "renderer.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::beginScene() {}

void Renderer::endScene() {}

void Renderer::submit(const std::shared_ptr<VertexArray>& vertexArray) {
	vertexArray->bind();
	rendererApi.drawIndexed(vertexArray);
}
