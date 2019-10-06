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

        void handle_input(SDL_Event &e);
        void update(double grid_h);
        void reset(int x, int y);
        const SDL_Rect* getPosition() { return &m_position; }
        Direction getDirection() { return m_direction; }
        Type      getType() { return m_type; }
        double      getMy() { return m_y; }

    private:
        double m_y;
        Type m_type;
        Direction m_direction;
        SDL_Rect m_position;        
};

#endif