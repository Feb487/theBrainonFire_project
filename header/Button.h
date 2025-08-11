//
// Created by giancarlo on 27/07/25.
//

#ifndef BUTTON_H
#define BUTTON_H

#include "../header/Mouse.h"
#include <functional>

class Button
{
    public:
        Button(int x, int y,const char* texDefault, const char* texClick);
        virtual ~Button();
        bool getIsSelected();
        void setIsSelected(bool state);
        void update(Mouse*);
        void draw();
        void setDirect(int x, int y);
        SDL_Rect srect,drect;

    private:
        bool isSelected;
        SDL_Texture *texDefault;
        SDL_Texture *texClick;


};

#endif //BUTTON_H
