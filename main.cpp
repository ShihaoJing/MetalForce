#include <iostream>
#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


bool HandleEvent(SDL_Event *Event)
{
  return false;
}

int main() {

  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *Window = SDL_CreateWindow("Handmade Hero",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SCREEN_WIDTH,
                                        SCREEN_HEIGHT,
                                        SDL_WINDOW_RESIZABLE);

  if (Window)
  {
    // Create a "Renderer" for our window.
    SDL_Renderer *Renderer = SDL_CreateRenderer(Window,
                                                -1,
                                                SDL_RENDERER_PRESENTVSYNC);

    

    if (Renderer)
    {
      bool Running = true;
      while (Running)
      {
        SDL_Event Event;
        while(SDL_PollEvent(&Event))
        {
          if (HandleEvent(&Event))
          {
            Running = false;
          }
        }
      }
    }
  }

  return 0;
}