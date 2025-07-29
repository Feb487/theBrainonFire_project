//
// Created by giancarlo on 27/07/25.
//

#include "../header/Mouse.h"


Mouse::Mouse() {
    texture = TextureManager::LoadTexture(".//assets//Cursor//Cursore.png");
    rect.w = 32;
    rect.h = 32;
    point.x = 1;
    point.y = 1;
    SDL_ShowCursor(false);
}

void Mouse::update() {
    SDL_GetMouseState(&rect.x, &rect.y);
    point.x = rect.x;
    point.y = rect.y;
}

void Mouse::draw() const{
    SDL_RenderCopy(Game::m_renderer, texture,nullptr, &rect);
}
