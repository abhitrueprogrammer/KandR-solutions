#include <stdio.h>
void st_cpy(char *s, char *t);
int main(void)
{
    char *s = "The ambition of greatest men of 20th century was to remove every tear from every eye";
    char *t = "Today is going to be a great day\0";
    st_cpy(s, t);
    // printf("%s", t);
    return 0;
}

void st_cpy(char *s, char *t)
{
while (*s++ = *t++)
;
}