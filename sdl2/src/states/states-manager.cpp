#include "states-manager.h"

#include "level-state.h"
#include "title-screen-state.h"
#include "game-over-state.h"

StatesManager::StatesManager() {
    m_states.fill(nullptr);
	m_states.at(GameState::TITLE_SCREEN) = std::make_shared<TitleScreenState>();
    m_states.at(GameState::LEVEL) = std::make_shared<LevelState>();
	m_states.at(GameState::GAME_OVER) = std::make_shared<GameOverState>();
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
