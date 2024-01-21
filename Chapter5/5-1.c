#include <ctype.h>
#include <stdio.h>
int getch(void);
void ungetch(int);
int getint(int *pn);

int main()
{
    int *pn;
    if(getint(pn))
    {
        printf("%i\n",*pn);
    }
}
/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c))
    {
        ungetch(c);
        ungetch(sign < 0 ? '-': '+');
        return 0;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100
static int buf[BUFSIZE]; // buffer for ungetch
static int bufp = 0; // next free position in buf
int getch(void) // get a character(possibily pushed back one)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) // push chracter back into input
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
