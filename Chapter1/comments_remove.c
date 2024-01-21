#define IN 1
#define OUT 0
#include <stdio.h>

int main(void)
{
    int quote = OUT;
    int characterConstant = OUT;
    int maybeComment  = OUT;
    int comment = OUT;
    int maybecommentout = OUT;
    for(int c = 0;(c = getchar()) != EOF; c++)
    {
        if (maybeComment)
        {
            if (c == '*')
            {
                comment = IN;
                maybeComment = OUT;
            }
            else
            {
                maybeComment = OUT;
                putchar('/');
                putchar(c);
            }
        }
        else if (comment)
        {
            if(maybecommentout)
            {
                if(c == '/')
                {
                    comment = OUT;
                    maybeComment = OUT;
                }
                else
                {
                    maybecommentout = OUT;
                }
            }

            if (c == '*')
            {
                maybecommentout = IN;
            }
        }
        else if (quote)
        {
            putchar(c);
            if (c == '\"')
            {
                quote = OUT;
            }
        }
        else if (characterConstant)
        {
            putchar(c);
            if (c == '\'')
            {
                characterConstant = OUT;
            }
        }
        else if(c == '/')
        {
            maybeComment  = IN;
        }
        else if(c == '\"')
        {
            quote = IN;
            putchar(c);

        }
        else if (c == '\'')
        {
            characterConstant = IN;
            putchar(c);
        }
        else
        {
            putchar(c);
        }
    }
}