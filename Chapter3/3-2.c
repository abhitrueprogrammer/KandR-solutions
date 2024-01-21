// Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible
// escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the
// other direction as well, converting escape sequences into the real characters.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void escape(char s[] ,char t[]);
int main()
{
    char s[] = "Today \t is \n going.";
    char *t = malloc(sizeof(s)*2*sizeof(char)); //dunno if sizeof(char) is required
    if (t == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit with an error code
    }
    // char t[] =  "                                                            ";
    escape(s,t);
    printf("%s\n",t);
    free(t);
    return 0;
}
void escape(char s[] ,char t[])
{

    for(int i = 0, j = 0; i < strlen(s) ;i++)
    {
        switch(s[i])
        {
            case '\a':
                t[j++] = '\\';
                t[j++] = 'a';
                break;
            case '\b':
                t[j++] = '\\';
                t[j++] = 'b';
                break;
            case '\e':
                t[j++] = '\\';
                t[j++] = 'e';
                break;
            case '\f':
                t[j++] = '\\';
                t[j++] = 'f';
                break;
            case '\n':
                t[j++] = '\\'; //make this backslashes one except for default case
                t[j++] = 'n';
                break;
            case '\r':
                t[j++] = '\\';
                t[j++] = 'r';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\v':
                t[j++] = '\\';
                t[j++] = 'v';
                break;
            default:
                t[j++] = s[i];
        }
    }
}