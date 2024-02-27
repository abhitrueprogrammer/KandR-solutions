// #include <stdio.h>
// #include <stdlib.h>/* for atof() */
// #define MAXOP 100
// #define MAXCHARS 200
// #define NUMBER '0' /* max size of operand or operator */
// /* signal that a number was found */
// int getop(char s[], char line[]);
// void push(double);
// double pop(void);
// /* reverse Polish calculator */
// int main()
// {
//     int lineEnd;
//     int type;
//     double op2;
//     char s[MAXOP];
//     char line[MAXCHARS];
//     while (fgets(line, MAXCHARS, stdin) != NULL)
//     {
//         lineEnd = 0;
//         while(!lineEnd)
//         {
//             type = getop(s, line);
//             switch (type)
//             {
//             case NUMBER:
//                 push(atof(s));
//                 break;
//             case '+':
//                 push(pop() + pop());
//                 break;
//             case '*':
//                 push(pop() * pop());
//                 break;
//             case '-':
//                 op2 = pop();
//                 push(pop() - op2);
//                 break;
//             case '/':
//                 op2 = pop();
//                 if (op2 != 0.0)
//                     push(pop() / op2);
//                 else
//                     printf("error: zero divisor\n");
//                 break;
//             case '\n':
//                 printf("\t%.8g\n", pop());
//                 lineEnd = 1;
//                 break;
//             default:
//                 printf("error: unknown command %s\n", s);
//                 break;
//             }
//         }
//     }
//     return 0;
// }

// #define MAXVAL 100
// int sp = 0;
// double val[MAXVAL];
// /* maximum depth of val stack */
// /* next free stack position */
// /* value stack */
// /* push: push f onto value stack */
// void push(double f)
// {
//     if (sp < MAXVAL)
//         val[sp++] = f;
//     else
//         printf("error: stack full, can't push %g\n", f);
// }
// /* pop: pop and return top value from stack */
// double pop(void)
// {
//     if (sp > 0)
//         return val[--sp];
//     else
//     {
//         printf("error: stack empty\n");
//         return 0.0;
//     }
// }

// #include <ctype.h>
// int getch(void);
// void ungetch(int);

// int getop(char s[], char line[])
// {
//     static int totalbytesRead;
    
//     int charsRead = sscanf(line, "%s%n", s+bytesRead, &bytesRead);
//     += bytesRead
//     if(charsRead < 1)
//     {
//         return '\n';
//     }
//     if (isdigit(*s))
//     {
//         return NUMBER;
//     }
//     else
//     {
//         return *s;
//     }
// }