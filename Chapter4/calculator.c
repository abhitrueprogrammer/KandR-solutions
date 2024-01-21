#include <stdio.h>
#include <stdlib.h>/* for atof() */

#define MAXOP 100  /*Max size of operator*/
#define NUMBER '0' /*Signal that a number has been found*/

int getop(char[]);
void push(double);
double pop(void);

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
#include <ctype.h>

int getch(void);
void ungetch(int);
//getop: get the next operator or numeric operand
int getop(char s[])
{
    int i, c;
    
    while (((s[0] = c = getch()) == ' ') || c == '\t');
    s[1] = '\0';
    if(!isdigit(c) & c != '.')
        return c; /*not a number*/
    i = 0;
    if (isdigit(c)) 
        while (isdigit(s[++i] = c = getch())); /*collect integer part*/
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
#define BUFSIZE 100
char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf
int getch(void) // get a character(possibily pushed back one)
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
