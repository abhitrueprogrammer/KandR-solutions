#include <stdio.h>
int bitcount(int x);
int main()
{
    printf("%i\n",bitcount(7));
    return 0;
}
int bitcount(int x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        {
            x &= x-1;
            b++;
        }

    return b;
}