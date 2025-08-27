#ifndef MENU_H
#define MENU_H

#include <vector>
#include "GameState.h"
#include "Button.h"
#include "Sound.h"

class Menu : public GameState {
public:
    Menu(Game* game);
    virtual ~Menu();

    void handleEvents(Game* game, Mouse* mouse) override;
    void update() override;
    void draw() override;

    void updateStartMenu(Mouse *mouse);
    void updateLogo();
    void drawStartMenu();    
      
    private:
    SDL_Rect srectWL,drectWL;
    Button *buttonPlay;
    Button *buttonExit;
    Button *buttonRule;
    Button *buttonOptions;
    SDL_Texture *backgrouds;
    SDL_Texture *logo;
    SDL_Rect Bsrect,Bdrect;
    SDL_Rect MGsrect,MGdrect;
    SDL_Rect Lsrect,Ldrect;
    std::vector<Button*> buttons; // Vettore di bottoni
    int frameLogo;
    int totalFrameLogo;
    int contatoreFrame;
    int ritardoFrame;
    Sound* soundMenu;
};

#endif // MENU_H
       
