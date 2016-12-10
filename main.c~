#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30
#define LEN 31
#define SIZE 30
#define LEN 31

int main()
{
char name[LEN][SIZE]; /* Data records */
char hold[LEN] ;
int i,j ; /* indices of array */
int last ; /* index of last item in array */

FILE *fpPtr; /* fpPtr = sorted_file.txt pointer */

/*
copy file contents to array
*/

/* fopen opens file; exits program if file cannot be opened */
if ( ( fpPtr = fopen("readFile.txt", "r" ) ) == NULL ) {
printf( "File could not be opened" );
} /* End if */

/* Read records from file */
else {
/* While not end of file */
printf("The names in original order are");
for(i = 0 ; !feof( fpPtr ) ; i++ ) {
fscanf( fpPtr, "%s", name[i] );
printf("%s", name[i]);
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
}
/*
write array to output
*/
printf("The names in alphabetical order are");
for (i = 0 ; i <= last ; i++)
printf("- %s",name[i]);

} /* End else */

return 0; /* Indicates that the program terminated successfully */
} /* End Main */
