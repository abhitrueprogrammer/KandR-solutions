#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    int c = getchar();

    if(strcmp(argv[0], "./up") == 0)
    {
        putchar(toupper(c));
    }
    else if(strcmp(argv[0], "./low") == 0)
    {
        putchar(tolower(c));
    }
    else
    {
        char *wrong = "The accepted file names are 'up' or 'lower'";
        for(int i = 0; wrong[i] != '\0'; i++)
        {
            putchar(wrong[i]);
        }
    }
    putchar('\n');
    return 0;
}