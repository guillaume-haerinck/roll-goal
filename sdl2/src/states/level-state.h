#pragma once

#include "i-state.h"

class LevelState : public IState {
public:
    LevelState(Context context);
    virtual ~LevelState();

    void onEnter();
    void update();
    void onExit();
};
