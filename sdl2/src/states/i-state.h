#pragma once

/**
 * @brief The states that the game can be in
 * @detail Used as index of an array so must be continuous
 */
enum class GameState {
    LEVEL = 0,
    TITLE_SCREEN,
    GAME_OVER
};

/**
 * @brief Common interface for every state of the game
 * 
 */
class IState {
public:
    IState();
    virtual ~IState();

    virtual void onEnter() = 0;
    virtual void update() = 0;
    virtual void onExit() = 0;

public:
    virtual GameState getName() = 0; 
};
