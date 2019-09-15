#ifndef PADDLE_H
#define PADDLE_H

#include "SDL.h"

enum class Type {LEFT, RIGHT};
enum class Direction {NONE, UP, DOWN};

class Paddle
{
    public:
        Paddle();
        Paddle(Type type, int x, int y);

        void handle_input(bool &running);
        void update(double dt);
        SDL_Rect getPosition() { return m_position; }

    private:
        double m_y;
        Type m_type;
        Direction m_direction;
        SDL_Rect m_position;        
};

#endif