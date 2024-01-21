// Exercise 5-10. Write the program expr, which evaluates a reverse Polish ex-
// pression from the command line, where each operator or operand is a separate
// argument. For example,
// expr 2 3 4 + *
// evaluates 2 × (3+4). □
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void push(double f);
double pop(void);
int main(int argc, char *argv[])
{
    int op2;
    while (*++argv)
    {
        if(isdigit(**argv))
            push(atof(*argv));
        else
        {
        switch (**argv)
        {
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 == 0.0)
            {
                printf("division by 0 error");
                break;
            }
            push(pop() - op2);
            break;
        default:
            printf("ERROR unknown command %s\n", *argv);
            break;
        }

        }
    
    }
    printf("\t%.7f\n", pop());

    return 0;
}

// don't copy, type it out or write it from memory
#define MAXVAL 100  /*maximum depth of val stack*/
int stack_pos = 0;         /*Next free stack position*/
double val[MAXVAL]; /*value stack*/
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
