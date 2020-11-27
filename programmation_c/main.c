#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


/* string containing a file access mode. It can be:
"r"	read: Open file for input operations. The file must exist.
"w"	write: Create an empty file for output operations. If a file with the same name already exists, its contents are discarded and the file is treated as a new empty file.
"a"	append: Open file for output at the end of a file. Output operations always write data at the end of the file, expanding it.
            Repositioning operations (fseek, fsetpos, rewind) are ignored. The file is created if it does not exist.
"r+" read/update: Open a file for update (both for input and output). The file must exist.
"w+" write/update: Create an empty file and open it for update (both for input and output).
                    If a file with the same name already exists its contents are discarded and the file is treated as a new empty file.
"a+" append/update: Open a file for update (both for input and output) with all output operations writing data at the end of the file.
                    Repositioning operations (fseek, fsetpos, rewind) affects the next input operations, but output operations move the position back to the end of file. The file is created if it does not exist.

*/


int main()
{

    FILE *fSortie=NULL;
    FILE *fEntree=NULL;

    int n_val=0;
    int n_Occurence=0;
    int n_NombreVal=0;
    char str_nomFichier[21];


    printf("Donnez le nom du fichier a creer :\n");
    scanf("%20s",str_nomFichier);
    fflush(stdin);

    //Les fichiers txt
    //Ecriture dans un fichier de type txt

   /* //Ouverture du fichier en ecriture
    if((fSortie=fopen(str_nomFichier,"w"))==NULL){
         //Test ouverture
        fprintf(stderr,"Erreur ouverture et creation du fichier :%s\n",strerror(errno));

    }else{

            do{

                printf("Donnez un entier diff de 0 :\n");
                scanf("%d",&n_val);

                if(n_val!=0){
                    //Ecriture dans le fichier
                    fprintf(fSortie,"%d\n",n_val);
                    n_Occurence++;
                }


            }while(n_val!=0);


    }

    fclose(fSortie); //fermeture du descripteur de fichier*/

    /*//Lecture dans un fichier de type txt
    printf("Donnez le nom du fichier a lire : \n");
    scanf("%20s",str_nomFichier);
    fflush(stdin);

     //Ouverture du fichier en lecture
    if((fEntree=fopen(str_nomFichier,"r"))==NULL){
        //Test ouverture
         fprintf(stderr,"Erreur ouverture du fichier :%s\n",strerror(errno));
    }else{


            while(n_NombreVal<n_Occurence){

                 //Lecture dans le fichier
                fscanf(fEntree,"%d",&n_val);
                printf("%d\n",n_val);
                n_NombreVal++;

            }



    }

    fclose(fEntree);//fermeture du descripteur de fichier*/


    //Les fichiers binaires

    //Ouverture du fichier en ecriture de type binaire
    if((fSortie=fopen(str_nomFichier,"wb"))==NULL){
         //Test ouverture
        fprintf(stderr,"Erreur ouverture et creation du fichier :%s\n",strerror(errno));

    }else{

            do{

                printf("Donnez un entier diff de 0 :\n");
                scanf("%d",&n_val);

                if(n_val!=0){
                    //Ecriture dans le fichier
                    fwrite(&n_val,sizeof(int),1,fSortie);
                    //Cette fonction permet d'écrire un certain nombre d'octets vers le flux
                    //spécifié en quatrième paramètre.
                    //Les octets à écrire seront stockés dans le buffer passé en premier paramètre. Pour spécifier le nombre d'octets à écrire,
                    //il faut jouer sur deux paramètres : le nombre de bloc d'octets à lire
                    //ainsi que la taille de chacun des blocs.
                    n_Occurence++;
                }


            }while(n_val!=0);


    }

    fclose(fSortie); //fermeture du descripteur de fichier



    //Lecture dans un fichier de type binaire

    printf("Donnez le nom du fichier a lire : \n");
    scanf("%20s",str_nomFichier);
    fflush(stdin);

     //Ouverture du fichier en lecture
    if((fEntree=fopen(str_nomFichier,"rb"))==NULL){
        //Test ouverture
         fprintf(stderr,"Erreur ouverture du fichier :%s\n",strerror(errno));
    }else{


            while(n_NombreVal<n_Occurence){

                 //Lecture dans le fichier
                fread(&n_val,sizeof(int),1,fEntree);
                //Cette fonction permet de lire un certain nombre d'octets à partir
                //d'un flux. L'ensemble des octets lu seront stockés dans un buffer
                //passé en premier paramètre : il faut donc être certain que le buffer
                // est bien de taille suffisante, par rapport à la taille des données
                // demandées. Pour spécifier le nombre d'octets à lire,
                //il faut jouer sur deux paramètres : le nombre de bloc d'octets
                //à lire ainsi que la taille de chacun des blocs.
                //La taille totale du buffer à allouer sera donc le produit de
                //ces deux tailles précédentes.
                printf("%d\n",n_val);
                n_NombreVal++;

            }



    }

    fclose(fEntree);//fermeture du descripteur de fichier


    return 0;
}
