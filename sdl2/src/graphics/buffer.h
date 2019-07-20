#pragma once

#include <glad/glad.h>
#include <vector>
#include <string>
#include <assert.h>
#include <spdlog/spdlog.h>

/**
 * @brief 
 */
enum class ShaderDataType {
    None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
};


/**
 * @brief Returns the size in bytes corresponding to the shader data
 */
static uint32_t shaderDataTypeSize(ShaderDataType type) {
    switch (type) {
        case ShaderDataType::Float:     return 4;
        case ShaderDataType::Float2:    return 4 * 2;
        case ShaderDataType::Float3:    return 4 * 3;
        case ShaderDataType::Float4:    return 4 * 4;
        case ShaderDataType::Mat3:      return 4 * 3 * 3;
        case ShaderDataType::Mat4:      return 4 * 4 * 4;
        case ShaderDataType::Int:       return 4;
        case ShaderDataType::Int2:      return 4 * 2;
        case ShaderDataType::Int3:      return 4 * 3;
        case ShaderDataType::Int4:      return 4 * 4;
        case ShaderDataType::Bool:      return 1;
    }

    spdlog::error("[shaderDataTypeSize] Unknown type");
    assert(false);
    return 0;
}


/**
 * @brief 
 */
struct BufferElement {
    BufferElement() {}

    BufferElement(const std::string name, ShaderDataType type, bool normalized = false)
    : name(name), type(type), size(shaderDataTypeSize(type)), offset(0), normalized(normalized) {}

    std::string name;
    ShaderDataType type;
    uint32_t offset;
    uint32_t size;
    bool normalized;

    uint32_t getComponentCount() const {
        switch (type) {
            case ShaderDataType::Float:     return 1;
            case ShaderDataType::Float2:    return 2;
            case ShaderDataType::Float3:    return 3;
            case ShaderDataType::Float4:    return 4;
            case ShaderDataType::Mat3:      return 3 * 3;
            case ShaderDataType::Mat4:      return 4 * 4;
            case ShaderDataType::Int:       return 1;
            case ShaderDataType::Int2:      return 2;
            case ShaderDataType::Int3:      return 3;
            case ShaderDataType::Int4:      return 4;
            case ShaderDataType::Bool:      return 1;
        }

        spdlog::error("[getElementCount] Unknown type");
        assert(false);
        return 0;
    }

    GLenum getOpenGlBaseType() const {
        switch (type) {
            case ShaderDataType::Float:     return GL_FLOAT;
            case ShaderDataType::Float2:    return GL_FLOAT;
            case ShaderDataType::Float3:    return GL_FLOAT;
            case ShaderDataType::Float4:    return GL_FLOAT;
            case ShaderDataType::Mat3:      return GL_FLOAT;
            case ShaderDataType::Mat4:      return GL_FLOAT;
            case ShaderDataType::Int:       return GL_INT;
            case ShaderDataType::Int2:      return GL_INT;
            case ShaderDataType::Int3:      return GL_INT;
            case ShaderDataType::Int4:      return GL_INT;
            case ShaderDataType::Bool:      return GL_BOOL;
        }

        spdlog::error("[getOpenGlBaseType] Unknown type");
        assert(false);
        return 0;
    }
};


/**
 * @brief 
 */
class BufferLayout {
public:
    BufferLayout() {}

    BufferLayout(const std::initializer_list<BufferElement>& elements)
    : m_elements(elements)
    {
        calculateOffsetsAndStride();
    }

    inline const std::vector<BufferElement>& getElements() const { return m_elements; }
    inline const uint32_t getStride() const { return m_stride; }

    std::vector<BufferElement>::iterator begin() { return m_elements.begin(); }
    std::vector<BufferElement>::iterator end() { return m_elements.end(); }

private:
    void calculateOffsetsAndStride() {
        uint32_t offset = 0;
        m_stride = 0;
        for (auto& element : m_elements) {
            element.offset = offset;
            offset += element.size;
            m_stride += element.size;
        }
    }

private:
    std::vector<BufferElement> m_elements;
    uint32_t m_stride = 0;
};


/**
 * @brief 
 */
class VertexBuffer {
public:
    VertexBuffer(float* vertices, unsigned int size);
    ~VertexBuffer();

    void setLayout(const BufferLayout& layout) { m_layout = layout; }
    const BufferLayout& getLayout() const { return m_layout; }

public:
    void bind() const;
    void unbind() const;

private:
    unsigned int m_rendererID;
    BufferLayout m_layout;
};


/**
 * @brief 
 */
class IndexBuffer {
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

public:
    void bind() const;
    void unbind() const;

    inline unsigned int getCount() const { return m_count; }

private:
    unsigned int m_rendererID;
    unsigned int m_count;
};



