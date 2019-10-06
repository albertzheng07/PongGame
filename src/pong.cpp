#include "pong.h"
#include "SDL.h"
#include <iostream>

Pong::Pong(int grid_width, int grid_height)
        : grid_w(grid_width), 
          grid_h(grid_height),  
          l_paddle_start{0, grid_height/2-70},
          r_paddle_start{grid_width-30, grid_height/2-70},
          left_paddle(Type::LEFT, 0, grid_height/2-70),
          right_paddle(Type::RIGHT, grid_width-30, grid_height/2-70),
          ball(grid_width, grid_height)
{
}

void Pong::update(bool &left_score, bool &right_score)
{
  left_paddle.update(grid_h);
  right_paddle.update(grid_h);
  ball.update(left_paddle, right_paddle, grid_w, grid_h, left_score, right_score);
}

void Pong::input(bool & running)
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {  
       if (e.type == SDL_QUIT) {
            running = false;
        }    
        else
        {  
        left_paddle.handle_input(e);
        right_paddle.handle_input(e);
        break;
        }
    }
}

void Pong::reset()
{
    left_paddle.reset(l_paddle_start.x, l_paddle_start.y);
    right_paddle.reset(r_paddle_start.x, r_paddle_start.y);
    ball.reset(grid_w, grid_h);
}