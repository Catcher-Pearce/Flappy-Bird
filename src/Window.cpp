//
// Created by catcherpearce on 10/26/26.
//

#include "Window.h"
#include "raylib.h"
#include "Pipe.h"
#include <algorithm>
#include <cmath>
#include <vector>

Window::Window(Player& player) : player(player) {
}

void Window::initialize() {
    InitWindow(800, 450, "Flappy Bird");
    SetTargetFPS(60);
    Image pipeImage = LoadImage("../assets/pipe.png");
    ImageAlphaCrop(&pipeImage, 0.0f);
    pipeTexture = LoadTextureFromImage(pipeImage);
    UnloadImage(pipeImage);
    birdTexture = LoadTexture("../assets/bird.png");
    backgroundTexture = LoadTexture("../assets/background.png");
}

void Window::drawScreen(std::vector<Pipe>& pipeList, int score) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (backgroundTexture.width > 0 && backgroundTexture.height > 0) {
        const float height = float(GetScreenHeight());
        const float width = float(backgroundTexture.width) * height / backgroundTexture.height;
        backgroundX = std::fmod(backgroundX - 40.0f * GetFrameTime(), width);

        const Rectangle source = {
            0, 0, float(backgroundTexture.width), float(backgroundTexture.height)
        };
        // Repeat enough copies to cover the screen without distorting the image.
        for (float tileX = backgroundX; tileX < GetScreenWidth(); tileX += width) {
            DrawTexturePro(backgroundTexture, source,
                           {tileX, 0, width, height}, {0, 0}, 0, WHITE);
        }
    }
    const char* text = TextFormat("%i", score);
    int fontSize = 40;
    int x = (GetScreenWidth() - MeasureText(text, fontSize)) / 2;
    int y = 20;

    const float pipeWidth = 80.0f;
    const float pipeHeight = pipeWidth * float(pipeTexture.height) / float(pipeTexture.width);
    for (const Pipe& pipe : pipeList) {
        // Negative source height flips the top pipe vertically.
        DrawTexturePro(
            pipeTexture,
            {0, 0, float(pipeTexture.width), -float(pipeTexture.height)},
            {pipe.getX(), pipe.getTopY() - pipeHeight, pipeWidth, pipeHeight},
            {0, 0}, 0, WHITE
        );

        DrawTexturePro(
            pipeTexture,
            {0, 0, float(pipeTexture.width), float(pipeTexture.height)},
            {pipe.getX(), pipe.getBottomY(), pipeWidth, pipeHeight},
            {0, 0}, 0, WHITE
        );
    }


    DrawRectangle(350, player.playerY, player.size, player.size, RED);
    const float birdWidth = 86.0f;
    const float birdHeight = 64.0f;
    const float birdAngle = std::clamp(player.velocity * 0.05f, -10.0f, 25.0f);

    DrawTexturePro(
        birdTexture,
        {0, 0, float(birdTexture.width), float(birdTexture.height)},
        {
            350.0f + player.size / 2.0f,
            player.playerY + player.size / 2.0f,
            birdWidth,
            birdHeight
        },
        {birdWidth / 2.0f, birdHeight / 2.0f}, birdAngle, WHITE
    );

    DrawText(text, x, y, fontSize, BLACK);

}

void Window::drawGameOver() {
    int x = (GetScreenWidth() - MeasureText("GameOver", 40)) / 2;
    int y = 200;
    DrawText("Game Over", x, y, 40, RED);
}
