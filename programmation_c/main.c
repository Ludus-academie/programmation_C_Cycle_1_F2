#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 255

int main()
{
    //char c_Chaine[TAILLE]="Hello";

   char c_Chaine[TAILLE]={'H','e','l','l','o',' ','w'};

   /*printf("Entrez votre chaine :\n");
   scanf("%s",c_Chaine);

   printf("Votre chaine : %s",c_Chaine);


   strcpy(c_Chaine,"nicolas");

   int n_lngChaine=strlen(c_Chaine);

   printf("long chaine : %d\n",n_lngChaine);

   int n_i=0;
   while(c_Chaine[n_i]!='\0'){

        n_i++;

   }

   printf("%d\n",n_i);*/



   /*printf("Entrez votre chaine :\n");
   gets(c_Chaine); //flus=>stdin

   printf("Votre chaine : %s",c_Chaine);*/


   printf("Entrez votre chaine :\n");
   fgets(c_Chaine,TAILLE,stdin);

   //printf("Votre chaine : %s",c_Chaine);
   //puts(c_Chaine);

   fputs(c_Chaine,stdout);

   int n_i;
   for(n_i=0;n_i<TAILLE;n_i++){
        printf("\nCar :\n");
        scanf("%c",&c_Chaine[n_i]);
        printf("%c\n",c_Chaine[n_i]);

   }






    return 0;
}
