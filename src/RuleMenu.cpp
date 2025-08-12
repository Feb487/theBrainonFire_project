
#include "../header/RuleMenu.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
int x=0;
RuleMenu::RuleMenu(Game* game) {
    backRuleMemoria = TextureManager::LoadTexture(".//assets//background//backgroundregole//backgroundmemoria_regole.png");
    backRuleLinguaggio = TextureManager::LoadTexture(".//assets//background//backgroundregole//backgroundlinguaggio_regole.png");
    backRuleConcentrazione = TextureManager::LoadTexture(".//assets//background//backgroundregole//backgroundconcentrazione_regole.png");
    
    buttonNumGame1 = new Button(660,730,".//assets//icons//rulesnumber//1normal_icon.png",".//assets//icons//rulesnumber//1selected_icon.png");
    buttonNumGame2 = new Button(710,730,".//assets//icons//rulesnumber//2normal_icon.png",".//assets//icons//rulesnumber//2selected_icon.png");
    buttonNumGame3 = new Button(760,730,".//assets//icons//rulesnumber//3normal_icon.png",".//assets//icons//rulesnumber//3selected_icon.png");
    buttonExitRule = new Button(810,730,".//assets//icons//general//close_icon.png",".//assets//icons//general//close_icon.png");
    
    buttonNumGame1->setDirect(48,48);
    buttonNumGame2->setDirect(48,48);
    buttonNumGame3->setDirect(48,48);
    buttonExitRule->setDirect(48,48);

    
    buttons.push_back(buttonNumGame1);
    buttons.push_back(buttonNumGame2);
    buttons.push_back(buttonNumGame3);
    buttons.push_back(buttonExitRule);


    Bsrect.x = 0;
    Bsrect.y = 0;
    Bsrect.h = 816;
    Bsrect.w = 1456;

    Bdrect.x = Bsrect.x;
    Bdrect.y = Bsrect.y;
    Bdrect.h = 736;
    Bdrect.w = 1216;
   }

// Distruttore
RuleMenu::~RuleMenu() {
    // Libera le texture
    if (backRuleMemoria != nullptr) {
        SDL_DestroyTexture(backRuleMemoria);
    }
    if (backRuleLinguaggio != nullptr) {
        SDL_DestroyTexture(backRuleLinguaggio);
    }
    if (backRuleConcentrazione != nullptr) {
        SDL_DestroyTexture(backRuleConcentrazione);
    }

    // Libera i pulsanti
    delete buttonNumGame1;
    delete buttonNumGame2;
    delete buttonNumGame3;
    delete buttonExitRule;
    
}

// Metodo per aggiornare le regole in base al mouse
void RuleMenu::handleEvents(Game* game,Mouse* mouse) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
        game->setRunning(false);
    } else if (event.type == SDL_MOUSEBUTTONUP) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            if (buttonNumGame1->getIsSelected()) {
                std::cout << "Pulsante Num1 cliccato!" << std::endl;
                    x=0;
            } else if (buttonNumGame2->getIsSelected()) {
                std::cout << "Pulsante Num2 cliccato!" << std::endl;
                    x=1;
            } else if (buttonNumGame3->getIsSelected()) {
                std::cout << "Pulsante Num3 cliccato" << std::endl;
                x=2;
            } else {
                std::cout << "Esci cliccato" << std::endl;
                GameState* menu = new Menu(game);
                game->changeState(menu);
                return;
            }
        }
    } else {
        buttonNumGame1->setIsSelected(false);
        buttonNumGame2->setIsSelected(false);
        buttonNumGame3->setIsSelected(false);
    }
   }
        for (auto& button : buttons) {
                button->update(mouse);
            }  
}

void RuleMenu::update(){
//nothig to update...    
}
void RuleMenu::setCurrentRule(DrawRule rule) {
    currentRule = rule;
}

// Implementazione del metodo per ottenere la regola corrente
RuleMenu::DrawRule RuleMenu::getCurrentRule() {
    return currentRule;
}

void RuleMenu::draw(){
    if (x == 0){
        TextureManager::Draw(backRuleConcentrazione,Bsrect,Bdrect);
    }else if (x == 1){
        TextureManager::Draw(backRuleLinguaggio,Bsrect,Bdrect);
    }else{
        TextureManager::Draw(backRuleMemoria,Bsrect,Bdrect);
    }           
    for (auto& button : buttons) { button->draw();}  
}

