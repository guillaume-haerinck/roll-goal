#pragma once

/**
 * @brief The states that the game can be in
 * @detail Used as index of an array so must be continuous
 */
enum GameState {
    LEVEL = 0,
    TITLE_SCREEN,
    GAME_OVER
};

/**
 * @brief Describe the step the state is currently in
 */
enum class LifeCycle {
	HAS_ENTERED,
	HAS_UPDATED,
	HAS_EXITED
};

/**
 * @brief Common interface for every state of the game
 */
class IState {
public:
    virtual void onEnter() = 0;
    virtual void update() = 0;
    virtual void onExit() = 0;

public:
    virtual GameState getName() const = 0;
	LifeCycle getLifeCycle() { return m_lifeCycle; };

protected:
	LifeCycle m_lifeCycle;
};
