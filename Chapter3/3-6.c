Exercise 3-6. Write a version of itoa that accepts three arguments instead of
two. The third argument is a minimum field width; the converted number must
be padded with blanks on the left if necessary to make it wide enough. □void itoa(int n, char s[])
#include <string.h>
#include <stdio.h>
void itoa(int n, char s[], int minimum_field_width );
void reverse(char s[], int minimum_field_width);

int main()
{
    char s[] = "0123456789abc";
    int minimum_field_width = 5;
    //in reversing check strlen and if less do padding
    itoa(69, s, minimum_field_width);
    printf("%s", s);
    return 0;
}
/* itoa: convert n to characters in s */
void itoa(int n, char s[], int minimum_field_width )
{
int i, sign;
if ((sign = n) < 0) /* record sign */
n = -n;
/* make n positive */
i = 0;
do {
/* generate digits in reverse order */
s[i++] = n % 10 + '0';
/* get next digit */
} while ((n /= 10) > 0);
/* delete it */
if (sign < 0)
s[i++] = '-';
s[i] = '\0';
reverse(s, minimum_field_width);
}
/* reverse: reverse string s in place */
void reverse(char s[], int minimum_field_width)
{
int i, c, j;
int str_len =strlen(s);
if  (str_len < minimum_field_width)
{
    for(i = 0; i< 10 - str_len; i++)
    {
        s[i] = " ";
    }
}
for ( j = (10 - str_len)+ strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
}
}
