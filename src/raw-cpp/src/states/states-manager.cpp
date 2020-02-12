#include "states-manager.h"

#include <spdlog/spdlog.h>

#include "core/tags.h"
#include "components/singletons/game-input.h"
#include "level-state.h"
#include "title-screen-state.h"
#include "game-over-state.h"

StatesManager::StatesManager()
{
	uint32_t sEntity = initSingletonComponents();
	m_context = {
		this,
		&m_registry,
		sEntity
	};

    m_states.fill(nullptr);
	m_states.at(STATE_TITLE_SCREEN) = std::make_shared<TitleScreenState>(m_context);
    m_states.at(STATE_LEVEL) = std::make_shared<LevelState>(m_context);
	m_states.at(STATE_GAME_OVER) = std::make_shared<GameOverState>(m_context);
}

/////////////////////////////////////////////////////////////////////////////
////////////////////////////// PUBLIC METHODS ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////


void StatesManager::push(GameState state) {
	if (!isEmpty()) {
		m_stateStack.top()->onExit();
	}
    m_stateStack.push(m_states.at(state));
	m_stateStack.top()->onEnter();
}

void StatesManager::pop() {
	if (m_stateStack.size() > 1) {
		m_stateStack.top()->onExit();
		m_stateStack.pop();
		m_stateStack.top()->onEnter();
	}
}

void StatesManager::update() {
	m_stateStack.top()->update();
}

/////////////////////////////////////////////////////////////////////////////
//////////////////////////// GETTERS & SETTERS //////////////////////////////
/////////////////////////////////////////////////////////////////////////////


std::shared_ptr<IState> StatesManager::getActiveState() const {
    return m_stateStack.top();
}

bool StatesManager::isEmpty() const {
	return (m_stateStack.size() == 0) ? true : false;
}

/////////////////////////////////////////////////////////////////////////////
///////////////////////////// PRIVATE METHODS ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////

uint32_t StatesManager::initSingletonComponents() {
	uint32_t sEntity = m_registry.create();
	scomp::GameInput& inputs = m_registry.assign<scomp::GameInput>(sEntity);
	return sEntity;
}

bool StatesManager::handleSdlEvents() {
	scomp::GameInput& inputs = m_registry.get<scomp::GameInput>(m_context.singletonComponentsId);
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			return false;
	
		case SDL_KEYDOWN:
			inputs.actionState.at(ACTION_TILT) = true;
			break;

		case SDL_KEYUP:
			inputs.actionState.at(ACTION_TILT) = false;
			break;

		case SDL_MOUSEBUTTONDOWN:
			break;
		}
	}

	return true;
}
