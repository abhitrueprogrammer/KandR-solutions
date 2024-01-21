#include <ctype.h>
#include <stdio.h>
#include "calc.h"
int getch(void);
static int unget = 0; // value pushed back to stdio
//getop: get the next operator or numeric operand
int getop(char s[])
{
    int i, c;
    if (unget) // if unget have a value inside it
    {
        if (unget == ' ' || unget == '\t')
        {
            while (((s[0] = c = getch()) == ' ') || c == '\t');
        }
        else
            c = unget;
            unget = 0;
    }
    else
    {
        c = getch();
    }

    s[1] = '\0';
    if(!isdigit(c) & c != '.')
        return c; /*not a number*/
    i = 0;
    if (isdigit(c)) 
        while (isdigit(s[++i] = c = getch())); /*collect integer part*/
    s[i] = '\0';
    if (c != EOF)
        unget = c;
    return NUMBER;
}
