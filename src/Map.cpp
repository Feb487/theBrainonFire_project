#include "../header/Map.h"
#include "../header/TextureManager.h"

void Map::incrementaLivelloCorrente(){
    livello_corrente = livello_corrente + 1;
}
void Map::numLv(){ // Carica tutte le mappe per ogni livello

    for(int k=0; k<numLivelli; k++){
        for(int i=0; i<righe; i++){
            for(int j=0; j<colonne; j++){
                if(k == 0){
                    livelli[k][i][j] = livello.lvl1[i][j]; //mappa con percorso visibile
                }
                else if( k == 1){
                    livelli[k][i][j] = livello.lvl1N[i][j]; //mappa con percorso invisibile
                }
                else if ( k == 2){
                    livelli[k][i][j] = livello.lvl2[i][j];
                }
                else if ( k == 3 ){
                    livelli[k][i][j] = livello.lvl2N[i][j];
                }

            }
        }
    }

}

void Map::numSafeBlock(){
    num_safe_block = 0;
    for(int i=0 ; i<righe;i++){
        for(int j=0; j<colonne; j++){
            if (livelli[livello_corrente][i][j] >= 7 && livelli[livello_corrente][i][j] <=12){
                num_safe_block++;
            }
        }
    }

    // Dealloca la memoria se è già stata allocata in precedenza
    if (blocco != nullptr) {
        delete[] blocco;
    }

     blocco = new Blocchi[num_safe_block];
     std::cout << "funziona numSafeBlock : " << num_safe_block << std::endl;

}

void Map::setSafeBlock(){
    int k=0;
    int i,j;
    for (i=0; i< righe; i++){
            for (j=0; j<colonne;j++){
                if (livelli[livello_corrente][i][j] >= 7 && livelli[livello_corrente][i][j] <=12 ){
                    blocco[k].sX = j*32;
                    blocco[k].mX = blocco[k].sX + 32;
                    blocco[k].sY = i*32;
                    blocco[k].mY = blocco[k].sY + 32;
                    std::cout << "BLOCCO " << k << " sX : " << blocco[k].sX << " mX : " << blocco[k].mX << " | " << " sY : " << blocco[k].sY << " mY : " << blocco[k].mY << std::endl;
                      k++;
                }
            }
    }

    std::cout << "funziona setSafeBlock" << std::endl;
}

bool Map::checkBlock(int Xpos, int Ypos){

    bool flag = false;
    for(int i=0; i<num_safe_block; i++){
        if(Xpos + 36 > blocco[i].sX && Xpos + 36 < blocco[i].mX && Ypos + 52 > blocco[i].sY && Ypos + 52 < blocco[i].mY ){
            blocco[i].thereIs = true;
        }
        else{
            blocco[i].thereIs = false;
        }
       flag = flag || blocco[i].thereIs;
    }

    return flag;

}

void Map::LoadMap(){

    for(int i=0; i<righe;i++){

        for(int j=0; j<colonne; j++){
            mapp[i][j] = livelli[livello_corrente][i][j];
        }
    }
}

