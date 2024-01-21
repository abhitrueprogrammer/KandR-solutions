// Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t
// occurs at the end of the string s, and zero otherwise. □
#include <stdio.h>
#include <string.h>
int strend(char *s, char *t);
int main(void)
{
    char *s = "Today is going to be a great day";
    char *t = "day";
    if (strend(s, t))
    {
        printf("t occurs at the end of s\n");
    }
    
    return 0;
}
int strend(char *s, char *t)
{
    while (*s++)
        ; // gets to the end of the string +1
    int len_e = strlen(t);
    while (*t++)
        ;
    // printf("%s\n",s); //it prints t lol 
    while (len_e--)
    {
        if (*--s != *--t)
            return 0;
    }
    return 1;
}