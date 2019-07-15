#pragma once

#include "i-state.h"

class TitleScreenState : public IState {
public:
	TitleScreenState(Context context);
	virtual ~TitleScreenState();

	void onEnter();
	void update();
	void onExit();
};
