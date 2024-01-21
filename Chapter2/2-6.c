// Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
// bits that begin at position p set to the rightmost n bits of y, leaving the other
// bits unchanged. □
#include <stdio.h>
// 11110 1111 -> input
// 11000 1111 xf
// 0000 0011 y0
// 0011 0000 yf
// // or
// 1101 1111 ->  output
int setbits(unsigned x, int p, int n, unsigned y);
int main()
{
    printf("%i\n", setbits(0b111101111,4,3,0b1010011));
    return 0;
}
int setbits(unsigned x, int p, int n, unsigned y)
{
    y = y  & ~(~0 << n);
    y = y << p;
     printf("%u\n", ~(~(~0 << n) << p));
    x = x & ~(~(~0 << n) << p);
    printf("%i\n", x);
    return x|y;
}