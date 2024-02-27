#include <stdio.h>
#include <ctype.h>
//would simplify code a LOT(maybe not here but in the main func) if instead of returning 0(if invalid) it just skipped to next word.
/*Puts word in the string given from stdin and return a non-zero number if valid word. -1(EOF) is returned if EOF*/
/*This new version returns the word and if its not a word puts it up in a file*/
int getword(char *word, int lim, FILE * fp)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    c = getch();
    while(isspace(c))
    {
        fputc(c, fp);
        c = getch();
    }

    if(c != EOF)
        *w++ = c;
    if(!isalnum(c))
    {
        if(c == '/')
        {
            if((*w = getch()) == '/')
            {
            fputc('/', fp);

                while(c != '\n')
                {
                    fputc(c, fp);
                    c = getch();
                }
                fputc(c, fp); //put final \n
                return 0;
            }
            ungetch(*w);
        }
        
        else if (c == '"')
        {
            fputc('"', fp);
            c = getch();
            while(c != '"')
            {
                fputc(c, fp);
                c = getch();
            }  
            fputc(c, fp); //put final "          
            return 0;
        }
        else if (c == '\'')
        {
            fputc('\'', fp);

            while(c != '\'')
            {
                fputc(c, fp);
                c = getch();
            }             
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