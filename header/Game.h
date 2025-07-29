//
// Created by giancarlo on 27/07/25.
//

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>
#include <iostream>


class Game {
    public:
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void update();
    void handleEvents();
    void render();
    bool running();
    static SDL_Renderer *m_renderer;

    private:
    int ffscreen;
    bool isRunning;
    SDL_Window *m_window;
};



#endif //GAME_H
