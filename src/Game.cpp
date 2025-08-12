//
// Created by giancarlo on 27/07/25.
//

#include "../header/Game.h"
#include "../header/Mouse.h"
#include "../header/Menu.h"
#include "../header/RuleMenu.h"
#include <bits/ostream.tcc>

//dichiarazione elementi globali
SDL_Renderer* Game::m_renderer = nullptr;
Mouse *mouse = nullptr;

Game::Game() {
    
    ffscreen = 0;
    isRunning = true;
    m_window = nullptr;
}
Game::~Game() {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
    delete currentState;
    std::cout << "Game Cleaned"<<std::endl;
}

void Game::setRunning(bool state){
    isRunning = state; 
}

void Game::changeState(GameState* newState){
    if (currentState != nullptr) {
        delete currentState; // Libera il vecchio stato
    }
    currentState = newState; // Imposta il nuovo stato}
}
using namespace std;
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

    if (fullscreen) {
        ffscreen = SDL_WINDOW_FULLSCREEN;
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
        soundGame = new Sound(); 
        mouse = new Mouse();
        
        currentState = new Menu(this); 

    }else
    {
        std::cout << "Errore nella inizilizzazione dei sistemi : " << SDL_GetError() << std::endl;
        isRunning = false; // se tutto va male, chiudiamo il gioco
    }
}
void Game::handleEvents() {
        mouse->update();
        currentState->handleEvents(this,mouse);    
}

void Game::update() { 
    currentState->update();
}

void Game::draw(){
    SDL_RenderClear(m_renderer);
        currentState->draw();
        mouse->draw(); // Assicurati che questa funzione disegni qualcosa
    SDL_RenderPresent(m_renderer);
}

bool Game::running() {
    return isRunning;
}

