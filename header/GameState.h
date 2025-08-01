
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SDL2/SDL.h>

class Game; // Forward declaration della classe Game
class Mouse;
class Sound;

class GameState {
public:
    virtual ~GameState() {}

    virtual void handleEvents(Game* game, Mouse* mouse) = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
};

#endif // GAMESTATE_H
