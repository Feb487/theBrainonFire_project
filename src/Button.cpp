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
}

void Button::update(Mouse* mouse){
    if(SDL_HasIntersection(&drect, &mouse->point)){
        isSelected = true;
    }
    else{
        isSelected = false;
    }
}

void Button::draw(){
    if(isSelected){
        SDL_RenderCopy(Game::m_renderer,texClick,&srect,&drect);
    }
    else{
        SDL_RenderCopy(Game::m_renderer,texDefault,&srect,&drect);
    }

}
bool Button::getIsSelected(){
    return isSelected;
}

void Button::setIsSelected(bool state){
    isSelected = state;
}
void Button::setDirect(int w, int h) {
    drect.w = w;
    drect.h = h;
}
Button::~Button()
{
     // Libera le texture
    SDL_DestroyTexture(texDefault);
    SDL_DestroyTexture(texClick);   
}
