#pragma once

#include <vector>
#include <entt/entt.hpp>

#include "systems/i-system.h"

class StatesManager; // Forward declaration

/**
 * @brief The states that the game can be in
 * @detail Used as index of an array so must be continuous
 */
enum GameState {
    STATE_LEVEL = 0,
    STATE_TITLE_SCREEN,
    STATE_GAME_OVER,
    _STATE_MAX_NUMBER
};

/**
 * @brief Describe the step the state is currently in
 */
enum class StateLifeCycle {
	HAS_ENTERED,
	HAS_UPDATED,
	HAS_EXITED
};

/**
 * @brief Holds references to common objects used across game states
 */
// TODO add the renderer
// TODO add an audio player
// TODO add an event emitter
struct Context {
    StatesManager* statesManager = nullptr;
    entt::registry* registry = nullptr;
};

/**
 * @brief Common interface for every state of the game
 */
class IState {
public:
    IState(GameState name, Context context) : m_name(name), m_context(context) {}
    virtual ~IState() = default;
    virtual void onEnter() = 0;
    virtual void update() = 0;
    virtual void onExit() = 0;

public:
    GameState getName() const { return m_name; };
	StateLifeCycle getLifeCycle() const { return m_lifeCycle; };

protected:
	StateLifeCycle m_lifeCycle;
    GameState m_name;
    Context m_context;
    std::vector<ISystem*> m_systems;
};
