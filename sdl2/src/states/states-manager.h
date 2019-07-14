#pragma once

#include <entt/entt.hpp>
#include <array>
#include <vector>

#include "i-state.h"

/**
 * @brief Pushdown Automaton to handle game states
 * @description Only one state can be active at a time
 * 
 * @link http://gameprogrammingpatterns.com/state.html
 */
class StatesManager {
public:
    StatesManager();
    ~StatesManager();

    /**
     * @brief Add a state on top of the stack
     * @detail The stack can have the same state multiple times
     */
    void push(GameState state);

    /**
     * @brief Make the state on top of the stack inactive
     * @exception Will not act if there is only one state in the stack
     */
    void pop();

    /**
     * @brief Update only the state on top of the stack
     */
    void update();

public:
    IState* getActiveState() const;
    bool isEmpty() const;

private:
    entt::registry m_registry;
    std::array<IState*, 3> m_states;
    std::vector<IState*> m_stateStack;
};
