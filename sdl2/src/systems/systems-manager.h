#pragma once

#include <vector>
#include <memory>

#include "i-system.h"

class SystemsManager {
public:
    SystemsManager();
    ~SystemsManager();

    void initSystems(std::vector<System> systems);
    void update();

public:
    std::vector<System> getInitSystemNames() const;
    std::vector<System> getAvailableSystemNames() const;

private:
    std::vector<std::unique_ptr<ISystem>> m_systems;
};
