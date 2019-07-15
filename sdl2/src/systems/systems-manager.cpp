#include "systems-manager.h"

#include "physic-system.h"
#include "render-system.h"

SystemsManager::SystemsManager() {
}

SystemsManager::~SystemsManager() {
}

/////////////////////////////////////////////////////////////////////////////
////////////////////////////// PUBLIC METHODS ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void SystemsManager::initSystems(std::vector<System> systems) {
    for (System systemName : systems) {
        switch (systemName) {
        case System::PHYSIC:
            m_systems.push_back(std::make_unique<PhysicSystem>());
            break;

        case System::RENDER:
            m_systems.push_back(std::make_unique<RenderSystem>());
            break;
        
        default:
            break;
        }
    }
}

void SystemsManager::update() {

}

/////////////////////////////////////////////////////////////////////////////
//////////////////////////// GETTERS & SETTERS //////////////////////////////
/////////////////////////////////////////////////////////////////////////////

std::vector<System> SystemsManager::getInitSystemNames() const {
    std::vector<System> initSystemNames;

/* 
    for (auto system : m_systems) {
        switch (system->getName()) {
        case System::PHYSIC:
            initSystemNames.push_back(System::PHYSIC);
            break;

        case System::RENDER:
            initSystemNames.push_back(System::RENDER);
            break;
        
        default:
            break;
        }
    }
*/

    return initSystemNames;
}

std::vector<System> SystemsManager::getAvailableSystemNames() const {

}
