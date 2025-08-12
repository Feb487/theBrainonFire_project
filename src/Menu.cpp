
#include "../header/Menu.h"
#include "../header/RuleMenu.h"
#include <unistd.h>


Menu::Menu(Game *game)
{
        buttonPlay = new Button(700,300,".//assets//menu_buttons//start-menu//Gioca_button.png",".//assets//menu_buttons//start-menu//Giocapressed_button.png");
        buttonRule = new Button(700,390,".//assets//menu_buttons//start-menu//Regole_button.png",".//assets//menu_buttons//start-menu//Regolepressed_button.png");
        buttonOptions = new Button(700,480,".//assets//menu_buttons//start-menu//Opzioni_button.png",".//assets//menu_buttons//start-menu//Opzionipressed_button.png");
        buttonExit = new Button(700,570,".//assets//menu_buttons//start-menu//Esci_button.png",".//assets//menu_buttons//start-menu//Escipressed_button.png");
        backgrouds = TextureManager::LoadTexture(".//assets//Backgrounds//bg_12.png");
        logo = TextureManager::LoadTexture(".//assets//game_logo//animation_logo.png");

        buttons.push_back(buttonPlay);
        buttons.push_back(buttonRule);
        buttons.push_back(buttonOptions);
        buttons.push_back(buttonExit);

                // rettangoli backgrouns

            // background Start Menu
            Bsrect.x = 0;
            Bsrect.y = 0;
            Bsrect.h = 816;
            Bsrect.w = 1456;

            Bdrect.x = Bsrect.x;
            Bdrect.y = Bsrect.y;
            Bdrect.h = 736;
            Bdrect.w = 1216;

            
        // rettangoli logo

        Ldrect.x = 370;
        Ldrect.y = 100;
        Ldrect.h = 100;
        Ldrect.w = 500;
        
        frameLogo = 0;
        totalFrameLogo = 8;
        contatoreFrame = 0;
        ritardoFrame = 8;
        
        game->soundGame->playOstMenu();

}
void Menu::handleEvents(Game* game, Mouse *mouse) {
    
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
        game->setRunning(false);
    } else if (event.type == SDL_MOUSEBUTTONUP) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            if (buttonPlay->getIsSelected()) {
                std::cout << "Pulsante Play cliccato!" << std::endl;
            } else if (buttonRule->getIsSelected()) {
                std::cout << "Pulsante Rule cliccato!" << std::endl;
                GameState* rulemenu = new RuleMenu(game);
                game->changeState(rulemenu);
                return;
            } else if (buttonExit->getIsSelected()) {
                std::cout << "Pulsante Exit cliccato, fine gioco..." << std::endl;
                game->setRunning(false);
            } else {
                std::cout << "Pulsante Option cliccato!" << std::endl;
            }
        }
    } else {
        buttonPlay->setIsSelected(false);
        buttonRule->setIsSelected(false);
        buttonOptions->setIsSelected(false);
    }
   }

    for (auto& button : buttons) {
                button->update(mouse);
            }    

} 
Menu::~Menu(){
    std::cout << "distruzione menu !" << std::endl;
    for (auto button : buttons) {
        delete button; 
    }
}
void Menu::update() {
        updateLogo();
}

void Menu::draw() {
    TextureManager::Draw(backgrouds,Bsrect,Bdrect);
    for (auto& button : buttons) {
            button->draw();
        }    
    TextureManager::Draw(logo,Lsrect,Ldrect);
}

void Menu::updateLogo(){
        contatoreFrame++;
        if(contatoreFrame >= ritardoFrame){

            contatoreFrame = 0;
            frameLogo = (frameLogo + 1) % totalFrameLogo;
        }

        Lsrect = { frameLogo * 1800, 0, 1805 , 380 };

}



