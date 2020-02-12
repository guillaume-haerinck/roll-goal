#pragma once

#include <memory>
#include <vector>
#include "buffer.h"

/**
 * @brief 
 */
class VertexArray {
public:
    VertexArray();
    ~VertexArray();

    void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer);
    void addIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer);
	void bind() const;
	void unbind() const;

	const std::vector<std::shared_ptr<VertexBuffer>>& getVertexBuffers() const { return m_vertexBuffers; }
	const std::shared_ptr<IndexBuffer>& getIndexBuffer() const { return m_indexBuffer; }

private:
    std::vector<std::shared_ptr<VertexBuffer>> m_vertexBuffers;
    std::shared_ptr<IndexBuffer> m_indexBuffer;
	uint32_t m_rendererID;
};


