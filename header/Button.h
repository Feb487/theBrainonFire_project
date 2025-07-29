//
// Created by giancarlo on 27/07/25.
//

#ifndef BUTTON_H
#define BUTTON_H

#include "../header/Mouse.h"

class Button {

        public:
        Button(int x, int y,const char* texDefault, const char* texClick);
        virtual ~Button();
        bool getIsSelected();
        void update(Mouse*);
        void draw();
        bool isSelected;

        SDL_Rect srect,drect;

    private:
        SDL_Texture *texDefault;
        SDL_Texture *texClick;
};


#endif //BUTTON_H
