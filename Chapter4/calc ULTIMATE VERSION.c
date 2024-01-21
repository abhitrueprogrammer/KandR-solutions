#include <stdio.h>
#include <stdlib.h>/* for atof() */
#include <math.h>
#include <string.h>
#include <ctype.h>
#define MAXSTR 1000 /*The issue with getline approach. You gotta specify the size of line beforehand*/
#define MAXOP 100  /*Max size of operator*/
#define NUMBER '0' /*Signal that a number has been found*/
#define FUNC '1'   /*signal that function has been found*/

void push(double);
double pop(void);
int getnum(char num_str[], char s[], int i);// Exercise 4-6. Add commands for handling variables. (It’s easy to provide
int getfunc(char func_str[], char s [], int i);
// twenty-six variables with single-letter names.) Add a variable for the most
// recently printed value. □
// Exercise 4-5. Add access to library functions like sin, exp, and pow. See
// <math.h> in Appendix B, Section 4. □

/*reverse Polish Calculator*/

int main()
{
    int cur_var;
    double op2;
    char s[MAXSTR] = {0};
    double ans;
    double vars[26] = {0};
    // for(int i = 'A'-'A'; i < 'Z'-'A'; i++)
    // {
    //     vars[i] = 0;
    // }
    // set all as 0, without equal sign store in stack without confirming otherwise if = found then pop A and set its val and then push.

    while (1) // break if the loop encounters \0
    {
        fgets(s, MAXSTR, stdin); // would be awesome if it returns a string but I don't think it does.
        printf("%s",s);
        for(int i = 0, c = 0; (c = s[i]) !='\0'; i++)
        {
            while ((( c = s[i]) == ' ') || c == '\t')
            i++;
            switch (c)
            {
            case '.':
            case '0' ... '9':
                char num_str[MAXOP];
                i = getnum(num_str, s, i);
                push(atof(num_str));
                break;
            case 'a'... 'z':
                char func_str[MAXOP];
                i = getfunc(func_str, s, i);
                if (!strcmp("sin", func_str))
                {
                    printf("Inside sin");
                    push(sin(pop()));
                }
                else if (!strcmp("cos", func_str))
                    push(cos(pop()));
                else if (!strcmp("exp", func_str))
                    push(exp(pop()));
                else if (!strcmp("pow", func_str))
                {
                    op2 = pop();
                    push(pow(pop(), op2));
                }
                else if(!strcmp("ans", func_str))
                {
                    push(ans);
                }
                else
                    printf("ERROR unknown func %s\n", func_str);
                break;
            case 'A' ... 'Z':
                //its pushing current value of variable and not variable name
                cur_var = c-'A';
                push(vars[cur_var]);
                break;
            case '=':
                int c = 0;
                pop();
                vars[cur_var] = pop();
                printf("\tVARIABLE ASSIGNED\n");
                while ((( c = s[i]) == ' ') || c == '\t')
                i++;
                if(c = s[++i] == '\n')
                {
                    i++;
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
            //maybe would have to return to pre /n = days
                ans = pop();
                printf("\t%.7f\n", ans);
                break;
            default:
                printf("ERROR unknown command %s\n", s);
                break;
            }
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

int getnum(char num_str[], char s[], int i)
{
    int num_str_index = 0;
    /* collect integer part */
    while (isdigit(num_str[num_str_index++]=s[i++]))
    ;
    if (num_str[num_str_index] == '.')
    /* collect fraction part */
    while (isdigit(num_str[num_str_index++] = s[i++]))
    ;
    num_str[--num_str_index] = '\0'; //reducing by 1 since in while loop the value of num_str gets preassigned. 
    i--;  //reducing by 1 since in while loop the value of i gets incremented before cheecking. 
    return i;
}
// returns new str_index i 
int getfunc(char func_str[], char s [], int i)
{
    int func_str_index = 0; // shows writable spots
    int c;
    for (;((c= s[i]) != '\n' && c != '\t' && c  != ' ' && !isdigit(c)); i++)
    {
        func_str[func_str_index++] = c;
    }
    func_str[func_str_index++] = '\0';
    if (c != EOF)
        i--;
    return i;
}