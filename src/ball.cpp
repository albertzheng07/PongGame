#include "ball.h"
#include <vector>
#include <ctime>
#include <cstdlib>

Ball::Ball(int grid_w, int grid_h)
{
    m_position.w = 30;
    m_position.h = 30;
    reset(grid_w, grid_h);
}

void Ball::update(Paddle &paddle1, Paddle &paddle2, int grid_w, int grid_h, bool & left_score, bool & right_score)
{
    std::vector <Paddle> allPaddle{paddle1, paddle2};
    for (Paddle &x : allPaddle)
    {
        const SDL_Rect *padPos  = x.getPosition();
        bool bounce = false;
        // check if ball intersects with paddle boundary
        int y_b1 = padPos->y;
        int y_b2 = padPos->y + padPos->h;
        bool upper_left_corner = (m_position.y >= y_b1 && m_position.y <= y_b2);
        bool lower_left_corner = ( ( (m_position.y + m_position.h) >= y_b1 ) && ( (m_position.y + m_position.h) <= y_b2 ) );                
        if (x.getType() == Type::LEFT)
        { 
            int x_bound = padPos->x + padPos->w;
            bounce = m_position.x <= x_bound && (upper_left_corner || lower_left_corner);
        }
        else if (x.getType() == Type::RIGHT)
        {
            int x_bound = padPos->x - padPos->w;
            bounce = m_position.x >= x_bound && (upper_left_corner || lower_left_corner);
        } 
        if (bounce) // define bounce criteria
        {
            v_x *= -1;
            break;
        }
    } 
    // check wall boundaries
    if (m_position.y <= 0 || (m_position.y+m_position.h) >= grid_h)
    {
        v_y *= -1;
    }

    // check wall boundaries
    m_position.x += v_x;
    m_position.y += v_y;   

    if (m_position.x+m_position.w < 0)
    {
        right_score = true;
    }
    else if (m_position.x > grid_w)
    {
        left_score = true;
    }
}

void Ball::reset(int grid_w, int grid_h)
{
    srand(clock());
    int vx_sign = 1;
    if (rand() % 2 == 1)
    {
        vx_sign *= -1;
    }
    srand(clock());
    int vy_sign = 1;
    if (rand() % 2 == 1)
    {
        vy_sign *= -1;
    }
    v_x = 1*vx_sign;
    v_y = 1*vy_sign;   
    // reset ball position 
    m_position.x = grid_w/2;
    m_position.y = grid_h/2; 
}