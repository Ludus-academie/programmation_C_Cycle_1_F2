#include <stdio.h>
#include <stdlib.h>
#define NBI 10

int main()
{
    int n_a=0,n_b=0;

    //Condition if
    if(n_a==n_b){
        //Instructions
        printf("n_a et n_b identiques\n");
    }
    else if(n_a>n_b){
        //Instructions
        printf("n_a > n_b\n");
    }
    else{

        //instruction
         printf("diff...\n");
    }


    if(n_a==n_b){

        printf("n_a et n_b identiques\n");
    }
    if(n_a>n_b){

        printf("n_a > n_b\n");
    }


    int n_val=12;

    if(n_val>=10 && n_val<=20){

        //Instructions...
        printf("%d",n_val);
    }

    //condition switch

    char n_choix='0';

    printf("Menu\n");
    printf("1:Menu 1\n");
    printf("2:Menu 2\n");
    printf("choix ? \n");
    scanf("%c",&n_choix);

    switch(n_choix){
        case '1' :printf("Menu 1\n");break;
        case '2' : printf("Menu 2 \n");break;
        default:printf("defaut\n");
    }


    //Boucle Pour
    int n_i;
    for(n_i=0;n_i<NBI;n_i++){
        printf("%d\n",n_i);
    }


    //faire TQ
    n_i=0;
    do{

        printf("%d\n",n_i);

        n_i++;

    }while(n_i<NBI);


    //TQ faire
    n_i=0;
    while(n_i<NBI){

        printf("%d\n",n_i);
        n_i++;

    }






    return 0;
}
