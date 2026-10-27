//
// Created by catcherpearce on 10/26/26.
//

#include "Player.h"

Player::Player(int size) : size(size), playerY(225), velocity(1) {};

void Player::applyGravity(float dt) {
    velocity += 800.0f * dt;
    playerY += (dt * velocity);
}

void Player::jump() {
    velocity = -300.0f;
}
