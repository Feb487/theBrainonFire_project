#include "../header/GamePlayer.h"

GamePlayer::GamePlayer(){
    xpos = 0;
    ypos = 0;
}

GamePlayer::~GamePlayer() {
    if (objTexureD) SDL_DestroyTexture(objTexureD);
    if (objTexureA) SDL_DestroyTexture(objTexureA);
    if (objTexureW) SDL_DestroyTexture(objTexureW);
    if (objTexureS) SDL_DestroyTexture(objTexureS);
    if (animationW) SDL_DestroyTexture(animationW);
    if (animationA) SDL_DestroyTexture(animationA);
    if (animationS) SDL_DestroyTexture(animationS);
    if (animationD) SDL_DestroyTexture(animationD);
    if (animationDeath) SDL_DestroyTexture(animationDeath);
}

// Implementazione dei metodi get
int GamePlayer::getXpos() {
    return xpos;
}

int GamePlayer::getYpos() {
    return ypos;
}

// Implementazione dei metodi set
void GamePlayer::setXpos(int x) {
    xpos = x;
}

void GamePlayer::setYPos(int y) {
    ypos = y;
}

void GamePlayer::attivaDirezione(int indiceAttivo) {
    direzioni.fill(false);
    direzioni[indiceAttivo] = true;
}

void GamePlayer::setW(){ 
    currentTexture = animationW;
    attivaDirezione(0);
    if (ypos == 0) {
    ypos = ypos - SPEED;
    }
    else if (ypos <= 0){
        ypos = 0;
    }
}
void GamePlayer::setS(){
    currentTexture = animationS;
    attivaDirezione(1);
    if (ypos <=700){
        ypos = ypos + SPEED;
    }
    else{
        ypos = 694 ;
    }
}
void GamePlayer::setA(){
    currentTexture = animationA;
    attivaDirezione(2);
    if (xpos >= 0){
        xpos = xpos - SPEED;
    }
    else{
        xpos = 0;
    }

}
void GamePlayer::setD(){
    currentTexture = animationD;
    attivaDirezione(3);
    if (xpos >= 0){
        xpos = xpos + SPEED;
    }

}

/*
 * Associare gli attiva direzione ad una posizione di default
 * implementare funzioni update (gestione dei tasti) e draw (renderizzare con una sola funzione)
 * */
