#ifndef SOUND_H
#define SOUND_H

#include <SDL2/SDL_mixer.h>

class Sound
{
    public:
        Sound();
        virtual ~Sound();
        void playClick();
        void playOstMenu();
        void stopOstMenu();

        void playOstMemoria();
        void stopOstMemoria();

        void playGameOver();
        void playVictory();
        void playDamage();

    private:

        Mix_Music *ostMenu;
        Mix_Music *ostMemoria;
        Mix_Chunk *soundClick;
        Mix_Chunk *soundGameOver;
        Mix_Chunk *soundVictory;
        Mix_Chunk *soundDamege;
        Mix_Chunk *soundWalk;
        Mix_Chunk *soundHit;


};

#endif // SOUND_H
