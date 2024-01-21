// Exercise 5-5. Write versions of the library functions strncpy, strncat, and
// strncmp, which operate on at most the first n characters of their argument
// strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
// Full descriptions are in Appendix B. □
#include <stdio.h>
#include <string.h>
int strn_cmp(char *s, char *c, int n);
int main()
{
    char s[100]  = "Today is going to be ";
    char *c = "Today is going to be ";
    printf("%i", strn_cmp(s, c,4));
    
}
// return == 0 if s = t
int strn_cmp(char *s,char *t, int n)
{
    for(int i = 0; i < n;i++)
    {
        if(*t == '\0')
            return 0;
        if (*s++ != *t++)
            return *s-*t;
    }
    return 0;
}