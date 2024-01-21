// Exercise 5-12. Extend entab and detab to accept the shorthand
// entab -m +n
// to mean tab stops every n columns, starting at column m. Choose convenient
// (for the user) default behavior. □
#include <stdio.h>
#define N 4 // number of tabstops
int main(int argc, char *argv[])
{
    int c;
    if(argc > 4)
    {
        printf("usage: ./5-11 \"spacestop\"");
    } 
    int n, m; //tab stops every n columns, starting at column m
    n = 4, m =4; // default values
    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while(c = *++argv[0])
            switch (c)
            {
            case 'm':
                m = c;
                break;
            default:
                break;
            }
    }
    while (--argc > 0 && (*++argv)[0] == '+')
    {
        while(c = *++argv[0])
            switch (c)
            {
            case 'n':
                n = c;
                break;
            default:
                break;
            }
    }
    
    char spacestop = argc > 1 ? **argv : ' ';
    for(int i = 0; i < m; i++)
    {
        c = getchar();
        putchar(c);
    }
    int i = 0;
    while((c = getchar())!= EOF)
    {
        if(i%4 == 0)
        {
            putchar(spacestop);
            putchar(c);
        }
        else
        {
            putchar(c);
        }
        i++;
    }
    return 0;
}