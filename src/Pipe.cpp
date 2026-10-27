//
// Created by catcherpearce on 10/26/26.
//

#include "Pipe.h"

#include <random>

Pipe::Pipe(float x) {
    pipeX = x;
    scored = false;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> topDistrib(50, 250);
    topPipeY = topDistrib(gen);
    bottomPipeY = topPipeY + 150;
}

void Pipe::move(float speed) {
    pipeX -= speed;
}
