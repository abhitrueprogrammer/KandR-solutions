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
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int main() /*convert declaration to words*/
{
    while (gettoken() != EOF)
    {
        strcpy(datatype, token); /* 1st token on line is the datatype */
        out[0] = '\0';
        dcl();
        if (tokentype != '\n')
            printf("syntax error\n");
        // printf("||%c: tokentype;",tokentype);
        // printf("%s: token;",token);
        // printf("%s: name;",name);
        // printf("%s: out;",out);
        // printf("%s: datatype;||\n", datatype);
        printf("%s: %s %s \n", name, out, datatype);
        
    }
    return 0;
}

void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*';) /*count *s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}
void dirdcl(void)
{
    int type;
    int error = 0;
    if (tokentype == '(') /*(dcl)*/
    {
        dcl();
        if (tokentype != ')')
            printf("error: missing ) \n");
    }
    else if (tokentype == NAME)
        strcpy(name, token);
    else
    {
    printf("error: expected name or (dcl)\n");
    error = 1;
    }
        // printf("||%c: tokentype;",tokentype);
        // printf("%s: token;",token);
        // printf("%s: name;",name);
        // printf("%s: datatype;",out);
        // printf("%s: out;||\n", datatype);
    if(!error)
    {
    while ((type = gettoken()) == PARENS || type == BRACKETS)
    {
        if (type == PARENS)
            strcat(out, " function returning");
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
    }

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