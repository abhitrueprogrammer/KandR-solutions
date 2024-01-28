#include <stdio.h>
#include <ctype.h>

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while(isspace(c = getch()))
    {
        if(c == '\n')
        {
            return c;
        }
    }
    // printf(" %i ", c);

    if(c != EOF)
        *w++ = c;
    if(!isalpha(c))
    {
        
        if(c == '/')
        {
            if((*w = getch()) == '/')
            {
                while((c = getch()) != '\n');
                return '\n';
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
            // printf("||II->%i||", *w);

            if(*w == '\n')
            {
                *w = '\0';
                return '\n';
            }
            else if(*w == '/')
            {
                if((*w = getch()) == '/')
                {
                    while((c = getch()) == '\n');
                    return c;
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