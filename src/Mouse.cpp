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

    }

void Mouse::draw() const{
    SDL_RenderCopy(Game::m_renderer, texture,nullptr, &rect);
}

bool Mouse::isClicked() const {
    return clicked; }
