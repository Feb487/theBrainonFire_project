#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Game.h"
#include "Cube.h"



class Map{

public:
    Map();
    virtual ~Map();

    void LoadMap();
    void DrawMap();
    void numSafeBlock();
    void numLv();
    void incrementaLivelloCorrente();
    void decrementeLivelloCorrente();
    int getLivello();
    void setSafeBlock();
    bool checkBlock(int Xpos, int Ypos);

private:

    SDL_Rect src,dest;
    static const int righe = 23;
    static const int colonne = 38;
    static const int numLivelli = 4;
    
    Blocchi *blocco;
    Livelli livello;

    int mapp[righe][colonne];
    int livelli[numLivelli][righe][colonne];
    int livello_corrente;
    int num_safe_block;

    //GENERAL ASSETS SECTION//

    //Grass Assets
    SDL_Texture* grass1_ground;
    SDL_Texture* grass2_ground;
    SDL_Texture* grass3_ground;
    SDL_Texture* grass4_ground;
    SDL_Texture* grass5_ground;
    SDL_Texture* grass6_ground;

    //Mud Assets
    SDL_Texture* mud1_ground;
    SDL_Texture* mud2_ground;
    SDL_Texture* mud3_ground;
    SDL_Texture* mud4_ground;
    SDL_Texture* mud5_ground;
    SDL_Texture* mud6_ground;

    //Sand Assets
    SDL_Texture* sand1_ground;
    SDL_Texture* sand2_ground;

    //Water Assets
    SDL_Texture* water1_ground;
    SDL_Texture* water2_ground;
    SDL_Texture* water3_ground;
    SDL_Texture* water4_ground;

    //Mud&Grass Assets
    SDL_Texture* mugra1_ground;
    SDL_Texture* mugra2_ground;
    SDL_Texture* mugra3_ground;
    SDL_Texture* mugra4_ground;
    SDL_Texture* mugra5_ground;
    SDL_Texture* mugra6_ground;
    SDL_Texture* mugra7_ground;
    SDL_Texture* mugra8_ground;
    SDL_Texture* mugra9_ground;
    SDL_Texture* mugra10_ground;
    SDL_Texture* mugra11_ground;
    SDL_Texture* mugra12_ground;

//FLOWERS ASSETS SECTION//

    //Big Red Flower Assets
    SDL_Texture* grassbigred1_ground;
    SDL_Texture* grassbigred2_ground;
    SDL_Texture* grassbigred3_ground;
    SDL_Texture* grassbigred4_ground;
    SDL_Texture* grassbigred5_ground;
    SDL_Texture* grassbigred6_ground;

    //Small Red Flower Assets
    SDL_Texture* grasssmallred1_ground;
    SDL_Texture* grasssmallred2_ground;
    SDL_Texture* grasssmallred3_ground;
    SDL_Texture* grasssmallred4_ground;
    SDL_Texture* grasssmallred5_ground;
    SDL_Texture* grasssmallred6_ground;

    //Big Orange Flower Assets
    SDL_Texture* grassbigorange1_ground;
    SDL_Texture* grassbigorange2_ground;
    SDL_Texture* grassbigorange3_ground;
    SDL_Texture* grassbigorange4_ground;
    SDL_Texture* grassbigorange5_ground;
    SDL_Texture* grassbigorange6_ground;

    //Small Orange Flower Assets
    SDL_Texture* grasssmallorange1_ground;
    SDL_Texture* grasssmallorange2_ground;
    SDL_Texture* grasssmallorange3_ground;
    SDL_Texture* grasssmallorange4_ground;
    SDL_Texture* grasssmallorange5_ground;
    SDL_Texture* grasssmallorange6_ground;

    //Big Yellow Flower Assets
    SDL_Texture* grassbigyellow1_ground;
    SDL_Texture* grassbigyellow2_ground;
    SDL_Texture* grassbigyellow3_ground;
    SDL_Texture* grassbigyellow4_ground;
    SDL_Texture* grassbigyellow5_ground;
    SDL_Texture* grassbigyellow6_ground;

    //Small Yellow Flower Assets
    SDL_Texture* grasssmallyellow1_ground;
    SDL_Texture* grasssmallyellow2_ground;
    SDL_Texture* grasssmallyellow3_ground;
    SDL_Texture* grasssmallyellow4_ground;
    SDL_Texture* grasssmallyellow5_ground;
    SDL_Texture* grasssmallyellow6_ground;


//ROCK ASSETS SECTION//

    //Big Rock Assets
    SDL_Texture* mudbigrock1_ground;
    SDL_Texture* mudbigrock2_ground;
    SDL_Texture* mudbigrock3_ground;
    SDL_Texture* mudbigrock4_ground;
    SDL_Texture* mudbigrock5_ground;
    SDL_Texture* mudbigrock6_ground;

    //Small Rock Assets
    SDL_Texture* mudsmallrock1_ground;
    SDL_Texture* mudsmallrock2_ground;
    SDL_Texture* mudsmallrock3_ground;
    SDL_Texture* mudsmallrock4_ground;
    SDL_Texture* mudsmallrock5_ground;
    SDL_Texture* mudsmallrock6_ground;


//HOLES ASSETS SECTION//

    //Empty Hole
    SDL_Texture* emptyhole1_ground;
    SDL_Texture* emptyhole2_ground;
    SDL_Texture* emptyhole3_ground;
    SDL_Texture* emptyhole4_ground;
    SDL_Texture* emptyhole5_ground;
    SDL_Texture* emptyhole6_ground;
    SDL_Texture* emptyhole7_ground;
    SDL_Texture* emptyhole8_ground;

    //Black Hole
    SDL_Texture* blackhole1_ground;
    SDL_Texture* blackhole2_ground;
    SDL_Texture* blackhole3_ground;
    SDL_Texture* blackhole4_ground;
    SDL_Texture* blackhole5_ground;
    SDL_Texture* blackhole6_ground;
    SDL_Texture* blackhole7_ground;
    SDL_Texture* blackhole8_ground;

    //Water Hole
    SDL_Texture* waterhole1_ground;
    SDL_Texture* waterhole2_ground;
    SDL_Texture* waterhole3_ground;
    SDL_Texture* waterhole4_ground;
    SDL_Texture* waterhole5_ground;
    SDL_Texture* waterhole6_ground;
    SDL_Texture* waterhole7_ground;
    SDL_Texture* waterhole8_ground;

    // Tress
    SDL_Texture* forest1_ground;
    SDL_Texture* forest2_ground;
    SDL_Texture* forest3_ground;
    SDL_Texture* forest4_ground;
    SDL_Texture* forest5_ground;
    SDL_Texture* forest6_ground;
    SDL_Texture* forest7_ground;
    SDL_Texture* forest8_ground;
    SDL_Texture* forest9_ground;
    SDL_Texture* forest10_ground;
    SDL_Texture* forest11_ground;
    SDL_Texture* forest12_ground;
    SDL_Texture* forest13_ground;
    SDL_Texture* forest14_ground;
    SDL_Texture* forest15_ground;
    SDL_Texture* forest16_ground;
    SDL_Texture* forest17_ground;
    SDL_Texture* forest18_ground;
};

#endif
