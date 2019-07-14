#pragma once

#include "i-state.h"

class TitleScreenState : public IState {
public:
	TitleScreenState();
	virtual ~TitleScreenState();

	void onEnter();
	void update();
	void onExit();

public:
	GameState getName() const;
};
