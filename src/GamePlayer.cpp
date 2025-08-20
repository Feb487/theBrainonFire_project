#include "../header/GamePlayer.h"

GamePlayer::GamePlayer(){
    xpos = 0;
    ypos = 0;
    currentFrame = 0;
    cFrame = 0;
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

void GamePlayer::init(const char* texturesheetD,const char* texturesheetA,
              const char* texturesheetW,const char* texturesheetS,
              const char* W,const char* A, const char* S, const char* D,const char* death,
              int x, int y){

    objTexureD = TextureManager::LoadTexture(texturesheetD); // default destra
    objTexureA = TextureManager::LoadTexture(texturesheetA); // default sinistra
    objTexureW = TextureManager::LoadTexture(texturesheetW);
    objTexureS = TextureManager::LoadTexture(texturesheetS);

    animationW = TextureManager::LoadTexture(W);
    animationA = TextureManager::LoadTexture(A);
    animationS = TextureManager::LoadTexture(S);
    animationD = TextureManager::LoadTexture(D);
    animationDeath = TextureManager::LoadTexture(death);

    xpos = x;
    ypos = y;


    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 32;
    srcRect.h = 32;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;

    currentAnimation = objTexureD;
}

void GamePlayer::handleEvents(SDL_Event& event){

    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_w:
                setW();
                break;

            case SDLK_a:
                setA();
                break;

            case SDLK_s:
                setS();
                break;

            case SDLK_d:
                setD();
                break;

            default:
                setDefault();
                break;
        }
    }
    else if (event.type == SDL_KEYUP) {
        setDefault();
    } 
   }

void GamePlayer::update(){
        cFrame++;
        if(cFrame >= rFrame){
            cFrame = 0;
            currentFrame = (currentFrame + 1) % totalFrames;
        }
        srcRect = { currentFrame * 32, 0, 32 , 32 };
        destRect.x = xpos;
        destRect.y = ypos;

}

void GamePlayer::draw(){
    SDL_RenderCopy(Game::m_renderer,currentAnimation,&srcRect,&destRect);
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

void GamePlayer::setDefault(){
    switch(lastAnimation) {
        case UP:    currentAnimation = objTexureW; break;
        case LEFT:  currentAnimation = objTexureA; break;
        case RIGHT: currentAnimation = objTexureD; break;
        case DOWN:  currentAnimation = objTexureS; break;
    }
}
void GamePlayer::setW(){ 
    currentAnimation = animationW;
    lastAnimation = UP;
    if (ypos >= 0) {
    ypos = ypos - SPEED;
    }
    else if (ypos <= 0){
        ypos = 0;
    }
}
void GamePlayer::setS(){
    currentAnimation = animationS;
    lastAnimation = DOWN;
    if (ypos <=700){
        ypos = ypos + SPEED;
    }
    else{
        ypos = 694 ;
    }
}
void GamePlayer::setA(){
    currentAnimation = animationA;
    lastAnimation = LEFT;
    if (xpos >= 0){
        xpos = xpos - SPEED;
    }
    else{
        xpos = 0;
    }

}
void GamePlayer::setD(){
    currentAnimation = animationD;
    lastAnimation = RIGHT;
    if (xpos >= 0){
        xpos = xpos + SPEED;
    }

}

