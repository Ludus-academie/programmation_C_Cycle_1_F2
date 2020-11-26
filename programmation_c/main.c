#include <stdio.h>
#include <stdlib.h>
#include<string.h>



//Exemple un point dans un plan
//les types
typedef struct tPoint{

    int x;
    int y;
    char str_coul[10];

}tPoint;

//Les enumerations
//typedef enum couleur{red=1,black,green}; mettre enum devant var
typedef enum couleur{red=1,black,green}couleur;

typedef enum booleen{faux,vrai}booleen;


//Prototypes
void setPoint(tPoint *pPoint,int n_x,int n_y,char str_coul[10]);



int main()
{
    //les types def

    tPoint monPoint={0,0,{"red"}};

    tPoint *pMonPoint=NULL;

    tPoint tab_point[100];


    pMonPoint=&monPoint;

    monPoint.x=10;
    monPoint.y=5;

    //Pointeur
    pMonPoint->x=12;
    pMonPoint->y=20;

    //formalise pointeur
    (*pMonPoint).x=20;
    (*pMonPoint).y=12;

   /* int i=0;

    for(i=0;i<100; i++){
        tab_point[i].x=0;
        tab_point[i].y=0;
    }*/

    monPoint.x=10;
    monPoint.y=5;

    strcpy(monPoint.str_coul,"black");

    setPoint(&monPoint,8,8,"green");

    //Les enum
    couleur cl1;

    cl1=1;

    booleen bln_val=faux;


    return 0;
}


void setPoint(tPoint *pPoint,int n_x,int n_y,char str_coul[10])
{
    pPoint->x=n_x;
    pPoint->y=n_y;
    strcpy(pPoint->str_coul,str_coul);

}
