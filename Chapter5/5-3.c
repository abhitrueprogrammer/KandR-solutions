#include <stdio.h>

void str_cat(char *s,char *t);

int main(void)
{
    char s[1000] = "Today is going to be a great day";
    char *t = "The ambition of greatest men of 20th century was to remove every tear from every eye";
    str_cat(s, t);
    printf("%s\n", s);
    return 0;
}

void str_cat(char *s,char *t)
{
    while (*s++);
    *s--;
    while(*s++ = *t++);
}