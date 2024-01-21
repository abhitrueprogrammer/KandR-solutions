// Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into
// a base b character representation in the string s. In particular, itob(n,s,16)
// formats n as a hexadecimal integer in s. □Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into
// a base b character representation in the string s. In particular, itob(n,s,16)
// formats n as a hexadecimal integer in s. □
#include <stdio.h>
#include <string.h>
void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    char s[] = "-0123456789a";
    itob(69,s,16);
    printf("%s\n",s );
    return 0;
}
//negative
void itob(int n, char s[], int b)
{
    int i = 0;
    //sign blyat
    char sign = n < 0 ?  n = -n, -1: 1 ;
    //sign blyat
    do
    {
        int numGreater = n % b; // + '0'
        if (numGreater > 9)
        {
            numGreater = numGreater%10 + 'A';
        }
        else
        {
            numGreater = numGreater + '0';
        }
        s[i++] = numGreater;
        n /= b;
    }
    while(n != 0);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
    // printf("FR%iFR",i);
    s[i] = '\0';
}
// void reverse(char s[],int j)
// {
//     char temp;

//     for(int i = 0; i < j;i++, j-- )
//     {
//         temp = s[j], s[j] = s[i], s[i] = temp; //swap
//     }
// }

void reverse(char s[])
{
    char temp;
    //wrong strlen cz 13 is predefined length. Fix  
    for(int i = 0, j = strlen(s) -1; i < j;i++, j-- )
    {
        temp = s[j], s[j] = s[i], s[i] = temp; //swap
    }
}
