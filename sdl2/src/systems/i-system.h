#pragma once

#include <entt/entt.hpp>

class ISystem {
public:
    ISystem(entt::registry& registry) : m_registry(registry) {}
    virtual ~ISystem() = default;
    virtual void update() = 0;

protected:
    entt::registry& m_registry;
};
