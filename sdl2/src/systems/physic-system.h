#pragma once

#include "i-system.h"

class PhysicSystem : public ISystem {
public:
    PhysicSystem(entt::registry& registry);
    ~PhysicSystem();

    void update();
};
