//
// Created by catcherpearce on 10/26/26.
//

#ifndef FLAPPYBIRD_GAME_H
#define FLAPPYBIRD_GAME_H

#include <vector>
#include "Window.h"
#include "Pipe.h"

class Game {

public:
    Game();

    void start();
    void process();
    void restart();

private:
    Window gameWindow;
    Player player;
    std::vector<Pipe> pipeList;
    float pipeSpeed;
    int score;
    bool gameOver;

};


#endif //FLAPPYBIRD_GAME_H
