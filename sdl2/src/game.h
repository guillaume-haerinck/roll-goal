#pragma once

#include <SDL2/SDL.h>
#include "states/states-manager.h"
#include "graphics/renderer.h"

/**
 * @brief Base root of the app
 * @description Handles all init and delegates the logic to the StatesManager
 */
class Game {
public:
    Game();
    ~Game();

    void update();

public:
    SDL_Window* getWindow() const;
    bool isRunning() const;
    void exit();

private:
    void initSDL();
    void initImgui() const;

private:
    SDL_Window* m_window;
    SDL_GLContext m_context;
    static bool m_instanciated;
    bool m_running;
    StatesManager m_states;
};
