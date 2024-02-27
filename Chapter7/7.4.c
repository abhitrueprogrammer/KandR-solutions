#include <stdio.h>
#include <stdarg.h>

struct linkedList
{
    //Change to that which changes its type automagically C
    union u_tag {
        int  *ivals;
        float *fvals;
        char *svals;
    } u;
    struct linkedList *next;
};

void minscanf(char *text, ...);

int main(void)
{
    return 0;
}
/*this version doesn't handle string matching. Deal with it.*/
void minscanf(char *text, ...)
{
    va_list varList;
    va_start(varList, text);
    char * start;
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == '%')
        {
            
            if(text[i++] == 'd')
            {
                scanf("%d", va_arg(varList, int *));
            }                
            else if(text[i++] == 'f')
            {
                scanf("%f", va_arg(varList, float *));
            }
            else if(text[i++] == 's')
            {
                scanf("%s", va_arg(varList, char *));
            }   
        }
    }

}
