#include "paddle.h"
#include <iostream>

Paddle::Paddle()
{
    m_position.x = 0;
    m_position.y = 0;
    m_position.w = 30;
    m_position.h = 70;
    m_y = 0;    
}

Paddle::Paddle(Type type, int x, int y)
{
    m_position.w = 30;
    m_position.h = 70;
    m_direction = Direction::NONE;
    m_type = type;
    reset(x, y);
}

void Paddle::handle_input(SDL_Event &e)
{
        if (e.type == SDL_KEYDOWN)
        {
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);
            if(m_type == Type::LEFT)
            {
                if(keys[SDL_SCANCODE_W])
                {
                    m_direction = Direction::UP;
                }
                else if(keys[SDL_SCANCODE_S])
                {
                    m_direction = Direction::DOWN;
                }
            } 
            else if(m_type == Type::RIGHT)
            {
                if(keys[SDL_SCANCODE_I])
                {
                    m_direction = Direction::UP;
                }
                else if(keys[SDL_SCANCODE_K])
                {
                    m_direction = Direction::DOWN;
                }
            }
        }
        else
        {            
            m_direction = Direction::NONE;
        }
}

void Paddle::update(double grid_h)
{
    if(m_direction == Direction::UP)
    {
        m_y = m_y - 10;
        if (m_y < 0)
        {
            m_y = 0;
        }     
        m_position.y = m_y;
    }
    else if(m_direction == Direction::DOWN)
    {
        m_y = m_y + 10;
        if (m_y > grid_h - m_position.h)
        {
            m_y = grid_h - m_position.h;
        }          
        m_position.y = m_y;
    }
}

void Paddle::reset(int x, int y)
{
    m_position.x = x;
    m_position.y = y;
    m_direction = Direction::NONE;
    m_y = static_cast<double>(y);
}