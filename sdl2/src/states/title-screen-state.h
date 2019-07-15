#pragma once

#include "i-state.h"

class TitleScreenState : public IState {
public:
	TitleScreenState(entt::registry& registry);
	virtual ~TitleScreenState();

	void onEnter();
	void update();
	void onExit();
};
