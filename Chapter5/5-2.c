// Exercise 5-2. Write getfloat, the floating-point analog of getint. What type
// does getfloat return as its function value? □
#include <ctype.h>
#include <stdio.h>
int getch(void);
void ungetch(int);
int getfloat(float *pn);

int main()
{
    float *pn;
    if(getfloat(pn)) // why not &pn cz its where pn resides not the arrow pointing to pn
    {
        printf("%.3f\n",*pn); 
    }
}
/* getfloat: get next float from input into *pn */
int getfloat(float *pn)
{
    //solve it giving 0 if +a -a or a is given. Keep in mind it should print 0 when 0.a or .0a is given.
    int c, sign;
    int power = 1;
    while (isspace(c = getch()))
        /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);
        /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.')
    {
        for (c = getch(); isdigit(c); c = getch())
        {
            *pn = 10 * *pn + (c - '0');
            power = power * 10;
        }
    }

    *pn = sign**pn/power;
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
