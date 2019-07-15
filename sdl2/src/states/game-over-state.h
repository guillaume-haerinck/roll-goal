#pragma once

#include "i-state.h"

class GameOverState : public IState {
public:
	GameOverState(Context context);
	virtual ~GameOverState();

	void onEnter();
	void update();
	void onExit();
};
