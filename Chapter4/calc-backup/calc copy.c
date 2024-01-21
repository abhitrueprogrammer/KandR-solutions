#include <stdio.h>
#include <stdlib.h>/* for atof() */
#include <math.h>
#include <string.h>
#include <ctype.h>
#define MAXOP 100  /*Max size of operator*/
#define NUMBER '0' /*Signal that a number has been found*/
#define FUNC '1'   /*signal that function has been found*/

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
// Exercise 4-6. Add commands for handling variables. (It’s easy to provide
// twenty-six variables with single-letter names.) Add a variable for the most
// recently printed value. □
// Exercise 4-5. Add access to library functions like sin, exp, and pow. See
// <math.h> in Appendix B, Section 4. □

/*reverse Polish Calculator*/
int main()
{
    int type;
    int cur_var;
    double op2;
    char s[MAXOP];
    double ans;
    double vars[26] = {0};
    // for(int i = 'A'-'A'; i < 'Z'-'A'; i++)
    // {
    //     vars[i] = 0;
    // }
    // set all as 0, without equal sign store in stack without confirming otherwise if = found then pop A and set its val and then push.
    while ((type = getop(s)) != EOF)
    {

        switch (type)
        {
        case FUNC:
            if (!strcmp("sin", s))
            {
                printf("Inside sin");
                push(sin(pop()));
            }
            else if (!strcmp("cos", s))
                push(cos(pop()));
            else if (!strcmp("exp", s))
                push(exp(pop()));
            else if (!strcmp("pow", s))
            {
                op2 = pop();
                push(pow(pop(), op2));
            }
            else if(!strcmp("ans", s))
            {
                push(ans);
            }
            else
                printf("ERROR unknown func %s\n", s);
            break;
        case NUMBER:
            push(atof(s));
            break;
        case 'A' ... 'Z':
            //its pushing current value of variable and not variable name
            cur_var = type-'A';
            push(vars[cur_var]);
            break;
        case '=':
            int c = 0;
            pop();
            vars[cur_var] = pop();
            printf("\tVARIABLE ASSIGNED\n");
            while (((c = getch()) == ' ') || c == '\t')
            ;
            if(c != '\n')
            {
                ungetch(c);
            }
            //make it so assignment doesn't fuck up anyone
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
        case '\n':
            //if assigned no value was set and \n should have no meaning
            ans = pop();
            printf("\t%.7f\n", ans );
            break;
        default:
            printf("ERROR unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
// don't copy, type it out or write it from memory
#define MAXVAL 100  /*maximum depth of val stack*/
int stack_pos = 0;  /*Next free stack position*/
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
    else
    {
        printf("ERROR: stack empty\n");
        return 0.0;
    }
}
#include <ctype.h>

//prevoius declarations of getch
// getop: get the next operator or numeric operand
int getop(char s[])
{
    int i, c;
    while (((s[0] = c = getch()) == ' ') || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) & c != '.')
    {
        // if(getch() == ' ')
        //     {
        //         return c;
        //     }
        if( c == '='||c == '+' || c == '-' || c == '*' || c == '%' || c == '\n')
            return c;
        else if (isupper(c))
            return c;
        else
        {
            ungetch(c);
            for (i = 0; (c = getch()) != '\n' && c != '\t' && c != ' ' && !isdigit(c); i++)
            {
                s[i] = c;
            }
            if (c != EOF)
                ungetch(c);
            printf("GETTING UR MOFO FUNC %s", s);
            return FUNC;
        }

    }
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ; /*collect integer part*/
    s[i] = '\0';
    
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
#define BUFSIZE 100
char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0;      // next free position in buf
int getch(void)    // get a character(possibily pushed back one)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) // push chracter back into input
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
// Exercise 4-4. Add commands to print the top element of the stack without
// popping,... to duplicate it, and to swap the top two elements. Add a command
// to clear the stack. □
void top_2_print()
{
    printf("top 2 elements are %g, %g", val[stack_pos], val[stack_pos - 1]);
}
void duplicate(int stack[], int stack2[])
{
    for (int i = 0; i <= stack_pos; i++)
    {
        stack2[i] = stack[i];
    }
}
void swap()
{
    int temp = val[stack_pos];
    val[stack_pos] = val[stack_pos - 1];
    val[stack_pos - 1] = temp;
}
void clear(int stack[])
{
    stack_pos = 0;
}
