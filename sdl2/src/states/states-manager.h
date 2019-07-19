#pragma once

#include <entt/entt.hpp>
#include <SDL2/SDL.h>
#include <array>
#include <stack>
#include <memory>

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

    /**
     * @brief Update the GameInput component
     * @returns false if SDL_QUIT
     */
    bool handleSdlEvents();

public:
	std::shared_ptr<IState> getActiveState() const;
    bool isEmpty() const;

private:
    /**
     * @brief Creates single-instance components used across the game to save some states
     * @exemple Input handling
     * 
     * @return uint32_t - The id of the entity that holds them
     */
    uint32_t initSingletonComponents();

private:
    entt::registry m_registry;
    std::array<std::shared_ptr<IState>, _STATE_MAX_NUMBER> m_states;
    std::stack<std::shared_ptr<IState>> m_stateStack;
    Context m_context;
};
