//Can make it better by using flags. When encounter / set flag. Another / inside structure and when \n outside. This would handle single line comments.
//Already handled multiline comments.
#include <stdio.h>

int syntax_error(int syntaxArr[]);
int main()
{
    int syntaxArr[5];

    int syntax_err = syntax_error(syntaxArr);
    if (syntax_err)
    {
        printf("Syntax error detected!\n");
        return 1;
    }
    else
    {
        printf("GG\n");
        return 0;
    }
//         get_parentheisis, bracketWrite a program to check a C program for rudimentary syntax
// errors like unbalanced parentheses, brackets and braces. Don’t forget about
// quotes, both single and double, escape sequences, and comments. (This
// program is hard if you do it in full generality.)s and braces and quotes and double quote 
//         if their their mod 2 is even then print not good else print print good
}

int syntax_error(int syntaxArr[])
{
    int parenthesis = 0;
    int braket = 0;
    int brace = 0;
    int doubleQuote = 0;
    int singleQuote = 0;
    int insideStructure = 0;
    int dangerAheadFlag = 0;
    for(int c = 0; (c = getchar()) != EOF; c++)
    {
        putchar(c);
        if (!(insideStructure))
        {   
            if(c == '{')
            {
                brace++;            
            }
            else if(c == '}')
            {
                brace--;
            }
            if(c == '(')
            {
                braket++;
            }
            else if(c == ')')
            {
                braket--;
            }
            if (c == '"')
            {
                doubleQuote++;
                insideStructure = '"';
            }
            if(c == '\'')
            {
                singleQuote++;
                insideStructure = '\'';
            }
            
        }
        else
        {
            if ((c == insideStructure) && !(dangerAheadFlag))
            {
                    insideStructure = 0;
                    if (c == '"')
                    {
                        doubleQuote++;
                    }
                    else if(c == '\'')
                    {
                        singleQuote++;
                    }
            }
            else if (dangerAheadFlag)
            {
                dangerAheadFlag = 0;
            }
            else if(c == '\\')
            {
                dangerAheadFlag = 1;
            }                
        }
   
    }

    printf("No. of unpaired parenthesis: %i\n",parenthesis);        
    printf("No. of unpaired brakets: %i\n",braket);        
    printf("No. of unpaired brace: %i\n",brace);        
    printf("No. of unpaired double quote: %i\n",doubleQuote%2);        
    printf("No. of unpaired single quote: %i\n",singleQuote%2);        

    if (parenthesis == 0 && braket == 0 && brace == 0 && doubleQuote%2 == 0 && singleQuote%2 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}