Map::Map(){

    //caricamento texture grass
    grass1_ground = TextureManager::LoadTexture("assets//grounds//Grass//grass1_ground.png");
    grass2_ground = TextureManager::LoadTexture("assets//grounds//Grass//grass2_ground.png");
    grass3_ground = TextureManager::LoadTexture("assets//grounds//Grass//grass3_ground.png");
    grass4_ground = TextureManager::LoadTexture("assets//grounds//Grass//grass4_ground.png");
    grass5_ground = TextureManager::LoadTexture("assets//grounds//Grass//grass5_ground.png");
    grass6_ground = TextureManager::LoadTexture("assets//grounds//Grass//grass6_ground.png");

    //caricamento texture mud
    mud1_ground = TextureManager::LoadTexture("assets//grounds//Mud//mud1_ground.png");
    mud2_ground = TextureManager::LoadTexture("assets//grounds//Mud//mud2_ground.png");
    mud3_ground = TextureManager::LoadTexture("assets//grounds//Mud//mud3_ground.png");
    mud4_ground = TextureManager::LoadTexture("assets//grounds//Mud//mud4_ground.png");
    mud5_ground = TextureManager::LoadTexture("assets//grounds//Mud//mud5_ground.png");
    mud6_ground = TextureManager::LoadTexture("assets//grounds//Mud//mud6_ground.png");

    //caricamento texture
    sand1_ground = TextureManager::LoadTexture("assets//grounds//Sand//sand1_ground.png");
    sand2_ground = TextureManager::LoadTexture("assets//grounds//Sand//sand2_ground.png");

    //caricamento texture water
    water1_ground = TextureManager::LoadTexture("assets//grounds//Water//water1_ground.png");
    water2_ground = TextureManager::LoadTexture("assets//grounds//Water//water2_ground.png");
    water3_ground = TextureManager::LoadTexture("assets//grounds//Water//water3_ground.png");
    water4_ground = TextureManager::LoadTexture("assets//grounds//Water//water4_ground.png");

    //carimento texture grass&mud
    mugra1_ground = TextureManager::LoadTexture("assets//grounds//MudnGrass//mugra1_ground.png");
    mugra2_ground = TextureManager::LoadTexture("assets//grounds//MudnGrass//mugra2_ground.png");
    mugra3_ground = TextureManager::LoadTexture("assets//grounds//MudnGrass//mugra3_ground.png");
    mugra4_ground = TextureManager::LoadTexture("assets//grounds//MudnGrass//mugra4_ground.png");
    mugra5_ground = TextureManager::LoadTexture("assets//grounds//MudnGrass//mugra5_ground.png");
    mugra6_ground = TextureManager::LoadTexture("assets//grounds//MudnGrass//mugra6_ground.png");
    mugra7_ground = TextureManager::LoadTexture("assets//grounds//MudnGrass//mugra7_ground.png");
    mugra8_ground = TextureManager::LoadTexture("assets//grounds//MudnGrass//mugra8_ground.png");
    mugra9_ground = TextureManager::LoadTexture("assets//grounds//MudnGrass//mugra9_ground.png");
    mugra10_ground = TextureManager::LoadTexture("assets//grounds//MudnGrass//mugra10_ground.png");
    mugra11_ground = TextureManager::LoadTexture("assets//grounds//MudnGrass//mugra11_ground.png");
    mugra12_ground = TextureManager::LoadTexture("assets//grounds//MudnGrass//mugra12_ground.png");


    //caricamento texture Flower

        //caricamento texture  Big Red Flower
        grassbigred1_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//red//big//grassbigred1_ground.png");
        grassbigred2_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//red//big//grassbigred2_ground.png");
        grassbigred3_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//red//big//grassbigred3_ground.png");
        grassbigred4_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//red//big//grassbigred4_ground.png");
        grassbigred5_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//red//big//grassbigred5_ground.png");
        grassbigred6_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//red//big//grassbigred6_ground.png");

        //carimento texture Small Red Flower

        grasssmallred1_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//red//small//grasssmallred1_ground.png");
        grasssmallred2_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//red//small//grasssmallred2_ground.png");
        grasssmallred3_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//red//small//grasssmallred3_ground.png");
        grasssmallred4_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//red//small//grasssmallred4_ground.png");
        grasssmallred5_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//red//small//grasssmallred5_ground.png");
        grasssmallred6_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//red//small//grasssmallred6_ground.png");

        // caicamento texture Big Orange Flower

        grassbigorange1_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//orange//big//grassbigorange1_ground.png");
        grassbigorange2_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//orange//big//grassbigorange2_ground.png");
        grassbigorange3_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//orange//big//grassbigorange3_ground.png");
        grassbigorange4_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//orange//big//grassbigorange4_ground.png");
        grassbigorange5_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//orange//big//grassbigorange5_ground.png");
        grassbigorange6_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//orange//big//grassbigorange6_ground.png");

        // Small Orange Flower
        grasssmallorange1_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//orange//small//grasssmallorange1_ground.png");
        grasssmallorange2_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//orange//small//grasssmallorange2_ground.png");
        grasssmallorange3_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//orange//small//grasssmallorange3_ground.png");
        grasssmallorange4_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//orange//small//grasssmallorange4_ground.png");
        grasssmallorange5_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//orange//small//grasssmallorange5_ground.png");
        grasssmallorange6_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//orange//small//grasssmallorange6_ground.png");

        //Big Flower Yellow

        grassbigyellow1_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//yellow//big//grassbigyellow1_ground.png");
        grassbigyellow2_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//yellow//big//grassbigyellow2_ground.png");
        grassbigyellow3_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//yellow//big//grassbigyellow3_ground.png");
        grassbigyellow4_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//yellow//big//grassbigyellow4_ground.png");
        grassbigyellow5_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//yellow//big//grassbigyellow5_ground.png");
        grassbigyellow6_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//yellow//big//grassbigyellow6_ground.png");

        // Small Flower Yellow

        grasssmallyellow1_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//yellow//small//grasssmallyellow1_ground.png");
        grasssmallyellow2_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//yellow//small//grasssmallyellow2_ground.png");
        grasssmallyellow3_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//yellow//small//grasssmallyellow3_ground.png");
        grasssmallyellow4_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//yellow//small//grasssmallyellow4_ground.png");
        grasssmallyellow5_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//yellow//small//grasssmallyellow5_ground.png");
        grasssmallyellow6_ground = TextureManager::LoadTexture("assets//grounds//flowers-grass//yellow//small//grasssmallyellow6_ground.png");

    // Rock

            // BIG

        mudbigrock1_ground = TextureManager::LoadTexture("assets//grounds//rock-mud//big//mudbigrock1_ground.png");
        mudbigrock2_ground = TextureManager::LoadTexture("assets//grounds//rock-mud//big//mudbigrock2_ground.png");
        mudbigrock3_ground = TextureManager::LoadTexture("assets//grounds//rock-mud//big//mudbigrock3_ground.png");
        mudbigrock4_ground = TextureManager::LoadTexture("assets//grounds//rock-mud//big//mudbigrock4_ground.png");
        mudbigrock5_ground = TextureManager::LoadTexture("assets//grounds//rock-mud//big//mudbigrock5_ground.png");
        mudbigrock6_ground = TextureManager::LoadTexture("assets//grounds//rock-mud//big//mudbigrock6_ground.png");

            //SMALL

        mudsmallrock1_ground = TextureManager::LoadTexture("assets//grounds//rock-mud//small//mudsmallrock1_ground.png");
        mudsmallrock2_ground = TextureManager::LoadTexture("assets//grounds//rock-mud//small//mudsmallrock2_ground.png");
        mudsmallrock3_ground = TextureManager::LoadTexture("assets//grounds//rock-mud//small//mudsmallrock3_ground.png");
        mudsmallrock4_ground = TextureManager::LoadTexture("assets//grounds//rock-mud//small//mudsmallrock4_ground.png");
        mudsmallrock5_ground = TextureManager::LoadTexture("assets//grounds//rock-mud//small//mudsmallrock5_ground.png");
        mudsmallrock6_ground = TextureManager::LoadTexture("assets//grounds//rock-mud//small//mudsmallrock6_ground.png");

      // EmptyHole

      emptyhole1_ground = TextureManager::LoadTexture("assets//grounds//EmptyHole//emptyhole1_ground.png");
      emptyhole2_ground = TextureManager::LoadTexture("assets//grounds//EmptyHole//emptyhole2_ground.png");
      emptyhole3_ground = TextureManager::LoadTexture("assets//grounds//EmptyHole//emptyhole3_ground.png");
      emptyhole4_ground = TextureManager::LoadTexture("assets//grounds//EmptyHole//emptyhole4_ground.png");
      emptyhole5_ground = TextureManager::LoadTexture("assets//grounds//EmptyHole//emptyhole5_ground.png");
      emptyhole6_ground = TextureManager::LoadTexture("assets//grounds//EmptyHole//emptyhole6_ground.png");

    // blackHole

    blackhole1_ground = TextureManager::LoadTexture("assets//grounds//BlackHole//blackhole1_ground.png");
    blackhole2_ground = TextureManager::LoadTexture("assets//grounds//BlackHole//blackhole2_ground.png");
    blackhole3_ground = TextureManager::LoadTexture("assets//grounds//BlackHole//blackhole3_ground.png");
    blackhole4_ground = TextureManager::LoadTexture("assets//grounds//BlackHole//blackhole4_ground.png");
    blackhole5_ground = TextureManager::LoadTexture("assets//grounds//BlackHole//blackhole5_ground.png");
    blackhole6_ground = TextureManager::LoadTexture("assets//grounds//BlackHole//blackhole6_ground.png");
    blackhole7_ground = TextureManager::LoadTexture("assets//grounds//BlackHole//blackhole7_ground.png");
    blackhole8_ground = TextureManager::LoadTexture("assets//grounds//BlackHole//blackhole8_ground.png");

    // water hole

    waterhole1_ground = TextureManager::LoadTexture("assets//grounds//WaterHole//waterhole1_ground.png");
    waterhole2_ground = TextureManager::LoadTexture("assets//grounds//WaterHole//waterhole2_ground.png");
    waterhole3_ground = TextureManager::LoadTexture("assets//grounds//WaterHole//waterhole3_ground.png");
    waterhole4_ground = TextureManager::LoadTexture("assets//grounds//WaterHole//waterhole4_ground.png");
    waterhole5_ground = TextureManager::LoadTexture("assets//grounds//WaterHole//waterhole5_ground.png");
    waterhole6_ground = TextureManager::LoadTexture("assets//grounds//WaterHole//waterhole6_ground.png");
    waterhole7_ground = TextureManager::LoadTexture("assets//grounds//WaterHole//waterhole7_ground.png");
    waterhole8_ground = TextureManager::LoadTexture("assets//grounds//WaterHole//waterhole8_ground.png");

    // TRESS

    forest1_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest1_ground.png");
    forest2_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest2_ground.png");
    forest3_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest3_ground.png");
    forest4_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest4_ground.png");
    forest5_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest5_ground.png");
    forest6_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest6_ground.png");
    forest7_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest7_ground.png");
    forest8_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest8_ground.png");
    forest9_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest9_ground.png");
    forest10_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest10_ground.png");
    forest11_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest11_ground.png");
    forest12_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest12_ground.png");
    forest13_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest13_ground.png");
    forest14_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest14_ground.png");
    forest15_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest15_ground.png");
    forest16_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest16_ground.png");
    forest17_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest17_ground.png");
    forest18_ground = TextureManager::LoadTexture("assets//grounds//Forest//forest17_ground.png");


    livello_corrente = 0;
    blocco = nullptr;

    numLv();
    LoadMap();
    numSafeBlock();
    setSafeBlock();

    src.x  = 0;
    src.y = 0;
    src.w = 32;
    src.h = 32;

    dest.x = 0;
    dest.y = 0;
    dest.w = 32;
    dest.h = 32;

}

