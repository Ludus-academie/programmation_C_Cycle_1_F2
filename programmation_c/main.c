#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* com para */
    //com ligne

    //unsigned : non signé ex :unsigned short sn_entier
    //Entier
    short sn_entier;
    int n_entier;
    long l_entier;

    printf("Taille en octet du short : %d\n",sizeof(sn_entier));
    printf("Taille en octet de entier : %d\n",sizeof(n_entier));
    printf("Taille en octet du long : %d\n",sizeof(l_entier));

    //reel
    //unsigned : non signé ex :unsigned float flt_reel
    float flt_reel;
    double dbl_reel;
    long double ldbl_reel;

    printf("Taille en octet du float : %d\n",sizeof(flt_reel));
    printf("Taille en octet de double : %d\n",sizeof(dbl_reel));
    printf("Taille en octet du long double : %d\n",sizeof(ldbl_reel));

    //caractère
    char c_car;
    printf("Taille en octet du caractere : %d\n",sizeof(c_car));


    int n_a=255;
    int n_b=0;

    //ECRIRE
    printf("val de n_a : %d et n_b : %d \n",n_a,n_b);
    printf("val de n_a : %x et n_b : %x \n",n_a,n_b);

    //LIRE
    printf("Saisir un entier dans n_a \n");
    scanf("%d",&n_a);
    printf("Saisir un entier dans n_b \n");
    scanf("%d",&n_b);

    printf("val de n_a : %d et n_b : %d \n",n_a,n_b);




    return 0;

}
