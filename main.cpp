#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


bool HandleEvent(SDL_Event *Event)
{
  return false;
}

int main() {

  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *Window = SDL_CreateWindow("Metal Force",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        SCREEN_WIDTH,
                                        SCREEN_HEIGHT,
                                        SDL_WINDOW_SHOWN);

  if (Window)
  {
    // Create a "Renderer" for our window.
    SDL_Renderer *Renderer = SDL_CreateRenderer(Window,
                                                -1,
                                                SDL_RENDERER_PRESENTVSYNC);




    SDL_Surface* gScreenSurface = NULL;

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
      printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    }
    else
    {
      //Get window surface
      gScreenSurface = SDL_GetWindowSurface(Window);
    }

    SDL_Surface *Background = IMG_Load("resources/bob.png");
    if (Background == NULL)
    {
      std::cout << "Couldn't load Map" << std::endl;
    }

    SDL_Surface* optimizedSurface = NULL;
    optimizedSurface = SDL_ConvertSurface(Background, gScreenSurface->format, NULL);

    /*SDL_Texture *BackgroundImage = NULL;
    BackgroundImage = IMG_LoadTexture(Renderer, "resources/Mission 1.png");

    if (BackgroundImage == NULL)
    {
      std::cout << "Couldn't load Map texture " << IMG_GetError() << std::endl;
    }

    SDL_Rect BackgroundRect = {};
    BackgroundRect.x = 0;
    BackgroundRect.y = 0;
    BackgroundRect.w = 640;
    BackgroundRect.h = 480;

    SDL_Texture *BobImage = NULL;
    BobImage = IMG_LoadTexture(Renderer, "bob.png");

    if (BobImage == NULL)
    {
      std::cout << "Couldn't load Bob" << std::endl;
    }

    SDL_Rect BobRect = {};
    BobRect.x = 300;
    BobRect.y = 300;
    BobRect.w = 100;
    BobRect.h = 180;*/

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
        }/*
        SDL_RenderCopy(Renderer, BackgroundImage, NULL, &BackgroundRect);
        SDL_RenderCopy(Renderer, BobImage, NULL, &BobRect);*/

        SDL_BlitSurface( optimizedSurface, NULL, gScreenSurface, NULL );
        SDL_UpdateWindowSurface(Window);
      }
    }
  }

  return 0;
}
