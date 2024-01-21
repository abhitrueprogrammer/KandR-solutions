// Write a program detab that replaces tabs in the input with
// the proper number of blanks to space to the next tab stop. Assume a fixed
// set of tab stops, say every n columns. Should n be a variable or a symbolic
// parameter?
#include <stdio.h>
int N = 10; // No of space for every tab

int main(void)
{
    int num = 1; //counting every character till 10th
    for(int c = 0; (c = getchar()) != EOF; c++)
    {
        if (c == '\t')
        {
            printf("%i", N);
            for(int i = 0; i < N; i++)
            {one
                putchar(' ');
            }
        }
        else
        {
            putchar(c);
            num++;
        }
    }
    return 0;
}