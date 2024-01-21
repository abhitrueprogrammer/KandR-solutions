#include <stdio.h>
#define LIM 10

main()
{
    int s[LIM] = {0};
    int c;
    for (int i=0; i<LIM - 1 ; ++i)
    {
        c=getchar();
        if(c != '\n')
        {
            if (c != EOF)
            {
                s[i] = c;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }

    }
    for(int i = 0; i < LIM -1; ++i)
        printf("%c", s[i]);
}
    