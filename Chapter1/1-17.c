#include <stdio.h>
#define MAXLINE 1000  /*maximum input line size*/
int get_line(char line[], int maxline);
int remove_trailing_space(char line[], int len);
void copy(char to[], char from[]);
//print longest input line
int main()
{
    int len; // current line length
    char line[MAXLINE]; // current input line
    char longest[MAXLINE]; // longest line saved here
    while((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%i\n",len);
    }
    return 0;
}

// get_line: read a line into s, return length 
int get_line(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c!= '\n'; i++)
    {
        s[i] = c;
    }
    if (c=='\n')
    {
        s[i] = c;
        i++;
    }
    return remove_trailing_space(s, i);
}
// copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        i++;
}
int remove_trailing_space(char line[], int len)
{
    len = len -1; //remove %i from picture
    int test = (line[len-1] != ' ' && line[len-1] != '\t');
    if (len == 0 || test )
    {
        line[len] = '\0';
        return len;
    }
    else
    {
        // printf("Condition didn't meet");
        remove_trailing_space(line, len - 1);
    }
}
