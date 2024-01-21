#include <stdio.h>
#include <string.h>
void copy(char s[], char *t)
{
    int i;
    for(i= 0; i < strlen(s); i++ )
    {
        t[i] = s[i];
    }
    printf("%s",t);
}