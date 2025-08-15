#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "Menu.h"

class GameMenu : public GameState{
public:
    GameMenu(Game *game);
    virtual ~GameMenu();

    void handleEvents(Game* game, Mouse* mouse) override;
    void update() override;
    void draw() override; 

private:

    Button* buttonMemoria;
    Button* buttonLinguaggio;
    Button* buttonConcentrazione;
    Button* buttonBack;
    std::vector<Button*> buttons; 
    SDL_Rect Bsrect,Bdrect;
    SDL_Texture* backgroundGameMenu;

};
#endif