void Map::decrementeLivelloCorrente(){
    livello_corrente = livello_corrente - 1;
}


int Map::getLivello(){
    return livello_corrente;
}

void Map::DrawMap(){

    int i,j;

    int type=0;

    for(i=0; i<righe;i++){

        for(j=0; j<colonne; j++){

                dest.x = j*32;
                dest.y = i*32;

            type = mapp[i][j];

            switch (type) {
    case 1:
        TextureManager::Draw(grass1_ground, src, dest);
        break;
    case 2:
        TextureManager::Draw(grass2_ground, src, dest);
        break;
    case 3:
        TextureManager::Draw(grass3_ground, src, dest);
        break;
    case 4:
        TextureManager::Draw(grass4_ground, src, dest);
        break;
    case 5:
        TextureManager::Draw(grass5_ground, src, dest);
        break;
    case 6:
        TextureManager::Draw(grass6_ground, src, dest);
        break;
    case 7:
        TextureManager::Draw(mud1_ground, src, dest);
        break;
    case 8:
        TextureManager::Draw(mud2_ground, src, dest);
        break;
    case 9:
        TextureManager::Draw(mud3_ground, src, dest);
        break;
    case 10:
        TextureManager::Draw(mud4_ground, src, dest);
        break;
    case 11:
        TextureManager::Draw(mud5_ground, src, dest);
        break;
    case 12:
        TextureManager::Draw(mud6_ground, src, dest);
        break;
    case 13:
        TextureManager::Draw(sand1_ground, src, dest);
        break;
    case 14:
        TextureManager::Draw(sand2_ground, src, dest);
        break;
    case 15:
        TextureManager::Draw(water1_ground, src, dest);
        break;
    case 16:
        TextureManager::Draw(water2_ground, src, dest);
        break;
    case 17:
        TextureManager::Draw(water3_ground, src, dest);
        break;
    case 18:
        TextureManager::Draw(water4_ground, src, dest);
        break;
    case 19:
        TextureManager::Draw(mugra1_ground, src, dest);
        break;
    case 20:
        TextureManager::Draw(mugra2_ground, src, dest);
        break;
    case 21:
        TextureManager::Draw(mugra3_ground, src, dest);
        break;
    case 22:
        TextureManager::Draw(mugra4_ground, src, dest);
        break;
    case 23:
        TextureManager::Draw(mugra5_ground, src, dest);
        break;
    case 24:
        TextureManager::Draw(mugra6_ground, src, dest);
        break;
    case 25:
        TextureManager::Draw(mugra7_ground, src, dest);
        break;
    case 26:
        TextureManager::Draw(mugra8_ground, src, dest);
        break;
    case 27:
        TextureManager::Draw(mugra9_ground, src, dest);
        break;
    case 28:
        TextureManager::Draw(mugra10_ground, src, dest);
        break;
    case 29:
        TextureManager::Draw(mugra11_ground, src, dest);
        break;
    case 30:
        TextureManager::Draw(mugra12_ground, src, dest);
        break;
    case 31:
        TextureManager::Draw(grassbigred1_ground, src, dest);
        break;
    case 32:
        TextureManager::Draw(grassbigred2_ground, src, dest);
        break;
    case 33:
        TextureManager::Draw(grassbigred3_ground, src, dest);
        break;
    case 34:
        TextureManager::Draw(grassbigred4_ground, src, dest);
        break;
    case 35:
        TextureManager::Draw(grassbigred5_ground, src, dest);
        break;
    case 36:
        TextureManager::Draw(grassbigred6_ground, src, dest);
        break;
    case 37:
        TextureManager::Draw(grasssmallred1_ground, src, dest);
        break;
    case 38:
        TextureManager::Draw(grasssmallred2_ground, src, dest);
        break;
    case 39:
        TextureManager::Draw(grasssmallred3_ground, src, dest);
        break;
    case 40:
        TextureManager::Draw(grasssmallred4_ground, src, dest);
        break;
    case 41:
        TextureManager::Draw(grasssmallred5_ground, src, dest);
        break;
    case 42:
        TextureManager::Draw(grasssmallred6_ground, src, dest);
        break;
    case 43:
        TextureManager::Draw(grassbigorange1_ground, src, dest);
        break;
    case 44:
        TextureManager::Draw(grassbigorange2_ground, src, dest);
        break;
    case 45:
        TextureManager::Draw(grassbigorange3_ground, src, dest);
        break;
    case 46:
        TextureManager::Draw(grassbigorange4_ground, src, dest);
        break;
    case 47:
        TextureManager::Draw(grassbigorange5_ground, src, dest);
        break;
    case 48:
        TextureManager::Draw(grassbigorange6_ground, src, dest);
        break;
    case 49:
        TextureManager::Draw(grasssmallorange1_ground, src, dest);
        break;
    case 50:
        TextureManager::Draw(grasssmallorange2_ground, src, dest);
        break;
    case 51:
        TextureManager::Draw(grasssmallorange3_ground, src, dest);
        break;
    case 52:
        TextureManager::Draw(grasssmallorange4_ground, src, dest);
        break;
    case 53:
        TextureManager::Draw(grasssmallorange5_ground, src, dest);
        break;
    case 54:
        TextureManager::Draw(grasssmallorange6_ground, src, dest);
        break;
    case 55:
        TextureManager::Draw(grassbigyellow1_ground, src, dest);
        break;
    case 56:
        TextureManager::Draw(grassbigyellow2_ground, src, dest);
        break;
    case 57:
        TextureManager::Draw(grassbigyellow3_ground, src, dest);
        break;
    case 58:
        TextureManager::Draw(grassbigyellow4_ground, src, dest);
        break;
    case 59:
        TextureManager::Draw(grassbigyellow5_ground, src, dest);
        break;
    case 60:
        TextureManager::Draw(grassbigyellow6_ground, src, dest);
        break;
    case 61:
        TextureManager::Draw(grasssmallyellow1_ground, src, dest);
        break;
    case 62:
        TextureManager::Draw(grasssmallyellow2_ground, src, dest);
        break;
    case 63:
        TextureManager::Draw(grasssmallyellow3_ground, src, dest);
        break;
    case 64:
        TextureManager::Draw(grasssmallyellow4_ground, src, dest);
        break;
    case 65:
        TextureManager::Draw(grasssmallyellow5_ground, src, dest);
        break;
    case 66:
        TextureManager::Draw(grasssmallyellow6_ground, src, dest);
        break;
    case 67:
        TextureManager::Draw(mudbigrock1_ground, src, dest);
        break;
    case 68:
        TextureManager::Draw(mudbigrock2_ground, src, dest);
        break;
    case 69:
        TextureManager::Draw(mudbigrock3_ground, src, dest);
        break;
    case 70:
        TextureManager::Draw(mudbigrock4_ground, src, dest);
        break;
    case 71:
        TextureManager::Draw(mudbigrock5_ground, src, dest);
        break;
    case 72:
        TextureManager::Draw(mudbigrock6_ground, src, dest);
        break;
    case 73:
        TextureManager::Draw(mudsmallrock1_ground, src, dest);
        break;
    case 74:
        TextureManager::Draw(mudsmallrock2_ground, src, dest);
        break;
    case 75:
        TextureManager::Draw(mudsmallrock3_ground, src, dest);
        break;
    case 76:
        TextureManager::Draw(mudsmallrock4_ground, src, dest);
        break;
    case 77:
        TextureManager::Draw(mudsmallrock5_ground, src, dest);
        break;
    case 78:
        TextureManager::Draw(mudsmallrock6_ground, src, dest);
        break;
    case 79:
        TextureManager::Draw(emptyhole1_ground, src, dest);
        break;
    case 80:
        TextureManager::Draw(emptyhole2_ground, src, dest);
        break;
    case 81:
        TextureManager::Draw(emptyhole3_ground, src, dest);
        break;
    case 82:
        TextureManager::Draw(emptyhole4_ground, src, dest);
        break;
    case 83:
        TextureManager::Draw(emptyhole5_ground, src, dest);
        break;
    case 84:
        TextureManager::Draw(emptyhole6_ground, src, dest);
        break;
    case 85:
        TextureManager::Draw(emptyhole7_ground, src, dest);
        break;
    case 86:
        TextureManager::Draw(emptyhole8_ground, src, dest);
        break;
    case 87:
        TextureManager::Draw(blackhole1_ground, src, dest);
        break;
    case 88:
        TextureManager::Draw(blackhole2_ground, src, dest);
        break;
    case 89:
        TextureManager::Draw(blackhole3_ground, src, dest);
        break;
    case 90:
        TextureManager::Draw(blackhole4_ground, src, dest);
        break;
    case 91:
        TextureManager::Draw(blackhole5_ground, src, dest);
        break;
    case 92:
        TextureManager::Draw(blackhole6_ground, src, dest);
        break;
    case 93:
        TextureManager::Draw(blackhole7_ground, src, dest);
        break;
    case 94:
        TextureManager::Draw(blackhole8_ground, src, dest);
        break;
    case 95:
        TextureManager::Draw(waterhole1_ground, src, dest);
        break;
    case 96:
        TextureManager::Draw(waterhole2_ground, src, dest);
        break;
    case 97:
        TextureManager::Draw(waterhole3_ground, src, dest);
        break;
    case 98:
        TextureManager::Draw(waterhole4_ground, src, dest);
        break;
    case 99:
        TextureManager::Draw(waterhole5_ground, src, dest);
        break;
    case 100:
        TextureManager::Draw(waterhole6_ground, src, dest);
        break;
    case 101:
        TextureManager::Draw(waterhole7_ground, src, dest);
        break;
    case 102:
        TextureManager::Draw(waterhole8_ground, src, dest);
        break;
    case 103:
        TextureManager::Draw(forest1_ground, src, dest);
        break;
    case 104:
        TextureManager::Draw(forest2_ground, src, dest);
        break;
    case 105:
        TextureManager::Draw(forest3_ground, src, dest);
        break;
    case 106:
        TextureManager::Draw(forest4_ground, src, dest);
        break;
    case 107:
        TextureManager::Draw(forest5_ground, src, dest);
        break;
    case 108:
        TextureManager::Draw(forest6_ground, src, dest);
        break;
    case 109:
        TextureManager::Draw(forest7_ground, src, dest);
        break;
    case 110:
        TextureManager::Draw(forest8_ground, src, dest);
        break;
    case 111:
        TextureManager::Draw(forest9_ground, src, dest);
        break;
    case 112:
        TextureManager::Draw(forest10_ground, src, dest);
        break;
    case 113:
        TextureManager::Draw(forest11_ground, src, dest);
        break;
    case 114:
        TextureManager::Draw(forest12_ground, src, dest);
        break;
    case 115:
        TextureManager::Draw(forest13_ground, src, dest);
        break;
    case 116:
        TextureManager::Draw(forest14_ground, src, dest);
        break;
    case 117:
        TextureManager::Draw(forest15_ground, src, dest);
        break;
    case 118:
        TextureManager::Draw(forest16_ground, src, dest);
        break;
    case 119:
        TextureManager::Draw(forest17_ground, src, dest);
        break;
    case 120:
        TextureManager::Draw(forest18_ground, src, dest);
        break;
    default:
        break;
}



            }
        }

}


