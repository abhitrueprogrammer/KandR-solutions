// Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
// that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving
// the others unchanged. □
//11011000111
#include <stdio.h>
int invert( int x, int p,int n);
int main()
{
    printf("%u\n", invert( 0b11010110111, 4,3));
    return 0; 
}
int invert( int x, int p,int n)
{
    int mask = ~(~(~0 << n) <<p);
    int xZeroMiddle = x & mask;
    printf("%u\n",xZeroMiddle);
    int mask4Invert = ~(~(~0 << n) <<p);
    int xInvert = ~(x | mask4Invert);
    printf("%u\n",xInvert);
    return xZeroMiddle | xInvert;
}