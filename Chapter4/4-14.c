// Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments
// of type t. (Block structure will help.) □
#include <stdio.h>
#define swap(t,x,y) {\
    t temp = y;\
    y = x;\
    x = temp;\
}
int main(void)
{
    int x = 4;
    int y = 3;
    swap(int, x,y);
    printf("%i,%i\n",x,y);
}