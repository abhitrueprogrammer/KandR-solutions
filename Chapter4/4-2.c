// Exercise 4-2. Extend atof to handle scientific notation of the form
// 123.45e-6
// where a floating-point number may be followed by e or E and an optionally
// signed exponent. □
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100
/* rudimentary calculator */
int main()
{
    double sum, atof(char[]);
    char line[MAXLINE];
    int get_line(char line[], int max);
    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i]== 'e')
        i++;
    int expsign, expval = 0, exp =1;
    expsign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (expval = 0; isdigit(s[i]); i++)
        expval = 10 * val + (s[i] - '0');
    for(int i = 0; i < expval; i++)
    {
        exp *= 10;
    }
    return (expsign >0) ?exp*sign * val / power: sign*val/(power*exp);
}
/* getline: get line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}