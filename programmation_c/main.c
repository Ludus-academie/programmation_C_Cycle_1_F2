#include <stdio.h>
#include <stdlib.h>


//pointeur générique
void raz(void *adr, int n_size);

//prototypes
void affiche(int *n_val);
void affiche2(double *n_val);

//un pointeur de la fonction affiche
//void (*pAffiche)(int);
void (*pAffiche)(void*);





int main()
{

    //pointeur générique
   double dbl_val;
   int t[10];

    raz(t,10*sizeof(int));
    raz(&dbl_val,sizeof(double));

    //pointeurs génériques et fonctions
   int n_val=12;

   pAffiche=(void*)&affiche;

   pAffiche(&n_val);

   double dbl_reel=8.5;

   pAffiche=(void*)&affiche2;

   pAffiche(&dbl_reel);



   return 0;
}

void raz(void *adr, int n_size){

    int i;
    char *ad=adr;
    for(i=0;i<n_size;i++)
        *(ad+i)=0; //ou ad[i]

}

void affiche(int *n_val){

    char *adr=(char*)n_val;
    printf("%d\n",*n_val);

}

void affiche2(double *n_val){

    char *adr=(char*)n_val;
    printf("%lf\n",*n_val);

}


