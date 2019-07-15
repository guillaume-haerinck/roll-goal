#pragma once

/**
 * @brief Store draw requests for each frame and send them at once to the GPU
 * 
 */
class Renderer {
public:
    Renderer(/* args */);
    ~Renderer();

    void draw();
};


