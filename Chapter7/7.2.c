#include <stdio.h>
#include <ctype.h>

int isgraphic(int c);
int main(void)
{
    int line_len = 0, c;
    int max_len = 40;
    while((c = getchar()) != EOF)
    {
        if(line_len > max_len)
        {
            printf("\n");
            line_len = 0;
        }
        if(c == '\n')
        {
           line_len = 0;
        }
        if(!isgraphic(c))
        {
            printf("x0%x", c);
        }
        else
        {
            putchar(c);
        }
        line_len++;

    }
}
int isgraphic(int c)
{
    // || isspace(c) || iscntrl(c)
    return  isgraph(c) || c == ' ';
}
