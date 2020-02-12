#include "input-system.h"

#include <spdlog/spdlog.h>
#include "components/singletons/game-input.h"

InputSystem::InputSystem(entt::registry& registry, uint32_t singletonComponentsId) 
: ISystem(registry), m_singletonComponentsId(singletonComponentsId)
{
}

InputSystem::~InputSystem()
{
}

void InputSystem::update() {
    scomp::GameInput& inputs = m_registry.get<scomp::GameInput>(m_singletonComponentsId);
    if (inputs.actionState.at(ACTION_TILT) == true) {
        spdlog::info("Tilt action enabled");
    }
}
