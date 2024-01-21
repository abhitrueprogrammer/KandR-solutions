#include <string.h>
#include <stdio.h>
#define MAXLEN 100 /*max length of any input line*/
int get_line(char *, int);
/*readline: read input lines. returns number of lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = get_line(*lineptr, MAXLEN)) > 0)
    {
        if(nlines >= maxlines)
            return -1;
        else {
            *lineptr[len - 1] = '\0'; /*delete newline*/
            *lineptr++;
        }
    }
    return nlines;
}
/*writelines: write output lines*/
void writelines(char *lineptr[], int nlines)
{
    int i;

    for(i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}