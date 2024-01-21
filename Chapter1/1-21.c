#include <stdio.h>
int N = 8; // No of space for every tab

int main()
{
    int num = 1; //counting every character till 10th
    int spaces = 0;
    for(int c = 0; (c = getchar()) != EOF; c++)
    {
        if (c == ' ')
        {
            spaces++;
            if (spaces > N)
            {
                putchar('\t');
                spaces = 0;
            }
        }
        else
        {
            for(int i = 0; i < spaces; i++)
            {
                putchar(' ');
                spaces = 0;
            }
            putchar(c);
        }
    }
}