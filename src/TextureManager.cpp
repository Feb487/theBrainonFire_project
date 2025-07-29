//
// Created by giancarlo on 27/07/25.
//
#include "../header/TextureManager.h"
#include <SDL2/SDL_image.h>

SDL_Texture* TextureManager::LoadTexture(const char *filepath) {
    SDL_Surface* tempSurface = IMG_Load(filepath);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::m_renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}


void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(Game::m_renderer,tex,&src,&dest);
}

