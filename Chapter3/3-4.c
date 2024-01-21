// Exercise 3-4. In a two’s complement number representation, our version of
// itoa does not handle the largest negative number, that is, the value of n equal
// to −(2wordsize−1 ). Explain why not. Modify it to print that value correctly,
// regardless of the machine on which it runs. □
#include <stdio.h>
#include <string.h>
void itoa(int n, char s[]);
void reverse(char s[]);
int main()
{
    char s[] = "0123456789abc";
    itoa(-69, s);
    printf("%s\n",s);
    return 0;
}
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        s[i++] = 10 - (n % 10) + '0';
        n = -n;
    /* make n positive */
    i = 0;
    do
    {
        /* generate digits in reverse order */
        s[i++] = n % 10 + '0';
        /* get next digit */
    } while ((n /= 10) > 0);
    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
void reverse(char s[])
{
    char temp;
    //wrong strlen cz 13 is predefined length. Fix  
    for(int i = 0, j = strlen(s) -1; i < j;i++, j-- )
    {
        temp = s[j], s[j] = s[i], s[i] = temp; //swap
    }
}
