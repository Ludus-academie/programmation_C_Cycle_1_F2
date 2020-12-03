#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 780

#define TIME_BETWEEN_2_FRAME_PLAYER 4

//Ressources pour rendu
typedef struct renderer{

    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;

}renderer;

//Ressources pour les objets (assets) a afficher dans le rendu
typedef struct rendererObject{

    SDL_Surface *pSurface;
    SDL_Texture *pTexture;

}rendererObject;

//Enum pour la gestion de orientation d'affichage
typedef enum flip{

    fRight=1,
    fLeft

}flip;

//Vecteur pour set la position des objets
typedef struct vect2D{

    int n_x;
    int n_y;

}vect2D;

//Tranform objet a manipuler pour modifier la position
typedef struct transform{

    vect2D tpos;


}transform;


//Gestion des Etats
//Etats jeu
typedef enum gameState{

    play,
    stop,
    pause

}gameState;

//Etats controller
typedef enum controller{

        up=1,
        down,
        left,
        right,
        none

}controller;



//Etats player
typedef enum  playerState{
    idle=1,
    run


}playerState;



void handleEvents(gameState *state,controller *control);

int main(int argc, char *argv[])
{
    renderer tRender;
    rendererObject tSprite;
    gameState state=stop;
    controller control=none;
    playerState pState=idle;
    transform tPosition={{0,0}};
    transform tForward={{1,0}};
    flip tFlip=fRight;

    int n_frameNumber,n_frameTimer, n_frameMax;

    //Initialisation de la SDL2
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){

        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }else{
        //Set window
        tRender.pWindow=SDL_CreateWindow("An SDL2 window",640,480,WINDOW_WIDTH,WINDOW_HEIGHT,
                                 SDL_WINDOW_SHOWN);
        //Set rendu
        if(tRender.pWindow){

            tRender.pRenderer=SDL_CreateRenderer(tRender.pWindow,-1,SDL_RENDERER_PRESENTVSYNC);

        }

        //Set img flags
        int flags=IMG_INIT_JPG|IMG_INIT_PNG;
        int initted=IMG_Init(flags);
        if((initted&flags)!=flags){
             SDL_Log("IMG_Init:Failed to init required jpg and png support !\n");
             SDL_Log("IMG_Init: %s\n", IMG_GetError());

             return 1;

        }



    }
    //init var des ressources
    state=play;
    n_frameNumber=0;
    SDL_Rect rectSource={0,0,0,0};
    SDL_Rect rectDest={0,0,0,0};

    //Boucle de jeu
    do{
        //control event (get controller)
        handleEvents(&state,&control);

        //Update transform
        if(control==left){
            tForward.tpos.n_x=-1;
            pState=run;
            tFlip=fLeft;
        }else if (control==right){
            tForward.tpos.n_x=1;
            pState=run;
            tFlip=fRight;
        }else if(control==none){

            pState=idle;
        }

        //Set rendu
        if(tRender.pRenderer){

            //Set Color
            SDL_SetRenderDrawColor(tRender.pRenderer,205,92,92,SDL_ALPHA_OPAQUE);


            //Clear Render
            SDL_RenderClear(tRender.pRenderer);


            //chargement image png
            tSprite.pSurface=IMG_Load("./assets/animate-alpha.png");

            //Si pas de reference
            if(!tSprite.pSurface){
                SDL_Log("Unable to set surface: %s", SDL_GetError());
                return 1;
            }else{

                tSprite.pTexture=SDL_CreateTextureFromSurface(tRender.pRenderer,tSprite.pSurface);
                SDL_FreeSurface(tSprite.pSurface);

                //Si pas de reference
                if(!tSprite.pTexture){
                    SDL_Log("Unable to set texture: %s", SDL_GetError());
                    return 1;
                }else{

                    //Gestion du player
                    n_frameTimer=TIME_BETWEEN_2_FRAME_PLAYER;
                    n_frameMax=6;


                    if(pState==idle){

                         /*int n_cycle=(int)(SDL_GetTicks()/100%6);
                        printf("%d",n_cycle);  Affiche le cycle*/
                        //rectSource.x=128*(int)(SDL_GetTicks()/100%6);
                        rectSource.x=0;
                        rectSource.y=0;
                        rectSource.w=128;
                        rectSource.h=82;


                        rectDest.x=tPosition.tpos.n_x;
                        rectDest.y=tPosition.tpos.n_y;
                        rectDest.w=rectSource.w;
                        rectDest.h=rectSource.h;

                        SDL_RenderCopy(tRender.pRenderer,tSprite.pTexture,&rectSource,&rectDest);


                    }else if(pState==run){



                        //Découpage de l'image depuis le fichier en fonction de l'etat
                        rectSource.x=128*(int)(SDL_GetTicks()/100%n_frameMax);//1 image =>100ms
                        rectSource.y=0;
                        rectSource.w=128;
                        rectSource.h=82;

                        //Blit image dans rectDest, qui sera envoyé dans le viewoport
                        rectDest.x=rectDest.x+tForward.tpos.n_x;
                        rectDest.y=0;
                        rectDest.w=rectSource.w;
                        rectDest.h=rectSource.h;

                        //Set nouvelle position courante
                        tPosition.tpos.n_x=rectDest.x;
                        tPosition.tpos.n_y=rectDest.y;

                        if(tFlip==fRight)
                            SDL_RenderCopy(tRender.pRenderer,tSprite.pTexture,&rectSource,&rectDest);
                        else
                            SDL_RenderCopyEx(tRender.pRenderer,tSprite.pTexture,&rectSource,&rectDest,0,0,SDL_FLIP_HORIZONTAL);


                    }


                }


            }


            //Update render
            SDL_RenderPresent(tRender.pRenderer);

            n_frameNumber++;


        }

    }while(state==play);


    //Destruction de la texture
    if(tSprite.pTexture){
        SDL_DestroyTexture(tSprite.pTexture);
    }

    //Destruction des ressources du rendu
    if(tRender.pRenderer){
        SDL_DestroyRenderer(tRender.pRenderer);
    }

    if(tRender.pWindow){
      SDL_DestroyWindow(tRender.pWindow);
    }


    SDL_Quit();



    return 0;
}


//Set controller et gameState event
void handleEvents(gameState *state,controller *control){

    SDL_Event event;

    if(SDL_PollEvent(&event)){

        switch (event.type){
            case SDL_QUIT : *state=stop;break;
            case SDL_KEYDOWN:
                        switch(event.key.keysym.sym){
                                case SDLK_LEFT:*control=left;break;
                                case SDLK_RIGHT:*control=right;break;

                        }break;



        default:*control=none;break;
        }
    }

}
