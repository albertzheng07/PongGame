#ifndef BALL_H
#define BALL_H
#include "SDL.h"
#include "paddle.h"


class Ball{
    public:
        Ball() {}
        Ball(int grid_w, int grid_h);
        void update(Paddle &paddle1, Paddle &paddle2, int grid_w, int grid_h, bool &left_score, bool &right_score);
        void reset(int grid_w, int grid_h);
        const SDL_Rect* getPosition() { return &m_position; }

    private:  
        int v_x;
        int v_y;
        SDL_Rect m_position;          

};

#endif