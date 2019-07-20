#pragma once

#include <string>

class Shader {
public:
    Shader();
    ~Shader();

    void bind() const;
    void unbind() const;

private:
    uint32_t m_rendererID;
};

