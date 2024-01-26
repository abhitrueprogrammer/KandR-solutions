char *keytab[] = {"auto", "break", "case", "char", "const", "continue", "default", "if", "int", "struct", "unsigned", "void", "volatile", "while"};

struct treenode
{
    char *word;
    int count;
    struct treenode *left;
    struct treenode *right;
};

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getword.h"

#define MAXWORD 100
#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))

struct treenode *addtree(struct treenode *root, char *word);
int binsearch(char *word, char * tab[], int n);
char *stralloc(int size);
void treeprint(struct treenode *root);
int main(int argc, char *argv)
{
    printf("UR MUM");
    printf("||%s||", keytab[6]);
    binsearch("test", keytab,14);
}
int binsearch(char *word, char *tab[], int n)
{
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        printf("%s", tab[mid]);
        printf("%s", word);
        if ((cond = strcmp(word, tab[mid])) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}