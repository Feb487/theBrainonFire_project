#ifndef MEMORIA_H
#define MEMORIA_H

#include "GameState.h"
#include "Button.h"
#include "GamePlayer.h"
#include "Map.h"
#include "Mouse.h"

class Memoria : public GameState{
public:
    Memoria(Game* game);
    virtual ~Memoria();

    void handleEvents(Game* game, Mouse* mouse) override;
    void update() override;
    void draw() override;

private:
    GamePlayer* player;
    
    Button* backGame;
    Button* backHome;
    Button* nextLevel;
    std::vector<Button*> buttons;

    const int lineInsivibile = 40;
    bool win;
    bool isAlive;
    bool fChange;

    SDL_Texture* bandiera;
    SDL_Rect srectBAN,drectBAN;
    Map* mappa;

     //backgrund game over  & victory
    SDL_Texture* backGV;

    //VICTORY & LOSE GAME
    SDL_Texture* texVictory;
    SDL_Texture* texLose;

    void drawVictory();
    void drawLose();
    SDL_Rect srectWL,drectWL;
    
    void setPlayerPos(int xpos,int ypos);

};

#endif // MEMORIA_H
