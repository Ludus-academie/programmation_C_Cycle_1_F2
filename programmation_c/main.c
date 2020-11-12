#include <stdio.h>
#include <stdlib.h>
#define TAILLE 100


//const int TAILLE =100;


int main()
{

    //Exemple


    int n_a=0,n_b=0;
    char c_car='a';
    float flt_f=0.0;

    int n_t=TAILLE;

    printf("Bonjour\n");
    printf("Programme exemple\n");

    //Affichage formate
    printf("n_a : %d\n",n_a);
    printf("n_b : %d\n",n_b);
    printf("c_car : %c\n",c_car);
    printf("flt_f : %f\n",flt_f);

    putchar(c_car);//affichage non formate, MACRO


    /*printf("\nEntrez un entier : \n");
    scanf("%d",&n_a);
    printf("Entrez un entier : \n");
    scanf("%d",&n_b);*/

    printf("\nEntrez deux entiers : \n");
    scanf("%d%d",&n_a,&n_b);

    printf("n_a : %d\n",n_a);
    printf("n_b : %d\n",n_b);

    fflush(stdin);//vider le tampon stdin
    printf("Entrez un caratere : \n");
    scanf("%c",&c_car);

    printf("c_car : %c\n",c_car);

    fflush(stdin);//vider le tampon stdin
    printf("Entrez un caratere : \n");
    c_car=getchar(); // Saisie non formatee MACRO

    printf("c_car : %c\n",c_car);


















    return 0;
}
