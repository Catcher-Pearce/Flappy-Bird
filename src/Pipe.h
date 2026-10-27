//
// Created by catcherpearce on 10/26/26.
//

#ifndef FLAPPYBIRD_PIPE_H
#define FLAPPYBIRD_PIPE_H


class Pipe {
public:
    Pipe(float x);
    void move(float speed);
    float getX() const { return pipeX; }
    float getTopY() const { return topPipeY; }
    float getBottomY() const { return bottomPipeY; }

    bool scored;

private:
    float pipeX;
    float topPipeY;
    float bottomPipeY;



};


#endif //FLAPPYBIRD_PIPE_H
