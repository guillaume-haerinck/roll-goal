#pragma once

#include "i-state.h"

class GameOverState : public IState {
public:
	GameOverState(entt::registry& registry);
	virtual ~GameOverState();

	void onEnter();
	void update();
	void onExit();
};
