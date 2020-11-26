#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *pn_Entier=(int*)malloc(sizeof(int));//int n_entier;

    int *pn_tabEntier=(int*)malloc(10*sizeof(int));

    int *pn_tabEntier2=(int*)calloc(10,sizeof(int));

    int *pn_more_numbers=NULL;

    *pn_Entier=10;

    int n_i;

    for(n_i=0;n_i<10;n_i++){

        pn_tabEntier[n_i]=0;
    }

    for(n_i=0;n_i<10;n_i++){

        printf("%d\n",pn_tabEntier[n_i]);
    }


    /*for(n_i=0;n_i<10;n_i++){

        pn_tabEntier2[n_i]=0;
    }

    for(n_i=0;n_i<10;n_i++){

        printf("%d",pn_tabEntier2[n_i]);
    }*/

    pn_more_numbers = (int*) realloc (pn_tabEntier2, 100 * sizeof(int));

    free(pn_tabEntier);
    //free(pn_tabEntier2);
    free(pn_more_numbers);
    free(pn_Entier);

    //Pointeur de pointeur

    int **ppn_MatEntier=NULL;

    // allocation de l'espace memoire au premier pointeur
    ppn_MatEntier=(int**)malloc(10*sizeof(int*));

     int i=0;
     int j=0;

    for(i=0;i<10;i++){
        // allocation de l'espace memoire au second pointeur
        ppn_MatEntier[i]=(int*)calloc(10,sizeof(int));

    }

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            ppn_MatEntier[i][j]=5;
            printf("%d", ppn_MatEntier[i][j]);
        }
        printf("\n");
    }

    //On libere le les allocations
    for(i=0;i<10;i++){
        free(ppn_MatEntier[i]);
    }

    free(ppn_MatEntier);







    return 0;
}
