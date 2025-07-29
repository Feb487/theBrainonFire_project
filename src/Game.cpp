//
// Created by giancarlo on 27/07/25.
//

#include "../header/Game.h"
#include "../header/Mouse.h"
#include <bits/ostream.tcc>

//dichiarazione elementi globali
SDL_Renderer* Game::m_renderer = nullptr;
Mouse *mouse;

Game::Game() {
    ffscreen = 0;
    isRunning = true;
    m_window = nullptr;
}
Game::~Game() {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
    std::cout << "Game Cleaned"<<std::endl;
}

using namespace std;
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

    if (fullscreen) {
        ffscreen = SDL_WINDOW_FULLSCREEN;
    }

int n = SDL_GetNumAudioDrivers();
        for (int i = 0; i < n; ++i) {
        printf("Audio driver %d: %s\n", i, SDL_GetAudioDriver(i));
        }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {


        
        cout << "SDL_Init success" << endl;
        m_window = SDL_CreateWindow(title, xpos, ypos, width, height, ffscreen);
        if (m_window == nullptr) {
            cout << "SDL_CreateWindow failed" << endl;
        }
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
        if (m_renderer == nullptr) {
            cout << "SDL_CreateRenderer failed" << endl;
        }

        isRunning = true; // se tutto va bene avvisiamo che il gioco é in esecuzione
        mouse = new Mouse();

    }else
    {
        std::cout << "Errore nella inizilizzazione dei sistemi : " << SDL_GetError() << std::endl;
        isRunning = false; // se tutto va male, chiudiamo il gioco
    }

   }
void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            isRunning = false;
        }
    }
}

void Game::update() {
    mouse->update();
}
void Game::render() {
SDL_SetRenderDrawColor(m_renderer, 0, 128, 0, 255); // Colore di sfondo nero
    SDL_RenderClear(m_renderer);
    
    mouse->draw(); // Assicurati che questa funzione disegni qualcosa

    SDL_RenderPresent(m_renderer);
}

bool Game::running() {
    return isRunning;
}


