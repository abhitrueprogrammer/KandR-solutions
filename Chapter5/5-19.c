#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum
{
    NAME,
    PARENS,
    BRACKETS
};

void dcl(void);
void dirdcl(void);
int getch(void);
void ungetch(int c); /* push character back on input */
int gettoken(void);
int tokentype;
int waspointer;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

/* undcl: convert word description to declaration */
int /* undcl: convert word description to declaration */
main()
{
    int type;
    waspointer = 0;
    char temp[MAXTOKEN*15];
    while (gettoken() != EOF)
    {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
            if (type == PARENS || type == BRACKETS)
            {
                if(waspointer)
                {
                sprintf(temp, "(%s)", out);
                strcpy(out, temp);
                waspointer = 0;
                }
                strcat(out, token);
            }
            else if (type == '*')
            {
                sprintf(temp, "*%s", out);
                waspointer = 1; // put brackets rectroactively
                strcpy(out, temp);
            }
            else if (type == NAME)
            {
                sprintf(temp, "%s %s", token, out); // how would char be added tho? Same as this? Prolly
                strcpy(out, temp);
            }
            else
                printf("invalid input at %s\n", token);
        printf("%s\n", out);
    }
    return 0;
}

int gettoken(void) /* return next token*/
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
        return tokentype = c;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
/* buffer for ungetch */
/* next free position in buf */
int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}