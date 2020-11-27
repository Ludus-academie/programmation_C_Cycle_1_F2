#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 780


typedef struct renderer{

    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;

}renderer;

typedef struct rendererObject{

    SDL_Surface *pSurface;
    SDL_Texture *pTexture;

}rendererObject;

typedef enum gameState{

    play,
    stop,
    pause

}gameState;


void handleEvents(gameState *state);

int main(int argc, char *argv[])
{
    renderer tRender;
    rendererObject tRobject;
    gameState state=stop;

    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){

        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }else{

        tRender.pWindow=SDL_CreateWindow("An SDL2 window",640,480,WINDOW_WIDTH,WINDOW_HEIGHT,
                                 SDL_WINDOW_SHOWN);

        if(tRender.pWindow){

            tRender.pRenderer=SDL_CreateRenderer(tRender.pWindow,-1,SDL_RENDERER_PRESENTVSYNC);

        }



    }

    state=play;

    do{

         handleEvents(&state);

         if(tRender.pRenderer){

         //Set Color
        SDL_SetRenderDrawColor(tRender.pRenderer,205,92,92,SDL_ALPHA_OPAQUE);

          //Clear Render
        SDL_RenderClear(tRender.pRenderer);

        tRobject.pSurface=SDL_LoadBMP("./assets/rider.bmp");

        if(!tRobject.pSurface){
            SDL_Log("Unable to set surface: %s", SDL_GetError());
            return 1;
        }else{

            tRobject.pTexture=SDL_CreateTextureFromSurface(tRender.pRenderer,tRobject.pSurface);
            SDL_FreeSurface(tRobject.pSurface);

            if(!tRobject.pTexture){
                SDL_Log("Unable to set texture: %s", SDL_GetError());
                return 1;
            }else{

                SDL_Rect rectSource;
                SDL_Rect rectDest;

                rectSource.x=0;
                rectSource.y=0;
                rectSource.w=123;
                rectSource.h=87;

                rectDest.x=0;
                rectDest.y=0;
                rectDest.w=rectSource.w;
                rectDest.h=rectSource.h;

                SDL_RenderCopy(tRender.pRenderer,tRobject.pTexture,&rectSource,&rectDest);

            }


        }


        /*tRobject.pSurface=SDL_CreateRGBSurface (0, 100, 100, 32, 0, 0, 0, 0);

        if(!tRobject.pSurface){
            SDL_Log("Unable to set surface: %s", SDL_GetError());
            return 1;
        }else{
            SDL_Rect surface_rect = {0, 0, 100, 100};
            SDL_FillRect(tRobject.pSurface, &surface_rect, SDL_MapRGB(tRobject.pSurface->format, 255, 255, 0));

            tRobject.pTexture=SDL_CreateTextureFromSurface(tRender.pRenderer,tRobject.pSurface);
            SDL_FreeSurface(tRobject.pSurface);

            if(!tRobject.pTexture){
                SDL_Log("Unable to set texture: %s", SDL_GetError());
                return 1;
            }else{

                SDL_Rect rectSource;
                SDL_Rect rectDest;

                rectSource.x=0;
                rectSource.y=0;
                rectSource.w=200;
                rectSource.h=200;

                rectDest.x=15;
                rectDest.y=15;
                rectDest.w=rectSource.w;
                rectDest.h=rectSource.h;

                SDL_RenderCopy(tRender.pRenderer,tRobject.pTexture,&rectSource,&rectDest);

            }

        }*/




            //Update render
            SDL_RenderPresent(tRender.pRenderer);



        }

    }while(state==play);



    if(tRender.pRenderer){
        SDL_DestroyRenderer(tRender.pRenderer);
    }

    if(tRender.pWindow){
      SDL_DestroyWindow(tRender.pWindow);
    }


    SDL_Quit();



    return 0;
}



void handleEvents(gameState *state){

    SDL_Event event;

    if(SDL_PollEvent(&event)){

        switch (event.type){
            case SDL_QUIT : *state=stop;break;


        default:break;
        }
    }

}
