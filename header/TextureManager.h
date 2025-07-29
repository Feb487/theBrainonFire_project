//
// Created by giancarlo on 27/07/25.
//

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "../header/Game.h"


class TextureManager {
    public:
        static SDL_Texture* LoadTexture(const char* filepath);
        static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);
};



#endif //TEXTUREMANAGER_H
