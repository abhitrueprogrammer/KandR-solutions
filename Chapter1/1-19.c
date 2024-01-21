// Exercise 1-19. Write a function reverse(s) that reverses the character string
// s. Use it to write a program that reverses its input a line at a time. □
#include <stdio.h>
#define MAXLEN 1024
void reverse_string(char str[], char revstr[] ,int len);
int get_line(char str[]);
int main()
{
    char revchr[MAXLEN];
    char chr[MAXLEN];
    int len = get_line(chr);
    reverse_string(chr, revchr, len);
    printf("%s\n", revchr);
    return 0;
}



int get_line(char str[])
{
    int c, len;
    len = 0;
    for(c = 0; (c = getchar()) != EOF && c != '\n' && len < MAXLEN; len++)
    {
        str[len] = c;
    }
    str[len] = '\0';
    return len;
}

void reverse_string(char str[], char revstr[],int len)
{
    
    for(int i = 0; i < len; i++)
    {
       revstr[len-1 - i]  = str[i];
    }
    revstr[len] = '\0';
}