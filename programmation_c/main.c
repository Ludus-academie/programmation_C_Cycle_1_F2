#include <stdio.h>
#include <stdlib.h>

//Exemple un point dans un plan

typedef struct tPoint{

    int x;
    int y;

}tPoint;


int main()
{

    tPoint monPoint={0,0};

    tPoint *pMonPoint=NULL;

    pMonPoint=&monPoint;

    monPoint.x=10;
    monPoint.y=5;

    //Pointeur
    pMonPoint->x=12;
    pMonPoint->y=20;

    //formalise pointeur
    (*pMonPoint).x=20;
    (*pMonPoint).y=12;





    return 0;
}
