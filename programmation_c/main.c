#include <stdio.h>
#include <stdlib.h>

//Les pointeurs sur fonctions

//prototypes
void affiche(int n_val);

//un pointeur de la fonction affiche
void (*pAffiche)(int);


//exemple fonction
int somme(int n_a, int n_b);

int (*pf)(int,int);

int fctEntier(int (*pnf)(int),int n_val);

int fctE(int n_a);

int main()
{
   //affiche(12);
   pAffiche=&affiche;

   pf=&somme;

   printf("somme:%d ", pf(2,3));

   int res=fctEntier(&fctE,2);

   return 0;
}


void affiche(int n_val){

    printf("%d\n",n_val);

}

int somme(int n_a, int n_b){

    return n_a + n_b;
}

int fctEntier(int (*pnf)(int),int n_val){

    return (*pnf)(n_val);

}


int fctE(int n_a){

    return n_a;
}
