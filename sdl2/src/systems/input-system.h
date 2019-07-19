#pragma once

#include "i-system.h"

/**
 * @brief Get the singleton component GameInput and apply it to the command pattern implementation
 */
class InputSystem : public ISystem
{
public:
	InputSystem(entt::registry &registry, uint32_t singletonComponentsId);
	~InputSystem();

	void update();

private:
	uint32_t m_singletonComponentsId;
};
