#pragma once

enum class System {
    PHYSIC,
    RENDER
};

class ISystem {
public:
    System getName() const { return m_name; }

private:
    System m_name;
};

