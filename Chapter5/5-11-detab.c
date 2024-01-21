// Exercise 5-11. Modify the programs entab and detab (written as exercises
// in Chapter 1) to accept a list of tab stops as arguments. Use the default tab
// settings if there are no arguments. □
// Exercise 1-20. Write a program detab that replaces tabs in the input with
// the proper number of blanks to space to the next tab stop. Assume a fixed
// set of tab stops, say every n columns. Should n be a variable or a symbolic
// parameter? □
#include <stdio.h>
#define N 4 // number of tabstops
int main(int argc, char *argv[])
{
    int c;
    if(argc > 2)
    {
        printf("usuage: ./5-11 \"spacestop\"");
    }
    char spacestop = argc > 1 ? *argv[1] : ' ';
    while((c = getchar())!= EOF)
    {
        if (c == '\t')
        {
            for(int i = 0; i < N; i++)
            {
                putchar(spacestop);
            }
        }
        else
        {
            putchar(c);
        }
    }
    return 0;
}