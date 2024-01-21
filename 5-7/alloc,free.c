#define ALLOCSIZE 10000 /*size of available space*/

static char allocbuf[ALLOCSIZE]; /*storage for alloc*/
static char *allocpointer = allocbuf; /*next free position*/

char *alloc(int n) /*return pointer to n characters*/
{
    if(allocbuf + ALLOCSIZE - allocpointer >= n)
    {
        allocpointer += n;
        return allocpointer - n; /*old p*/
    }
    else
    
        return 0;
}