#pragma once

#include <vector>
#include <memory>
#include <entt/entt.hpp>

#include "i-system.h"

/**
 * @brief Handles systems creation and updates
 * @detail The systems are always continuous in memory
 */
class SystemsManager {
public:
    SystemsManager(entt::registry& registry);
    ~SystemsManager();

    /**
     * @brief Create said systems on the stack
     */
    void initSystems(std::vector<System> systems);

    /**
     * @brief Update each initiated systems
     * @detail They are updated in the same order as they where created
     */
    void update();

    /**
     * @brief Delete all systems
     */
    void clear();

public:
    std::vector<System> getInitSystemNames() const;
    std::vector<System> getAvailableSystemNames() const;

private:
    std::vector<std::unique_ptr<ISystem>> m_systems;
    entt::registry& m_registry;
};
