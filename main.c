#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int main() {

    FILE *fp = fopen ( "readFile.txt", "r");
    FILE *fw = fopen ( "writeFile.txt", "w");
    int i = 0;
    char *input[5] = {"World","orange","apple","mobile","car"};
   // printf("input -> %d",sizeof(input));

int stringLen = sizeof(input) / sizeof(char *);
     for (i=0; i<stringLen; ++i)
        printf("%d: %s\n", i, input[i]);
        int firstWord = 0;
    int count = 0;
    char line[1024];
    char ch;
    int x = 0;
    int index = 0;
    while ( (ch = getc ( fp )) != EOF ) {
    if(ch != 32) {
        count = 0;
    }
        index++;
         /* if ( ch != '\n'){
            line[index++] = ch; // insére à la suite tant que pas \n
        }else {
            line[index] = '\0'; // remplace \n par un \0 fin de chaine
            index=0;
            printf("line = %s\nwords = %s\n", line,words);
           if(strcmp(line,words) == 0) {
                printf("trouver");
                x = 1;
                break;
            }
        }*/

    while ( ch >= 32 && ch <= 64  ) {
	    if(0 == count && 0!= firstWord ) {
            ch = '\n';
            count++;
	    }else{
            ch = getc ( fp );
        }
	}




    fputc(ch,fw);
    printf("%d => %c \n",ch,ch);
    firstWord++;
        //fputc(ch,fw);
    }

        //printf("%d",index);


    fclose ( fw );
    fclose ( fp );
    return 0;

/*
    qsort(input, stringLen, sizeof(char *), myCompare);

    for (i=0; i<stringLen; ++i)
        printf("%d: %s\n", i, input[i]);
*/
}
