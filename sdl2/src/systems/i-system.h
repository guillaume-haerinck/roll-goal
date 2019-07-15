#pragma once

enum class System {
    PHYSIC,
    RENDER
};

class ISystem {
public:
    ISystem(System name) : m_name (name) {}
    virtual void update() = 0;

public:
    System getName() const { return m_name; }

private:
    System m_name;
};

