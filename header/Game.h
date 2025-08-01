//
// Created by giancarlo on 27/07/25.
//

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "GameState.h"
#include "Sound.h"


class Game {
    public:
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void update();
    void handleEvents();
    void draw();
    void setRunning(bool state);
    bool running();
    void changeState(GameState* newState);
    static SDL_Renderer *m_renderer;

    Sound* soundGame;

    private:
    GameState* currentState;
    int ffscreen;
    bool isRunning;
    SDL_Window *m_window;
};



#endif //GAME_H
