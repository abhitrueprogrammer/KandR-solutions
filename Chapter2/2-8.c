// Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
// integer x rotated to the right by n bit positions. □
#include <stdio.h>
#include <math.h>
int rightrot(int x, int n);
int main(void)
{
    printf("%u\n", rightrot(0b1101100110111, 4));
    return 0;
}
int rightrot(int x, int n)
{
    int l = floor(log2(x))+1;
    int xRightPush = x >> n;
    int mask = ~(~0 << n); //001111
    int rot = x & mask;  //0000111
    rot = rot << l+1 - n; //garbar imminent
    // int mask4RightPush = ~(mask << l+1 -n);
    // printf("%u, %u\n", mask,mask4RightPush);
    // xRightPush = mask4RightPush & xRightPush;
    printf("%u, %u\n", rot,xRightPush);
    return xRightPush | rot;

}