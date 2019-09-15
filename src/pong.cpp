#include "pong.h"
#include "SDL.h"
#include <iostream>

Pong::Pong(int grid_width, int grid_height)
        : grid_w(grid_width), 
          grid_h(grid_height),
         left_paddle(Type::LEFT, 0, grid_height/2-70),
         right_paddle(Type::RIGHT, grid_width-30, grid_height/2-70)        
{
}

void Pong::update()
{
}

void Pong::input(bool & running)
{
    left_paddle.handle_input(running);
    right_paddle.handle_input(running);
}