struct key
{
    char *word;
    int count;
} keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"if", 0},
    /*....*/
    {"int", 0},
    {"struct", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0}};
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

/*count C keywords; pointer version*/
int main(void)
{
    char word[MAXWORD];
    struct key *p;
    
    while(getword(word, MAXWORD)!= EOF)
    {
        if(isalpha(word[0]))
            if((p=binsearch(word, keytab, NKEYS)) != NULL)
                p -> count++;
    }
    for(p = keytab; p < keytab+NKEYS; p++)
        if(p-> count > 0)
            printf("%4d %s\n", p -> count, p -> word);
    return 0;
}

/*binsearch: find word in tab[0]... tab[n-1]*/
struct key *binsearch(char *word, struct key *tab, int n)
{
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while(low < high)
    {
        mid = low + (high - low)/2;
        if ((cond = strcmp(word, mid -> word)) < 0)
        {
            high = mid -1;
        }
        else if (cond > 0)
            low = mid + 1;
        else 
            return mid;
    }
    return NULL;
}







int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c = getch()));

    if(c != EOF)
        *w++ = c;
    if(!isalpha(c))
    {
        if(c == '/')
        {
            if((*w = getch()) == '/')
            {
                while((c = getch()) != '\n');
                return 0;
            }
            ungetch(*w);
        }
        
        else if (c == '"')
        {
            while((c = getch()) != '"');
            return 0;
        }
        else if (c == '\'')
        {
            while((c = getch()) != '\'');
            return 0;
        }
        else if (c == '#')
        {
            while((c = getch()) != ' ');
            return 0;
        }

        *w = '\0';
        return c;
    }
    for( ; --lim > 0; w++)
    {
        if(!isalnum(*w = getch()) && !(*w == '_'))
        {   
            if(*w == '/')
            {
                if((*w = getch()) == '/')
                {
                    while((c = getch()) == '\n');
                    return 0;
                }
                ungetch(*w);
                ungetch('/');
                break;
            }
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}
#define BUFSIZE 100 /*buffer size*/
char buf[BUFSIZE]; /*buffer for ungetch*/
int bufp = 0;  /*next free position in buffer*/
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /*push character back on input*/
{
    if (bufp >= BUFSIZE) //Cannot be ever greater than BUFSIZE tho
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}