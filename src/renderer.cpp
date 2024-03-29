#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("PONG Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Pong & pong) {
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);


  /* Draw Paddle Left */
  const SDL_Rect *rect1  = pong.left_paddle.getPosition();
  SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(sdl_renderer, rect1);
  SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);

  /* Draw Paddle Right */
  const SDL_Rect *rect2  = pong.right_paddle.getPosition();  
  SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(sdl_renderer, rect2);
  SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);

  /* Draw Ball */
  const SDL_Rect *rect3  = pong.ball.getPosition();
  SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(sdl_renderer, rect3);
  SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255); 

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score1,  int score2, int fps) {
  std::string title{"Score P1: " + std::to_string(score1) + " P2: " + std::to_string(score2) +  " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}