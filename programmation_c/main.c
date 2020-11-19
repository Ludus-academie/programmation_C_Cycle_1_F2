#include <stdio.h>
#include <stdlib.h>

//prototype
void int_somme(int n_nb1, int n_nb2, int *n_Res);
void init_tabEntier(int n_tabEntier[],int n_taille);
char * get_tabCar(char c_tabCar[],int n_taille);

int main()
{
    //Pointeur
    int n_Entier=0;
//pointeur sur @ n_entier   //@ de n_entier
            int * pn_Entier=&n_Entier;

    *pn_Entier=10;

    int n_Entier2=5;

    pn_Entier =&n_Entier2;

    *pn_Entier=8;

    //passage par adresse
    int n_nb1=10,n_nb2=5, n_Res=0;

    int_somme(n_nb1,n_nb2,&n_Res);


    //tableaux et pointeurs

    //Exemple avec char
    char c_tab[10];


    char *pc_char=c_tab;

    int n_i;

    for(n_i=0;n_i<10;n_i++){
            pc_char[n_i]='a';
    }

     //incrementation du pointeur de caractere, j'incremente son espace d'adressage
    pc_char++;


    //tableaux et pointeurs

    //Exemple avec int
    int n_tab[10];


    int *pn_int=n_tab;

    for(n_i=0;n_i<10;n_i++){
            pn_int[n_i]=5;
    }

    //incrementation du pointeur d'entier, j'incremente son espace d'adressage
      pn_int++; //ecriture 1
    *(pn_int)++; //ecriture 2

    //incrementation de la val et non du pinteur
    (*pn_int)++; //*pn_int++


    for(n_i=0;n_i<10;n_i++){
            //n_tab[n_i]=8; formalisme tableau
            *(n_tab+n_i)=8; //formalisme pointeur
    }

    int n_tab2D[10][10];

    int n_j;

    for(n_i=0;n_i<10;n_i++){
             for(n_j=0;n_j<10;n_j++){
                //n_tab2D[n_i][n_j]
                 *(*(n_tab2D+n_i)+n_j)=0;//formalisme pointeur matrice
             }
    }

    //Attention
    //Bug
    /*int *pn_Entier3;

    *pn_Entier3=6;*/

    //fix
    int *pn_Entier3=NULL;//0x0 init

    pn_Entier3=&n_Entier;


    init_tabEntier(n_tab,10);

    int n_tabEntier2[100];
    init_tabEntier(n_tabEntier2,100);

    char *pc_car=get_tabCar(c_tab,10);



    return 0;
}


void int_somme(int n_nb1, int n_nb2, int *n_Res){

    *n_Res=n_nb1+n_nb2;

}


void init_tabEntier(int n_tabEntier[],int n_taille){

    int n_i;
    for(n_i=0;n_i<n_taille;n_i++){
            n_tabEntier[n_i]=0;
    }

}


//Pour retourner un tableau, vous utilisez un pointeur
char * get_tabCar(char c_tabCar[],int n_taille){

    int n_i;

    for(n_i=0;n_i<n_taille;n_i++){
        c_tabCar[n_i]='z';
    }

    return c_tabCar;
}



