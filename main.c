#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30 // Taille la plus grande d'un mots 'Hexakosioihexekontahexaphobie'
#define LEN 30000 // nombre de mot moyens dans un dico

void Cap(char string[]);

void Cap(char string[]){
    int i;
    int x = strlen(string);

    //while(string[i] >= 32 && string[i] <= 64  || string[i] >= 122) {
     for (i=0;i<x;i++){
         if(string[i] >= 32 && string[i] <= 64  || string[i] >= 122) {
                string[i] = NULL;
         }
         //   printf("%d %c => Alert\n",string[i],string[i]);
    }

     // You want to get the length of the whole string.
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

/*
copy file contents to array
*/

/* fopen opens file; exits program if file cannot be opened */
if ( ( fpPtrWrite = fopen("writeFile.txt", "w" ) ) == NULL ) {
printf( "Fichier ne pas pas être ouvert" );
}

/* fopen opens file; exits program if file cannot be opened */
if ( ( fpPtr = fopen("readFile.txt", "r" ) ) == NULL ) {
printf( "Fichier ne pas pas être ouvert" );
} /* End if */

/* Read records from file */
else {
/* While not end of file */
//printf("dans le fichiers il y a\n");
for(i = 0 ; !feof( fpPtr ) ; i++ ) {
fscanf( fpPtr, "%s", name[i] );
Cap(name[i]);
} /* End while */
last = i - 1 ;

fclose( fpPtr ); /* fclose closes the file */


/*
sort
*/
for (i = last ; i > 0 ; i--)
for (j = 1 ; j <= i ; j++)
if (strcmp(name[j],name[j - 1]) < 0) {
    strcpy(hold,name[j]) ;
    strcpy(name[j],name[j - 1]) ;
    strcpy(name[j - 1],hold) ;
} else if(strcmp(name[j],name[j - 1]) == 0) {
    strcpy(name[j-1],"");
}
/*
write array to output
*/
//printf("\n ordre alphabetique \n ");
for (i = 0 ; i <= last ; i++) {
if( strcmp(name[i],"") != 0) {
    if(i == last ) {
        fprintf(fpPtrWrite,"%s ",name[i]);
    }else {
    fprintf(fpPtrWrite,"%s \n",name[i]);
    }
}
}
} /* End else */

return 0; /* Indicates that the program terminated successfully */
} /* End Main */
