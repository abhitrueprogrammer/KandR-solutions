// Exercise 5-5. Write versions of the library functions strncpy, strncat, and
// strncmp, which operate on at most the first n characters of their argument
// strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
// Full descriptions are in Appendix B. □
#include <stdio.h>
#include <string.h>
int strn_cat(char *s, char *c, int n);
int main()
{
    char s[100]  = "Today is going to be ";
    char *c = "a great day";
    strn_cat(s, c,4);
    printf("%s", s);
}
// return 1 if n < len(c)
int strn_cat(char *s,char *t, int n)
{
    while (*s++);
    *s--;
    for(int i = 0; i < n;i++)
    {
        if(*t)
        *s++ = *t++;
    }

}