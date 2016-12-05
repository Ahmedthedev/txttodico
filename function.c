#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int myCompare (const void * a, const void * b ) {
    const char *pa = *(const char**)a;
    const char *pb = *(const char**)b;

    return strcmp(pa,pb);
}

char** add(char *arr[],char * str) {

}

