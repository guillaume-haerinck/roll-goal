#include "states-manager.h"

#include "level-state.h"
#include "title-screen-state.h"
#include "game-over-state.h"

StatesManager::StatesManager(entt::registry& registry) : m_registry(registry) 
{
	Context context = {
		this,
		&m_registry
	};

    m_states.fill(nullptr);
	m_states.at(STATE_TITLE_SCREEN) = std::make_shared<TitleScreenState>(context);
    m_states.at(STATE_LEVEL) = std::make_shared<LevelState>(context);
	m_states.at(STATE_GAME_OVER) = std::make_shared<GameOverState>(context);
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
