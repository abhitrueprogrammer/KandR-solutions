// Exercise 1-14. Write a program to print a histogram of the frequencies of dif-
// ferent characters in its input. □
#include <stdio.h>
#define ARRAYLEN 27
#define IN 1
#define OUT 0
main()
{ 
    int histogramArray[ARRAYLEN] = {0};
    int c;
    while (( c = getchar()) != EOF)
    {
        int state = IN;
        if (c == ' ' || c == '\n' || c== '\t')
        {
            state = OUT;
        }
        else
        {
            state = IN;
            printf("%i", (c-'A'));
            histogramArray['A'-c]++;
        }
    }
    printf("\n");
    for(int i = 0; i < ARRAYLEN; i++)
    {
        if (histogramArray[i] != 0)
        {
            putchar('A'+i);
            for(int j = 0; j < histogramArray[i]; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
}