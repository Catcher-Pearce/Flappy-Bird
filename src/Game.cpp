//
// Created by catcherpearce on 10/26/26.
//

#include "Game.h"
#include "raylib.h"

Game::Game() : player(Player(30)), gameWindow(player), pipeSpeed(3), score(0), gameOver(false) {
        for (int i = 0; i < 4; ++i) {
            pipeList.emplace_back(800.0f + i * 250.0f);
        }
}

void Game::start() {
    gameWindow.initialize();

    while (!WindowShouldClose()) {
        gameWindow.drawScreen(pipeList, score);
        if (gameOver) {
            if (IsKeyPressed(KEY_R)) {
                restart();
            }
            gameWindow.drawGameOver();
            player.applyGravity(GetFrameTime());
        } else {
            process();
        }
        EndDrawing();

    }
}

void Game::process() {
    player.applyGravity(GetFrameTime());

    if (IsKeyPressed(KEY_SPACE)) {
        player.jump();
    }

    for (Pipe& pipe : pipeList) {
        pipe.move(pipeSpeed);

        Rectangle topBox = {
            pipe.getX(), 0.0f, 80.0f, pipe.getTopY()
        };

        Rectangle bottomBox = {
            pipe.getX(), pipe.getBottomY(),
            80.0f, 450.0f - pipe.getBottomY()
        };

        Rectangle playerBox = {
            350.0f, player.playerY,
            float(player.size), float(player.size)
        };

        if (CheckCollisionRecs(playerBox, topBox) ||
            CheckCollisionRecs(playerBox, bottomBox) ||
                player.playerY > 600 ||
                player.playerY < -80) {
            gameOver = true;
            }

        if (!pipe.scored && pipe.getX() + 80.0f < playerBox.x) {
            pipe.scored = true;
            ++score;
            pipeSpeed *= 1.02f;
        }
    }

    Pipe frontPipe = pipeList.front();

    if (!pipeList.empty() && frontPipe.getX() < -80.0f) {
        float nextX = pipeList.back().getX() + 250.0f;
        pipeList.erase(pipeList.begin());
        pipeList.emplace_back(nextX);
    }
}

void Game::restart() {
    player = Player(30);
    score = 0;
    pipeSpeed = 3;
    gameOver = false;

    pipeList.clear();
    for (int i = 0; i < 4; ++i) {
        pipeList.emplace_back(800.0f + i * 250.0f);
    }
}
