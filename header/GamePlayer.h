#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>
#include <array>

class GamePlayer {
public:
    GamePlayer();
    virtual ~GamePlayer();

    void init(const char* texturesheetD,const char* texturesheetA,const char* texturesheetW,const char* texturesheetS,const char* W,const char* A, const char* S, const char* D,const char* death, int x, int y);

    int getXpos();
    int getYpos();
    void setXpos(int x);
    void setYPos(int y);

    void setW();
    void setA();
    void setS();
    void setD();

    void attivaDirezione(int indiceAttivo);

private:

    int xpos;
    int ypos;

    std::array<bool, 4> direzioni = {false, false, false, false};
    SDL_Texture* objTexureD; 
    SDL_Texture* objTexureA; 
    SDL_Texture* objTexureW;
    SDL_Texture* objTexureS;
    SDL_Rect srcRect,destRect;

    SDL_Texture* animationW;
    SDL_Texture* animationA;
    SDL_Texture* animationS;
    SDL_Texture* animationD;
    SDL_Texture* animationDeath;

    int const SPEED = 4;
    
    SDL_Texture* currentTexture;

};

#endif
