//
// Created by catcherpearce on 10/26/26.
//

#ifndef FLAPPYBIRD_PLAYER_H
#define FLAPPYBIRD_PLAYER_H


class Player {
public:
    Player(int size);

    void jump();
    void applyGravity(float dt);

    float playerY;
    float velocity;
    int size;
};


#endif //FLAPPYBIRD_PLAYER_H
