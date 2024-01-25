#include <stdio.h>
#include <math.h>
struct pt
{
    int x;
    int y;
};

int main(void)
{
    struct pt point = {3,5};
    double dist = sqrt((double)((point.x *point.x) + (point.y * point.y)));
    printf("%0.290f\n", dist);
    return 0;
}