#pragma once

/**
 * @brief Store draw requests on a stack for each frame and send them at once to the GPU
 */
class Renderer {
public:
    Renderer();
    ~Renderer();

    void draw();
};


