#pragma once

#include "i-system.h"

class RenderSystem : public ISystem {
public:
    RenderSystem();
    ~RenderSystem();

    void update();
};
