#include <stdio.h>
#define ARRAYLEN 27
#define IN 1
#define OUT 0
main()
{ 
    int histogramArray[ARRAYLEN] = {0};
    int c;
    int wordlen = 0;
    while (( c = getchar()) != EOF)
    {
        int state = IN; 
        if (c == ' ' || c == '\n' || c== '\t')
        {
            if (state == IN) //check if it was just inside a word before
            {
                histogramArray[wordlen]++;
                wordlen = 0;
            }

            state = OUT;
        }
        else
        {
            state = IN;
            wordlen++;
        }
    }
    printf("\n");
    for(int i = 0; i < ARRAYLEN; i++)
    {
        if (histogramArray[i] != 0)
        {
            
            printf("%2i: ", i);
            for(int j = 0; j < histogramArray[i]; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
}