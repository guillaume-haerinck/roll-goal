#pragma once

#include "i-state.h"

class GameOverState : public IState {
public:
	GameOverState();
	virtual ~GameOverState();

	void onEnter();
	void update();
	void onExit();

public:
	GameState getName() const;
};
