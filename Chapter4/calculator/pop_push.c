// don't copy, type it out or write it from memory
#include <stdio.h>
#include "calc.h"
#define MAXVAL 100  /*maximum depth of val stack*/
static int stack_pos = 0;         /*Next free stack position*/
static double val[MAXVAL]; /*value stack*/
/*push: push f onto value stack*/
void push(double f)
{
    if (stack_pos < MAXVAL)
        val[stack_pos++] = f;
    else
        printf("ERROR: stack full can't push %g\n", f);
}
// pop and return top value from stack
double pop(void)
{
    if (stack_pos > 0)
        return val[--stack_pos];
    else {
        printf("ERROR: stack empty\n");
        return 0.0;
    }
}