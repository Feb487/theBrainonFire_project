//
// Created by giancarlo on 27/07/25.
//

#ifndef BUTTON_H
#define BUTTON_H

#include "../header/Mouse.h"
#include <functional>

class Game; // Forward declaration della classe Game
class Mouse; // Forward declaration della classe Mouse

class Button {
public:
    Button(int x, int y, const char* texDefault, const char* texClick);
    virtual ~Button();

    void setAction(std::function<void(Game* game)> action);
    void update(Mouse* mouse, Game* game);
    void draw(SDL_Renderer* renderer);

private:
    SDL_Texture* texDefault;
    SDL_Texture* texClick;
    std::function<void(Game* game)> action;
    bool isSelected;
    SDL_Rect srect, drect;
};

#endif //BUTTON_H
