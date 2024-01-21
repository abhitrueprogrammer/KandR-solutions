#include <stdio.h>
unsigned getbits(unsigned x, int p, int n)
{
    printf("%i\n" ,x >> (p+1));
    printf("%i\n" ,x >> (p+1-n));
    return (x >> (p+1-n)) & ~(~0 << n);
}
int main()
{
    getbits(0b1110111,5,2);
    return 0;
}