#pragma once

#include <entt/entt.hpp>
#include <array>
#include <stack>
#include <memory>

#include "i-state.h"

/**
 * @brief Pushdown Automaton to handle game states
 * @description Only one state can be active at a time
 * @detail The registry is created here
 * 
 * @link http://gameprogrammingpatterns.com/state.html
 */
class StatesManager {
public:
    StatesManager();

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
	std::shared_ptr<IState> getActiveState() const;
    bool isEmpty() const;

private:
    entt::registry m_registry;
    std::array<std::shared_ptr<IState>, 3> m_states;
    std::stack<std::shared_ptr<IState>> m_stateStack;
};
