// Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa;
// that is, convert an integer into a string by calling a recursive routine. □
#include <stdio.h>

int itoa(int n, char s[], int i);

int main()
{

    char s[] = "0123456789abc";
    itoa(-69, s, 0);   
    printf("%s\n", s);
}
// put the number n in the string s. I is index of the string that has meaningful information
int itoa(int n, char s[], int i)
{
    if (n < 0)
    {
        s[0] = '-';
        i++;
        n = -n;
    }
    if (n / 10) // if the character has one than more digits
        i = itoa(n/10, s, i);
    s[i] = n % 10 + '0'; // assign reminader to s[i]
    i++;
    s[i] = '\0'; // end the string after the digits occupied after each call
    return i;//set i as static
}
