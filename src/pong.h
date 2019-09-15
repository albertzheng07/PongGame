#ifndef PONG_H
#define PONG_H

#include "paddle.h"

class Pong{
    public:
        Pong() {}
        Pong(int grid_width, int grid_height);      
        //~Pong();
        void update();
        void input(bool &running);
        Paddle left_paddle;
        Paddle right_paddle;
        
    private:
        int grid_w;
        int grid_h;   

};

#endif