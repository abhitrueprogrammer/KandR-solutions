#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int n);

int main(int argc, char *argv[])
{
    int nlines;
    int n = 10;
    if(argc > 1 && **++argv == '-')
    {
        n = atoi( ++*argv);
    }
    if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        writelines(lineptr, nlines, n);
    }
    
    return 0;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    size_t cur_len = 0;
    nlines = 0;
    char *line;
    char *p;
    while((len = getline(&line, &cur_len, stdin)) > 1)
    {
        if(nlines >= maxlines || (p = malloc(len)) == NULL)
        {
            return -1;
        }
        else{
            strcpy(p,line);
            p[len -1] = '\0';
            lineptr[nlines++] = p;
        }
    }


    return nlines;
}
void writelines(char *lineptr[], int nlines, int n)
{

    for(int i =  nlines > n ? nlines - n:0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
}