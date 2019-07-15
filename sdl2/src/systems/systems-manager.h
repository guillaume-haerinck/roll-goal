#pragma once

#include <vector>
#include <memory>
#include <entt/entt.hpp>

#include "i-system.h"

/**
 * @brief Handles systems creation and updates
 */
class SystemsManager {
public:
    SystemsManager(entt::registry& registry);
    ~SystemsManager();

    /**
     * @brief Create said systems on the stack
     */
    template<class System>
    void push() {
        m_systems.push_back(std::make_unique<System>(m_registry));
    }

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
