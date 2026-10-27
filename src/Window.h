//
// Created by catcherpearce on 10/26/26.
//

#ifndef FLAPPYBIRD_WINDOW_H
#define FLAPPYBIRD_WINDOW_H
#include <vector>

#include "Player.h"
#include "Pipe.h"
#include "raylib.h"


class Window {
public:

    Window(Player& player);

    void initialize();
    void drawScreen(std::vector<Pipe>& pipelist, int score);
    void drawGameOver();


private:
    Player& player;
    Texture2D birdTexture;
    Texture2D pipeTexture;
    Texture2D backgroundTexture{};
    float backgroundX = 0.0f;
};


#endif //FLAPPYBIRD_WINDOW_H
