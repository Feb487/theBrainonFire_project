
#include "../header/Menu.h"
#include <unistd.h>


Menu::Menu(Game *game)
{
        buttonPlay = new Button(700,300,".//assets//menu_buttons//start-menu//Gioca_button.png",".//assets//menu_buttons//start-menu//Giocapressed_button.png");
        buttonRule = new Button(700,390,".//assets//menu_buttons//start-menu//Regole_button.png",".//assets//menu_buttons//start-menu//Regolepressed_button.png");
        buttonOptions = new Button(700,480,".//assets//menu_buttons//start-menu//Opzioni_button.png",".//assets//menu_buttons//start-menu//Opzionipressed_button.png");
        buttonExit = new Button(700,570,".//assets//menu_buttons//start-menu//Esci_button.png",".//assets//menu_buttons//start-menu//Escipressed_button.png");
        backgrouds = TextureManager::LoadTexture(".//assets//Backgrounds//bg_12.png");
        logo = TextureManager::LoadTexture(".//assets//game_logo//animation_logo.png");

        buttonPlay->setAction([](Game* game){
            game->soundGame->playClick();
        });
        buttonRule->setAction([](Game* game){
            game->soundGame->playClick();
        });
        buttonOptions->setAction([](Game* game){
            game->soundGame->playClick();
        });
        buttonExit->setAction([](Game* game){
            game->soundGame->playClick();
            game->setRunning(false);
        });

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
            }
            for (auto& button : buttons) {
                button->update(mouse,game); // Passa il puntatore del mouse
            }
        }
    }
Menu::~Menu()
{
    std::cout << "distruzione menu !" << std::endl;
        for (auto button : buttons) {
            delete button; // Libera la memoria dei bottoni
        }
}
void Menu::update() {
    updateLogo();
}

void Menu::draw() {
    TextureManager::Draw(backgrouds,Bsrect,Bdrect);
    for (auto& button : buttons) {
            button->draw(Game::m_renderer);
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



