#include "paddle.h"


Paddle::Paddle()
{
    m_position.x = 0;
    m_position.y = 0;
    m_position.w = 30;
    m_position.h = 70;
}

Paddle::Paddle(Type type, int x, int y)
{
    m_position.x = x;
    m_position.y = y;
    m_position.w = 30;
    m_position.h = 70;
    m_direction = Direction::NONE;
    m_type = type;
}

void Paddle::handle_input(bool &running)
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT) {
            running = false;
        }
        else if (e.type == SDL_KEYDOWN)
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
            } else if(m_type == Type::RIGHT)
            {
                if(keys[SDL_SCANCODE_UP])
                {
                    m_direction = Direction::UP;
                }
                else if(keys[SDL_SCANCODE_DOWN])
                {
                    m_direction = Direction::DOWN;
                }
            }
        }
    }
}

void Paddle::update(double dt)
{
    if(m_direction == Direction::UP)
    {
        m_y = m_y - 5.0 * dt;
        m_position.y = m_y;
    }
    else if(m_direction == Direction::DOWN)
    {
        m_y = m_y + 5.0 * dt;
        m_position.y = m_y;
    }
}