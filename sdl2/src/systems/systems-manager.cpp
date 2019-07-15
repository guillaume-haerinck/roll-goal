#include "systems-manager.h"

#include "physic-system.h"
#include "render-system.h"

SystemsManager::SystemsManager(entt::registry& registry) : m_registry(registry)
{
}

SystemsManager::~SystemsManager() {
}

/////////////////////////////////////////////////////////////////////////////
////////////////////////////// PUBLIC METHODS ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void SystemsManager::update() {

}

void SystemsManager::clear() {
    m_systems.clear();
}

/////////////////////////////////////////////////////////////////////////////
//////////////////////////// GETTERS & SETTERS //////////////////////////////
/////////////////////////////////////////////////////////////////////////////

std::vector<System> SystemsManager::getInitSystemNames() const {
    std::vector<System> initSystemNames;
    for (int i = 0; i < m_systems.size(); i++) {
        initSystemNames.push_back(m_systems.at(i)->getName());
    }
    return initSystemNames;
}

std::vector<System> SystemsManager::getAvailableSystemNames() const {
    return std::vector<System> {
        System::RENDER,
        System::PHYSIC
    };
}
