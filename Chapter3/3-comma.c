/* reverse: reverse string s in place */
#include<stdio.h>
#include <string.h>
void reverse(char s[])
{
int c, i, j;
for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
c = s[i], s[i] = s[j], s[j] = c;
}
}
int main()
{
    char s[] = {'m', 'a','h','a','t','m','a'};
    reverse(s);
    for(int i = 0; i < sizeof(s) / sizeof(s[0]);i++ )
    {
        printf("%c\n",s[i]);
    }
}