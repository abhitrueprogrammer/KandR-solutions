#include <ctype.h>
#include <stdio.h>
#include "calc.h"
int getch(void);
void ungetch(int);
//getop: get the next operator or numeric operand
int getop(char s[])
{
    int i, c;
    
    while (((s[0] = c = getch()) == ' ') || c == '\t');
    s[1] = '\0';
    if(!isdigit(c) & c != '.')
        return c; /*not a number*/
    i = 0;
    if (isdigit(c)) 
        while (isdigit(s[++i] = c = getch())); /*collect integer part*/
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
