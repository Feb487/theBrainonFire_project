
#include "../header/Sound.h"

Sound::Sound()
{
    ostMenu = nullptr;
    ostMemoria = nullptr;
    soundClick = nullptr;
    soundGameOver = nullptr;
    soundVictory = nullptr;
    soundDamege = nullptr;
    soundWalk = nullptr;
    soundHit = nullptr;

       // Inizializzare SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }

    soundClick = Mix_LoadWAV(".//assets//Sounds//SoundEffect//click.wav");
    if (soundClick == NULL) {
        printf("Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    }

    soundGameOver = Mix_LoadWAV(".//assets//sfx//OST//SoundsEffects//mixkit-retro-game-over-1947.wav");
    soundVictory = Mix_LoadWAV(".//assets//sfx//OST//SoundsEffects//mixkit-game-bonus-reached-2065.wav");
    soundDamege = Mix_LoadWAV(".//assets//sfx//OST//SoundsEffects//mixkit-wrong-electricity-buzz-955.wav");

    // Caricare la musica di sottofondo
    ostMenu = Mix_LoadMUS(".//assets//Sounds//OST//menuv.wav");
    if (ostMenu == NULL) {
        printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
    }

    ostMemoria = Mix_LoadMUS(".//assets//sfx//OST//difficilissimo.mp3");
    if (ostMemoria == NULL) {
        printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
    }
}

Sound::~Sound() {
    // Libera le musiche
    if (ostMenu) {
        Mix_FreeMusic(ostMenu);
        ostMenu = nullptr;
    }

    if (ostMemoria) {
        Mix_FreeMusic(ostMemoria);
        ostMemoria = nullptr;
    }

    // Libera i suoni
    if (soundClick) {
        Mix_FreeChunk(soundClick);
        soundClick = nullptr;
    }

    if (soundGameOver) {
        Mix_FreeChunk(soundGameOver);
        soundGameOver = nullptr;
    }

    if (soundVictory) {
        Mix_FreeChunk(soundVictory);
        soundVictory = nullptr;
    }

    if (soundDamege) {
        Mix_FreeChunk(soundDamege);
        soundDamege = nullptr;
    }

    if (soundWalk) {
        Mix_FreeChunk(soundWalk);
        soundWalk = nullptr;
    }

    if (soundHit) {
        Mix_FreeChunk(soundHit);
        soundHit = nullptr;
    }
}

void Sound::playClick(){
     Mix_PlayChannel(-1, soundClick, 0);
}

void Sound::playGameOver(){
    Mix_PlayChannel(-1,soundGameOver,0);
}
void Sound::playVictory(){
    Mix_PlayChannel(-1,soundVictory,0);
}
void Sound::playDamage(){
    Mix_PlayChannel(-1,soundDamege,0);
}

void Sound::playOstMenu(){
     Mix_PlayMusic(ostMenu, -1);
}

void Sound::playOstMemoria(){
    Mix_PlayMusic(ostMemoria, -1);
}

void Sound::stopOstMemoria(){
    Mix_HaltMusic();
}

void Sound::stopOstMenu(){
    Mix_HaltMusic();
}
