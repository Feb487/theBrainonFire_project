#ifndef RULEMENU_H
#define RULEMENU_H

#include "Menu.h"

class RuleMenu : public GameState 
{
    public:
    RuleMenu(Game* game);
    virtual ~RuleMenu();

    void handleEvents(Game* game, Mouse* mouse) override;
    void update() override;
    void draw() override;

    private:
    Button *buttonNumGame1;
    Button *buttonNumGame2;
    Button *buttonNumGame3;
    Button *buttonExitRule;
    enum DrawRule {
        rule1,
        rule2,
        rule3
    };
    void setCurrentRule(DrawRule rule);
    DrawRule getCurrentRule();
    SDL_Texture* backRuleMemoria;
    SDL_Texture* backRuleLinguaggio;
    SDL_Texture* backRuleConcentrazione;
    std::vector<Button*> buttons; // Vettore di bottoni
    SDL_Rect Bsrect,Bdrect;
    DrawRule currentRule;
};

#endif // MENU_H
