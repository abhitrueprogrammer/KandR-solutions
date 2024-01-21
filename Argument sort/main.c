#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void q_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *, char *);

int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;
    if (argc > 1 && *(*++argv) == '-')
        {
            switch (*++(*argv)) //next character show
            {
            case 'r':
                reverse = 1;
                break;
            case 'n':
                numeric = 0;
                break;
            }
        }
    if ((nlines = readlines(lineptr, MAXLINES)) > 0)
    {
        q_sort((void **)lineptr, 0, nlines - 1,
               (numeric ? (int (*)(void *, void *))numcmp : (int (*)(void *, void *))strcmp));
        writelines(lineptr, nlines, reverse);
        return 0;
    }
    else
    {
        printf("Input too big to sort");
        return 1;
    }
}

#include <stdlib.h>

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return 1;
    else if (v1 > v2)
        return -1;
    else
        return 0;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    size_t cur_len = 0;
    nlines = 0;
    char *line;
    char *p;
    while ((len = getline(&line, &cur_len, stdin)) > 1)
    {
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            strcpy(p, line);
            p[len - 1] = '\0';
            lineptr[nlines++] = p;
        }
    
    }
    return nlines;
}
/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int reverse)
{
    int i;
    // implement this better
    if(reverse)
    {
    for (i = nlines-1; i >= 0; i--)
        printf("%s\n", lineptr[i]);
        
    }
    else
    {
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
    }

}