#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int main() {

    FILE *fp = fopen ( "readFile.txt", "r");
    FILE *fw = fopen ( "writeFile.txt", "w");
    int i = 0;
    char table[100] = "lol";
    char *input[10] = {0};
   // printf("input -> %d",sizeof(input));
    int stringLen = sizeof(input) / sizeof(char *);

    int firstWord = 0;
    int count = 0;
    char line[30];
    char ch;
    int x = 0;
    int index = 0;
    while ( (ch = getc ( fp )) != EOF ) {
        if(ch != 32) {
            count = 0;
        }

        while ( ch >= 32 && ch <= 64  || ch >= 122) {
            if(0 == count && 0 != firstWord ) {
                ch = '\0';
                count++;
            }else{
                ch = getc ( fp );
            }
        }
        printf("line[%d] = %c \n",index,ch);
        line[index] = ch;
        index++;
        if(ch == '\0') {
           printf(" line = %s\n",line);
           input[i] = line;
           printf(" input[%d] ==  %s\n",i,input[i]);
           i++;
           index = 0;
        }


       // fputc(ch,fw);
        //printf("%d => %c \n",ch,ch);
        firstWord++;
            //fputc(ch,fw);

    }

         for (i=0; i<stringLen; ++i)
        printf("%d: %s\n", i, input[i]);




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
