#pragma once

#include "i-system.h"

/**
 * @brief Issue draw requests to the renderer class
 */
class RenderSystem : public ISystem {
public:
    RenderSystem(entt::registry& registry);
    ~RenderSystem();

    void update();
};
