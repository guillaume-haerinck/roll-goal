#pragma once

#include <entt/entt.hpp>

enum class System {
    PHYSIC,
    RENDER
};

class ISystem {
public:
    ISystem(System name, entt::registry& registry) : m_name (name), m_registry(registry) {}
    virtual void update() = 0;

public:
    System getName() const { return m_name; }

protected:
    entt::registry& m_registry;

private:
    System m_name;
};