Map::~Map() {
    // Dealloca le texture per il terreno
    SDL_DestroyTexture(grass1_ground);
    SDL_DestroyTexture(grass2_ground);
    SDL_DestroyTexture(grass3_ground);
    SDL_DestroyTexture(grass4_ground);
    SDL_DestroyTexture(grass5_ground);
    SDL_DestroyTexture(grass6_ground);
    
    SDL_DestroyTexture(mud1_ground);
    SDL_DestroyTexture(mud2_ground);
    SDL_DestroyTexture(mud3_ground);
    SDL_DestroyTexture(mud4_ground);
    SDL_DestroyTexture(mud5_ground);
    SDL_DestroyTexture(mud6_ground);
    
    SDL_DestroyTexture(sand1_ground);
    SDL_DestroyTexture(sand2_ground);
    
    SDL_DestroyTexture(water1_ground);
    SDL_DestroyTexture(water2_ground);
    SDL_DestroyTexture(water3_ground);
    SDL_DestroyTexture(water4_ground);
    
    SDL_DestroyTexture(mugra1_ground);
    SDL_DestroyTexture(mugra2_ground);
    SDL_DestroyTexture(mugra3_ground);
    SDL_DestroyTexture(mugra4_ground);
    SDL_DestroyTexture(mugra5_ground);
    SDL_DestroyTexture(mugra6_ground);
    SDL_DestroyTexture(mugra7_ground);
    SDL_DestroyTexture(mugra8_ground);
    SDL_DestroyTexture(mugra9_ground);
    SDL_DestroyTexture(mugra10_ground);
    SDL_DestroyTexture(mugra11_ground);
    SDL_DestroyTexture(mugra12_ground);
    
    // Dealloca le texture per i fiori
    SDL_DestroyTexture(grassbigred1_ground);
    SDL_DestroyTexture(grassbigred2_ground);
    SDL_DestroyTexture(grassbigred3_ground);
    SDL_DestroyTexture(grassbigred4_ground);
    SDL_DestroyTexture(grassbigred5_ground);
    SDL_DestroyTexture(grassbigred6_ground);
    
    SDL_DestroyTexture(grasssmallred1_ground);
    SDL_DestroyTexture(grasssmallred2_ground);
    SDL_DestroyTexture(grasssmallred3_ground);
    SDL_DestroyTexture(grasssmallred4_ground);
    SDL_DestroyTexture(grasssmallred5_ground);
    SDL_DestroyTexture(grasssmallred6_ground);
    
    SDL_DestroyTexture(grassbigorange1_ground);
    SDL_DestroyTexture(grassbigorange2_ground);
    SDL_DestroyTexture(grassbigorange3_ground);
    SDL_DestroyTexture(grassbigorange4_ground);
    SDL_DestroyTexture(grassbigorange5_ground);
    SDL_DestroyTexture(grassbigorange6_ground);
    
    SDL_DestroyTexture(grasssmallorange1_ground);
    SDL_DestroyTexture(grasssmallorange2_ground);
    SDL_DestroyTexture(grasssmallorange3_ground);
    SDL_DestroyTexture(grasssmallorange4_ground);
    SDL_DestroyTexture(grasssmallorange5_ground);
    SDL_DestroyTexture(grasssmallorange6_ground);
    
    SDL_DestroyTexture(grassbigyellow1_ground);
    SDL_DestroyTexture(grassbigyellow2_ground);
    SDL_DestroyTexture(grassbigyellow3_ground);
    SDL_DestroyTexture(grassbigyellow4_ground);
    SDL_DestroyTexture(grassbigyellow5_ground);
    SDL_DestroyTexture(grassbigyellow6_ground);
    
    SDL_DestroyTexture(grasssmallyellow1_ground);
    SDL_DestroyTexture(grasssmallyellow2_ground);
    SDL_DestroyTexture(grasssmallyellow3_ground);
    SDL_DestroyTexture(grasssmallyellow4_ground);
    SDL_DestroyTexture(grasssmallyellow5_ground);
    SDL_DestroyTexture(grasssmallyellow6_ground);
    
    // Dealloca le texture per le rocce
    SDL_DestroyTexture(mudbigrock1_ground);
    SDL_DestroyTexture(mudbigrock2_ground);
    SDL_DestroyTexture(mudbigrock3_ground);
    SDL_DestroyTexture(mudbigrock4_ground);
    SDL_DestroyTexture(mudbigrock5_ground);
    SDL_DestroyTexture(mudbigrock6_ground);
    
    SDL_DestroyTexture(mudsmallrock1_ground);
    SDL_DestroyTexture(mudsmallrock2_ground);
    SDL_DestroyTexture(mudsmallrock3_ground);
    SDL_DestroyTexture(mudsmallrock4_ground);
    SDL_DestroyTexture(mudsmallrock5_ground);
    SDL_DestroyTexture(mudsmallrock6_ground);
    
    // Dealloca le texture per i buchi
    SDL_DestroyTexture(emptyhole1_ground);
    SDL_DestroyTexture(emptyhole2_ground);
    SDL_DestroyTexture(emptyhole3_ground);
    SDL_DestroyTexture(emptyhole4_ground);
    SDL_DestroyTexture(emptyhole5_ground);
    SDL_DestroyTexture(emptyhole6_ground);
    SDL_DestroyTexture(emptyhole7_ground);
    SDL_DestroyTexture(emptyhole8_ground);

    SDL_DestroyTexture(blackhole1_ground);
    SDL_DestroyTexture(blackhole2_ground);
    SDL_DestroyTexture(blackhole3_ground);
    SDL_DestroyTexture(blackhole4_ground);
    SDL_DestroyTexture(blackhole5_ground);
    SDL_DestroyTexture(blackhole6_ground);
    SDL_DestroyTexture(blackhole7_ground);
    SDL_DestroyTexture(blackhole8_ground);

    SDL_DestroyTexture(waterhole1_ground);
    SDL_DestroyTexture(waterhole2_ground);
    SDL_DestroyTexture(waterhole3_ground);
    SDL_DestroyTexture(waterhole4_ground);
    SDL_DestroyTexture(waterhole5_ground);
    SDL_DestroyTexture(waterhole6_ground);
    SDL_DestroyTexture(waterhole7_ground);
    SDL_DestroyTexture(waterhole8_ground);

    // Dealloca le texture per gli alberi
    SDL_DestroyTexture(forest1_ground);
    SDL_DestroyTexture(forest2_ground);
    SDL_DestroyTexture(forest3_ground);
    SDL_DestroyTexture(forest4_ground);
    SDL_DestroyTexture(forest5_ground);
    SDL_DestroyTexture(forest6_ground);
    SDL_DestroyTexture(forest7_ground);
    SDL_DestroyTexture(forest8_ground);
    SDL_DestroyTexture(forest9_ground);
    SDL_DestroyTexture(forest10_ground);
    SDL_DestroyTexture(forest11_ground);
    SDL_DestroyTexture(forest12_ground);
    SDL_DestroyTexture(forest13_ground);
    SDL_DestroyTexture(forest14_ground);
    SDL_DestroyTexture(forest15_ground);
    SDL_DestroyTexture(forest16_ground);
    SDL_DestroyTexture(forest17_ground);
    SDL_DestroyTexture(forest18_ground);

}

