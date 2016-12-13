#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30 // Taille la plus grande d'un mots 'Hexakosioihexekontahexaphobie'
#define LEN 60000 // nombre de mot moyens dans un dico

void Capitalize(char string[]);
// example : "Hello"
void Capitalize(char string[]){
    int i;
    int x = strlen(string);
     //Efface les caractéres spéciaux
     for (i=0;i<x;i++){
         if(string[i] >= 32 && string[i] <= 64  || string[i] >= 122) {
                string[i] = NULL;
         }
    }

    for (i=0;i<x;i++){
         if( i == 0 && string[i] > 96 && string[i] < 123 ) {
            string[i] -= 32;

         }else if(i > 0 && string[i] > 64 && string[i] < 96) {
            string[i] += 32;
         }
    }
}

int main(int argc, char *argv[])
{
    char name[LEN][SIZE]; /* Data records */
    char hold[LEN] ;
    int i,j ; /* indices of array */
    int last ; /* index of last item in array */

    FILE *fpPtr; /* fpPtr = sorted_file.txt pointer */
    FILE *fpPtrWrite; /* fpPtr = sorted_file.txt pointer */


    if ( ( fpPtrWrite = fopen("writeFile.txt", "w" ) ) == NULL ) {
        printf( "Fichier ne pas pas être ouvert" );
    }

    if ( ( fpPtr = fopen("readFile.txt", "r" ) ) == NULL ) {
        printf( "Fichier ne pas pas être ouvert" );

    }else {

        for(i = 0 ; !feof( fpPtr ) ; i++ ) {
            fscanf( fpPtr, "%s", name[i] );
            Capitalize(name[i]);
        }
        last = i - 1 ;
        fclose( fpPtr );

        //trie à bull
        for (i = last ; i > 0 ; i--) {
            for (j = 1 ; j <= i ; j++) {
                if(strcmp(name[j],name[j - 1]) == 0) {
                    strcpy(name[j-1],"");
                }else if (strcmp(name[j],name[j - 1]) < 0) {
                    strcpy(hold,name[j]) ;
                    strcpy(name[j],name[j - 1]) ;
                    strcpy(name[j - 1],hold) ;
                }
            }
        }

        for (i = 0 ; i <= last ; i++) {
            if( strcmp(name[i],"") != 0) {
                if(i == last ) {
                    fprintf(fpPtrWrite,"%s",name[i]);
                }else {
                    fprintf(fpPtrWrite,"%s\n",name[i]);
                }
            }
        }
    }
    return 0;
}
