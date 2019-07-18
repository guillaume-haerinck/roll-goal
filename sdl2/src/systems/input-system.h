#pragma once

#include "i-system.h"

/**
 * @brief Get the singleton component GameInput and apply it to the command pattern implementation
 */
class InputSystem : public ISystem {
public:
        InputSystem(entt::registry& registry);
        ~InputSystem();

        void update();
};
