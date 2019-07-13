#pragma once

#include <SDL2/SDL.h>

class Game {
public:
    Game();
    ~Game();

public:
    SDL_Window* getWindow() const;
    bool isRunning() const;
    void exit();

private:
    SDL_Window* m_window;
    SDL_GLContext m_context;
    static bool m_instanciated;
    bool m_running;
};
