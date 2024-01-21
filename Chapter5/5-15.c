#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
// Exercise 5-15. Add the option -f to fold upper and lower case together, so that
// case distinctions are not made during sorting; for example, a and A compare
// equal. □
#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void q_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *, char *);
int main(int argc, char *argv[])
{

    int nlines;
    int fold = 0;
    int numeric = 0;
    int reverse = 0;
    if (argc-- > 1)
        {
            while(argc-- > 0 && *(*++argv) == '-')
            {
                switch (*++(*argv)) //next character show
                {
                    case 'r':
                        reverse = 1;
                        break;
                    case 'n':
                        numeric = 1;
                        break;
                    case 'f':
                        fold =1;
                        break;
                }
            }
        }
    if ((nlines = readlines(lineptr, MAXLINES)) > 0)
    {
        // printf("%i", fold);
        q_sort((void **)lineptr, 0, nlines - 1,
               (numeric ? (int (*)(void *, void *))numcmp : fold? (int (*)(void *, void *))strcasecmp : (int (*)(void *, void *))strcmp) );
               //There are 3 ways to lower
               //1. cast string to str, then use lower
               //2. write ur own strcmp function and use lower in it
               //3. use strcasecmp
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

void q_sort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, pivot;
    void swap(void *v[], int i, int j);

    if( left >= right)
    {
        return;
    }

    swap(v, left, (left+right)/2);
    pivot = left;

    for(i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++pivot, i);
    swap(v, left, pivot);
    q_sort(v, left, pivot-1, comp);
    q_sort(v, pivot+1, right, comp);
}

void swap(void *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}