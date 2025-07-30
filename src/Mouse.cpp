//
// Created by giancarlo on 27/07/25.
//

#include "../header/Mouse.h"


Mouse::Mouse() {
    texture = TextureManager::LoadTexture(".//assets//Cursor//Cursore.png");
    rect.w = 32;
    rect.h = 32;
    SDL_ShowCursor(false);
    clicked = false;
}

void Mouse::update() {
    SDL_GetMouseState(&rect.x, &rect.y);
    point.x = rect.x;
    point.y = rect.y;
    point.w = 1;
    point.h = 1;

    std::cout << "Mouse Position: (" << point.x << ", " << point.y << ")" << std::endl; // Debug
    // Controlla se il pulsante sinistro del mouse è stato premuto
    clicked = (SDL_GetMouseState(nullptr,nullptr) & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;
}

void Mouse::draw() const{
    SDL_RenderCopy(Game::m_renderer, texture,nullptr, &rect);
}

bool Mouse::isClicked() const {
    return clicked; }
