#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 780


SDL_Window *pWindow=NULL;
SDL_Renderer *pRenderer=NULL;


int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){

        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }else{

        pWindow=SDL_CreateWindow("An SDL2 window",640,480,WINDOW_WIDTH,WINDOW_HEIGHT,
                                 SDL_WINDOW_SHOWN);

        if(pWindow){

            pRenderer=SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_PRESENTVSYNC);
        }



    }

    SDL_Delay(10000);

    SDL_Quit();



    return 0;
}
