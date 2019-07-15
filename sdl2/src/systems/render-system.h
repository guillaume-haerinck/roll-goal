#pragma once

#include "i-system.h"

/**
 * @brief Issue draw requests to the renderer class
 */
class RenderSystem : public ISystem {
public:
    RenderSystem();
    ~RenderSystem();

    void update();
};
