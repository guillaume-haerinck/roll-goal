#include "vertex-array.h"

#include <glad/glad.h>
#include <assert.h>
#include "gl-log-handler.h"

VertexArray::VertexArray() {
	GLCall(glGenVertexArrays(1, &m_rendererID));
}

VertexArray::~VertexArray() {
	GLCall(glDeleteVertexArrays(1, &m_rendererID));
}

void VertexArray::addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) {
	assert(vertexBuffer->getLayout().getElements().size() != 0);

	GLCall(glBindVertexArray(m_rendererID));
	vertexBuffer->bind();

	uint32_t index = 0;
	const auto& layout = vertexBuffer->getLayout();
	for (const auto& element : layout) {
		GLCall(glVertexAttribPointer(index,
			element.getComponentCount(),
			element.getOpenGlBaseType(),
			element.normalized ? GL_TRUE : GL_FALSE,
			layout.getStride(),
			(const void*) element.offset
		));
		index++;
	}

	m_vertexBuffers.push_back(vertexBuffer);
}

void VertexArray::addIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) {
	GLCall(glBindVertexArray(m_rendererID));
	indexBuffer->bind();
	m_indexBuffer = indexBuffer;
}

void VertexArray::bind() const {
	GLCall(glBindVertexArray(m_rendererID));
}

void VertexArray::unbind() const {
	GLCall(glBindVertexArray(0));
}
