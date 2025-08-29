#include "../header/Memoria.h"

Memoria::Memoria(Game* game){

    backGame = new Button(700,100,"assets//icons//general//back_icon.png","assets//icons//general//backpressed_icon.png");
    backGame->setDirect(48,48);
    
    backHome = new Button(760,100,"assets//icons//general//home_icon.png","assets//icons//general//homepressed_icon.png");
    backHome->setDirect(48,48);


    nextLevel = new Button(700,450,"assets//icons//winlose//icons//nextlevel_icon.png","assets//icons//winlose//icons//nextlevelpressed_icon.png");

    buttons.push_back(backGame);
    buttons.push_back(backHome);
    buttons.push_back(nextLevel);

    bandiera = TextureManager::LoadTexture("assets//icons//flags//redflag_animation.png");

    srectBAN.x = 0;
    srectBAN.y = 0;
    srectBAN.w = 60;
    srectBAN.h = 60;

    drectBAN.x = 1130;
    drectBAN.y = 325;
    drectBAN.w = srectBAN.w;
    drectBAN.h = srectBAN.h;


    srectWL.x = 0;
    srectWL.y = 0;
    srectWL.w = 800;
    srectWL.h = 380;

    drectWL.x = 450;
    drectWL.y = 200;
    drectWL.w = 400;
    drectWL.h = 180;

    mappa = new Map();
    player = new GamePlayer();
    player->init(".//assets//Sprite//Idle.png",
                                    ".//assets//Sprite//Idle2.png",
                                    ".//assets//Sprite//Ferma_dietro.png",
                                    ".//assets//Sprite//Ferma_avanti.png",
                                    ".//assets//Sprite//Cammina_dietro.png",
                                    ".//assets//Sprite//RunA.png",
                                    ".//assets//Sprite//Cammina_avanti.png",
                                    ".//assets//Sprite//RunD.png",
                                    ".//assets//Sprite//Dead.png",100,100);
    setPlayerPos(10,310);

    texVictory = TextureManager::LoadTexture("assets//icons//winlose//haivinto_animation.png");
    texLose = TextureManager::LoadTexture("assets//icons//winlose//haiperso_animation.png");

    win = false;
    isAlive = true;
    fChange = false;
}

Memoria::~Memoria() {
    for (Button* button : buttons) {
        delete button;
    }
    buttons.clear(); 

    if (bandiera) {
        SDL_DestroyTexture(bandiera);
        bandiera = nullptr; 
    }
    if (texVictory) {
        SDL_DestroyTexture(texVictory);
        texVictory = nullptr;
    }
    if (texLose) {
        SDL_DestroyTexture(texLose);
        texLose = nullptr;
    }
   

    delete player;
    player = nullptr;

    delete mappa;
    mappa = nullptr;
}
void Memoria::handleEvents(Game* game, Mouse* mouse){
 
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
        game->setRunning(false);
    } else if (event.type == SDL_MOUSEBUTTONUP) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            if (backGame->getIsSelected()) {
                std::cout << "Pulsante Play cliccato!" << std::endl;
                return;
            } else if (backHome->getIsSelected()) {
                std::cout << "Pulsante Rule cliccato!" << std::endl;
                return;
            } else if (nextLevel->getIsSelected()) {
                std::cout << "Pulsante Exit cliccato, fine gioco..." << std::endl;
                game->setRunning(false);
            } else {
                std::cout << "Pulsante Option cliccato!" << std::endl;
            }
        }
    } else {
        backGame->setIsSelected(false);
        backHome->setIsSelected(false);
        nextLevel->setIsSelected(false);
    }

    player->handleEvents(event);
   }

    for (auto& button : buttons) { button->update(mouse);}
}
void Memoria::update(){
    player->update();

    isAlive = mappa->checkBlock(player->getXpos(),player->getYpos());
    if(player->getXpos() > lineInsivibile ){
            if (fChange){
                    mappa->incrementaLivelloCorrente();
                    mappa->LoadMap();
                    fChange = false;
                }
            if (player->getXpos() >= 1100){ win =  true;}
    }
};
void Memoria::draw(){
    mappa->DrawMap();
    if (isAlive){
        backGame->draw();
        backHome->draw();
        player->draw();
        if(win){
            drawVictory();
            nextLevel->draw();
        }
    }else{
        drawLose();
        player->drawDeath();
    }

    
        
};

void Memoria::setPlayerPos(int xpos, int ypos){
    player->setXpos(xpos);
    player->setYPos(ypos);
}

void Memoria::drawVictory(){
    TextureManager::Draw(texVictory,srectWL,drectWL);
}

void Memoria::drawLose(){
    TextureManager::Draw(texLose,srectWL,drectWL);
}
