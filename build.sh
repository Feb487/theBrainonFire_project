#!/bin/bash
g++ -v -o theBrainOnFire main.cpp src/*.cpp -Iheader -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
./theBrainOnFire
