#pragma once

#include "i-system.h"

class PhysicSystem : public ISystem {
public:
    PhysicSystem();
    ~PhysicSystem();

    void update();
};
