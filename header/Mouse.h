//
// Created by giancarlo on 27/07/25.
//

#ifndef MOUSE_H
#define MOUSE_H
#include "../header/TextureManager.h"
#include <SDL2/SDL_mouse.h>

class Mouse {
    private:
        SDL_Texture* texture;
        SDL_Rect rect{};
        bool clicked;

    public:
        SDL_Rect point{};
        Mouse();
        void update();
        void draw() const;
        bool isClicked() const;
};


#endif //MOUSE_H
