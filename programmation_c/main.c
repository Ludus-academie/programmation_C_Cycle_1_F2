#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


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
    move


}playerState;



void handleEvents(gameState *state,controller *control);

int main(int argc, char *argv[])
{
    renderer tRender;
    rendererObject tSprite;
    rendererObject tFont;
    gameState state=stop;
    controller control=none;
    playerState pState=idle;
    transform tPosition={{0,0}};
    transform tForward={{1,0}};
    flip tFlip=fRight;
    TTF_Font *font=NULL;

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


        //Set ttf
        if(TTF_Init()==-1) {
            SDL_Log("TTf init: %s\n", TTF_GetError());
            return 1;
        }


        font=TTF_OpenFont("./assets/fonts/texgyreheroscn-regular.otf",72);
        if(!font){
            SDL_Log("TTF_OpenFont: %s\n", TTF_GetError());
            //handle error
        }





    }
    //init var des ressources
    state=play;
    n_frameNumber=1;
    SDL_Rect rectSource={0,0,0,0};
    SDL_Rect rectDest={0,0,0,0};
    SDL_Rect rectSourcef={0,0,0,0};
    SDL_Rect rectDestf={0,0,0,0};
    unsigned int lastTime = 0, currentTime=0;
    unsigned int FrameTime=0;
    int n_i=0;

    //Boucle de jeu
    do{
        currentTime = SDL_GetTicks();
        printf("Frame time 1 : %d\n",currentTime);
        //control event (get controller)
        handleEvents(&state,&control);

        //Update transform
        if(control==left){
            tForward.tpos.n_x=-1;
            pState=move;
            tFlip=fLeft;
        }else if (control==right){
            tForward.tpos.n_x=1;
            pState=move;
            tFlip=fRight;
        }
        else if(control==none){

            pState=idle;
        }

        //Set rendu
        if(tRender.pRenderer){



            //Set Color
            SDL_SetRenderDrawColor(tRender.pRenderer,205,92,92,SDL_ALPHA_OPAQUE);

            //Clear Render
            SDL_RenderClear(tRender.pRenderer);


            //Gestion du sprites
            //chargement image png
            tSprite.pSurface=IMG_Load("./assets/helicopter.png");

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
                    n_frameMax=5;


                    if(pState==idle){

                         /*int n_cycle=(int)(SDL_GetTicks()/100%6);
                        printf("%d",n_cycle);  Affiche le cycle*/
                        //rectSource.x=128*(int)(SDL_GetTicks()/100%6);
                        int i;

                        rectSource.x=128*(int)(SDL_GetTicks()/100%n_frameMax);
                        rectSource.y=0;
                        rectSource.w=128;
                        rectSource.h=55;


                        rectDest.x=tPosition.tpos.n_x;
                        rectDest.y=tPosition.tpos.n_y;
                        rectDest.w=rectSource.w;
                        rectDest.h=rectSource.h;

                        SDL_RenderCopyEx(tRender.pRenderer,tSprite.pTexture,&rectSource,&rectDest,0,0,SDL_FLIP_HORIZONTAL);


                    }else if(pState==move){



                        //Découpage de l'image depuis le fichier en fonction de l'etat
                        rectSource.x=128*(int)(SDL_GetTicks()/100%n_frameMax);//1 image =>100ms
                        rectSource.y=0;
                        rectSource.w=128;
                        rectSource.h=55;

                        //Blit image dans rectDest, qui sera envoyé dans le viewoport
                        rectDest.x=rectDest.x+tForward.tpos.n_x;
                        rectDest.y=0;
                        rectDest.w=rectSource.w;
                        rectDest.h=rectSource.h;

                        //Set nouvelle position courante
                        tPosition.tpos.n_x=rectDest.x;
                        tPosition.tpos.n_y=rectDest.y;

                        if(tFlip==fRight)
                            SDL_RenderCopyEx(tRender.pRenderer,tSprite.pTexture,&rectSource,&rectDest,0,0,SDL_FLIP_HORIZONTAL);
                        else
                            SDL_RenderCopy(tRender.pRenderer,tSprite.pTexture,&rectSource,&rectDest);


                    }


                }


            }


             //Gestion de la font
            SDL_Color color ={0,0,0};

            //Set ressource a afficher
            //Set Frame rateils
             char buffer [50];
             int n;



            // Print a report once per second
            /*if (currentTime > lastTime + 16) {
                //printf("Report: %d\n",currentTime );
                n=sprintf (buffer, "Report : %d",n_i);
                lastTime = currentTime;
                n_i++;
            }*/




            if(!(tFont.pSurface=TTF_RenderText_Solid(font,buffer,color))){

                SDL_Log("TTF render error: %s\n", TTF_GetError());

            }else{
                //int w,h;
               // TTF_SizeText(font,"Hello World",&w,&h);

                tFont.pTexture=SDL_CreateTextureFromSurface(tRender.pRenderer,tFont.pSurface);
                SDL_FreeSurface(tFont.pSurface);

                //Si pas de reference
                if(!tFont.pTexture){
                    SDL_Log("Unable to set texture: %s", SDL_GetError());
                    return 1;
                }else{
                        rectSourcef.x=0;
                        rectSourcef.y=0;
                        rectSourcef.w=600;
                        rectSourcef.h=100;


                        rectDestf.x=424;
                        rectDestf.y=0;
                        rectDestf.w=50;
                        rectDestf.h=30;

                        SDL_RenderCopy(tRender.pRenderer,tFont.pTexture,&rectSourcef,&rectDestf);

                }


            }




            //Update render
            SDL_RenderPresent(tRender.pRenderer);



            currentTime = SDL_GetTicks();
            FrameTime=(currentTime/n_frameNumber);
            n=sprintf (buffer, "%d",FrameTime);
            printf("currentTime : %d\n",currentTime);
            printf("nb frame : %d\n",n_frameNumber);
            printf("Frame time 2 : %d\n",FrameTime);



            //SDL_Delay(5000);
            n_frameNumber++;


        }

    }while(state==play);

    TTF_CloseFont(font);
    font=NULL;

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

    TTF_Quit();

    IMG_Quit();

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
                                case SDLK_UP:*control=up;break;
                                case SDLK_DOWN:*control=down;break;

                        }break;



        default:*control=none;break;
        }
    }

}
