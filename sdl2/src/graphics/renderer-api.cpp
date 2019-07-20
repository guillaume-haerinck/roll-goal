#include "renderer-api.h"

#include "gl-log-handler.h"

RendererApi::RendererApi() {
}

RendererApi::~RendererApi() {
}
 
void RendererApi::setClearColor(glm::vec4 color) {
	GLCall(glClearColor(color.r, color.g, color.b, color.a));
}

void RendererApi::clear() {
	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void RendererApi::drawIndexed(const std::shared_ptr<VertexArray>& vertexArray) {
	GLCall(glDrawElements(GL_TRIANGLES, vertexArray->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr));
}
