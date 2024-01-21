#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /*maxlines to be sorted*/

char *lineptr[MAXLINES]; /*pointers to text lines*/

int readlines(char *lineptr[],int nlines);
int writelines(char *lineptr[], int nlines);

void quickSort(char *lineptr[], int left, int right);

/*sort input lines*/
int main()
{
    int nlines; /*number of input lines read*/
    if((nlines = readlines(lineptr, MAXLINES))>= 0)
    {
        quickSort(lineptr, 0, nlines -1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("ERROR: input too big to sort\n");
        return 1;
    }
}