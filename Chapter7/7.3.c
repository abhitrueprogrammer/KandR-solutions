// Exercise 7-3. Revise minprintf to handle more of the other facilities of printf.

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
void minprintf(char *fmt, ...);

int main(void)
{
    minprintf("My name is: %s\n", "ur mum");
}

void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    char *buffer;
    buffer = (char *) malloc(5* sizeof(char));
    int ival;
    double dval;
    va_start(ap, fmt);
    for(p = fmt; *p; p++)
    {

        if(*p != '%')
        {
            putchar(*p);
            continue;
            
        }
        char *format;
        format = (char *) malloc(6 *sizeof(char));
        int i = 0;
        while(!isalpha(*p))
        {
                format[i++] = *p++;
        }
        format[i++] = *p;
        switch(*p)
        {
            case 'd':
                ival = va_arg(ap, int);
                printf(format, ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf(format, dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                printf(format,sval);
                break;
            default:
                putchar(*p);
                break;
        }
        va_end(ap);
    }
}