#pragma once

#include "i-state.h"

class LevelState : public IState {
public:
    LevelState(entt::registry& registry);
    virtual ~LevelState();

    void onEnter();
    void update();
    void onExit();
};
