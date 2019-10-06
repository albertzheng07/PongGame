#ifndef PONG_H
#define PONG_H

#include "paddle.h"
#include "ball.h"

struct Point
{
    int x;
    int y;
};

class Pong{
    public:
        Pong() {}
        Pong(int grid_width, int grid_height);      
        //~Pong();
        void update(bool &left_score, bool &right_score);
        void input(bool &running);
        void reset();
        Paddle left_paddle;
        Paddle right_paddle;
        Ball   ball;
        
    private:
        int grid_w;
        int grid_h;  
        Point l_paddle_start;
        Point r_paddle_start;

};

#endif