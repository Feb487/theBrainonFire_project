//
// Created by giancarlo on 27/07/25.
//

#include "../header/Button.h"

Button::Button(int x, int y,const char* texDefault, const char* texClick)
{
    this->texDefault = TextureManager::LoadTexture(texDefault);
    this->texClick = TextureManager::LoadTexture(texClick);

    srect.h = 81;
    srect.w = 163;

    srect.x = 0;
    srect.y = 0;

    drect.h = srect.h;
    drect.w = srect.w;
    drect.x = x - srect.w;
    drect.y = y - srect.h;

    isSelected = true;
    action = nullptr;

}

void Button::update(Mouse* mouse, Game* game){
    if(SDL_HasIntersection(&drect, &mouse->point)){
        isSelected = true;
        std::cout << "Mouse is over the button!" << std::endl; // Debug
        if(mouse->isClicked()){
            if(action){
                action(game);
            }
        }
    }
    else{
        isSelected = false;
    }
}

void Button::draw(SDL_Renderer* renderer){
    if(isSelected){
        SDL_RenderCopy(renderer,texClick,&srect,&drect);
    }
    else{
        SDL_RenderCopy(renderer,texDefault,&srect,&drect);
    }

}


 void Button::setAction(std::function<void(Game* game)> action) {
        this->action = action; // Imposta l'azione del bottone
    }


Button::~Button()
{
     // Libera le texture
    SDL_DestroyTexture(texDefault);
    SDL_DestroyTexture(texClick);   
}
