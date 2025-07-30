#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "header/Game.h"

Game *game = nullptr;


int main (int argc,char *argv[]){
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("BrainOnFire",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1216,736,false);
    while (game->running()){

    frameStart = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->draw();

    frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime){
        SDL_Delay(frameDelay - frameTime);
    }

    }

    delete game;
    return 0;
}
