// Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises
// with pointers instead of array indexing. Good possibilities include getline
// Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4),
// reverse Chapter 3), and strindex and getop (Chapter 4).
#include <stdio.h>

int atoi(char *s);

int main()
{
    printf("%i\n",atoi("123"));
    
}
int atoi(char *s)
{
    int i, n;
    n = 0;
    for (i = 0; *s >= '0' && *s <= '9';*s++)
        n = 10 * n + (*s - '0');
    return n;
}