#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "renderer.h"
#include "pong.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Renderer &renderer,
           std::size_t target_frame_duration);
  void Update(bool &left_score, bool &right_score); 
 private:
    Pong pong;
    int score1{0};
    int score2{0};
    Uint32 resetTime;
};

#endif