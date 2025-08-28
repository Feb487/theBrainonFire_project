#include "../header/GameMenu.h"

GameMenu::GameMenu(Game* game){

    backgroundGameMenu = TextureManager::LoadTexture(".//assets//Backgrounds//bg_12.png");
    buttonMemoria = new Button(700,300,".//assets//menu_buttons//games-menu//Memoria_button.png",".//assets//menu_buttons//games-menu//Memoriapressed_button.png");
    buttonLinguaggio = new Button(700,390,".//assets//menu_buttons//games-menu//Linguaggio_button.png",".//assets//menu_buttons//games-menu//Linguaggiopressed_button.png");
    buttonConcentrazione = new Button(700,480,".//assets//menu_buttons//games-menu//Concentrazione_button.png",".//assets//menu_buttons//games-menu//Concentrazionepressed_button.png");
    buttonBack = new Button(700,570,".//assets//menu_buttons//games-menu//Indietro_button.png",".//assets//menu_buttons//games-menu//Indietropressed_button.png");
    
    buttons.push_back(buttonMemoria);
    buttons.push_back(buttonLinguaggio);
    buttons.push_back(buttonConcentrazione);
    buttons.push_back(buttonBack);

    Bsrect.x = 0;
    Bsrect.y = 0;
    Bsrect.h = 816;
    Bsrect.w = 1456;

    Bdrect.x = Bsrect.x;
    Bdrect.y = Bsrect.y;
    Bdrect.h = 736;
    Bdrect.w = 1216;

}

GameMenu::~GameMenu(){
    if (backgroundGameMenu) {
        SDL_DestroyTexture(backgroundGameMenu);
        backgroundGameMenu = nullptr;     
    }

    for (Button* button : buttons) { delete button;}
    buttons.clear(); 
}

void GameMenu::handleEvents(Game* game, Mouse* mouse){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
        game->setRunning(false);
    } else if (event.type == SDL_MOUSEBUTTONUP) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            if (buttonMemoria->getIsSelected()) {
                std::cout << "memoria cliccato" << std::endl;
                GameState* memoria = new Memoria(game);
                game->changeState(memoria);
                return;
            } else if (buttonConcentrazione->getIsSelected()) {
                std::cout << "concentrazione cliccato" << std::endl;
            } else if (buttonLinguaggio->getIsSelected()) {
                std::cout << "linguaggio cliccato" << std::endl;
            } else if (buttonBack->getIsSelected()){
                GameState* menu = new Menu(game);
                game->changeState(menu);
                return;
            }else{
                std::cout << "Nessun bottone selezionato" << std::endl;
            }
        }
    } else {
        buttonMemoria->setIsSelected(false);
        buttonLinguaggio->setIsSelected(false);
        buttonConcentrazione->setIsSelected(false);
    }
   }

    for (auto& button : buttons) { button->update(mouse);} 

}

void GameMenu::update(){}

void GameMenu::draw(){
    TextureManager::Draw(backgroundGameMenu,Bsrect,Bdrect);
    for (auto& button : buttons) { button->draw();} 
}
