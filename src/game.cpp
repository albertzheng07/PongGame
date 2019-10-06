#include "game.h"
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
  : pong(grid_width, grid_height) {
}

void Game::Run(Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    bool left_score = false;
    bool right_score = false;    
    // if reset is set, wait 1 sec before running again
    if ( (frame_start-resetTime) > 1000)
    {
      pong.input(running);
      Update(left_score, right_score);
    }  
    renderer.Render(pong);

    // trigger reset for all objects (pause for a sec) if ball is past either paddle,
    // tell pong to update score
    if (left_score)
    {
        score1 += 1;
    }
    else if (right_score)
    {
        score2 += 1;
    }
    if (left_score || right_score)
    {
        pong.reset();
        resetTime = SDL_GetTicks();
    }
    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score1, score2, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::Update(bool & left_score, bool & right_score) {
  pong.update(left_score, right_score);
}