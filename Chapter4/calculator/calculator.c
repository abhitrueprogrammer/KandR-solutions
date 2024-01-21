#include <stdio.h>
#include <stdlib.h>/* for atof() */
#include "calc.h"
#define MAXOP 100  /*Max size of operator*/

/*reverse Polish Calculator*/
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
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
        case '%':
            op2 = pop();
            if (op2 == 0)
            {
                printf("ZeroDivisionError: integer modulo by zero");
            }
            push((int)pop() % (int)op2);
            break;
        case '\n':
            printf("\t%.7f\n", pop());
            break;
        default:
            printf("ERROR unknown command %s\n", s);
            break;
        }
    }
    return 0;
}


