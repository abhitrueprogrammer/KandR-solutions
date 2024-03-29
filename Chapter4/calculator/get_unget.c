#include <stdio.h>
#define BUFSIZE 100
static buf[BUFSIZE]; // buffer for ungetch
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
