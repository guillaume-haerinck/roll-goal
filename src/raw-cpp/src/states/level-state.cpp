#include "level-state.h"

#include "systems/physic-system.h"
#include "systems/render-system.h"
#include "systems/input-system.h"

LevelState::LevelState(Context context) : IState(STATE_LEVEL, context)
{
	m_systems = {
		new PhysicSystem(*context.registry),
		new RenderSystem(*context.registry),
		new InputSystem(*context.registry, context.singletonComponentsId)
	};
}

LevelState::~LevelState() {
	for (const auto system : m_systems) {
		delete system;
	}
}

/////////////////////////////////////////////////////////////////////////////
////////////////////////////// PUBLIC METHODS ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////


void LevelState::onEnter() {
	m_lifeCycle = StateLifeCycle::HAS_ENTERED;
}

void LevelState::update() {
	for (const auto system : m_systems) {
		system->update();
	}

	if (m_lifeCycle == StateLifeCycle::HAS_ENTERED)
		m_lifeCycle = StateLifeCycle::HAS_UPDATED;
}

void LevelState::onExit() {
	m_lifeCycle = StateLifeCycle::HAS_EXITED;
}


/////////////////////////////////////////////////////////////////////////////
//////////////////////////// GETTERS & SETTERS //////////////////////////////
/////////////////////////////////////////////////////////////////////////////


