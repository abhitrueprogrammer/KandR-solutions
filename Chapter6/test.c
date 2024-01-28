
struct treenode
{
    int line;
    char *word;
    struct treenode *next;
};

#include <stdio.h>

#include <stdlib.h>
struct treenode *changeTree(struct treenode *root);
int *changeInt(int * x);
int main(int argc, char *argv)
{
    int y = 2;
    int *x;
    x = (int *) malloc(sizeof(int));
    *x = y;
    changeInt(x);
    printf("%i\n", *x);
    
    struct treenode *t1;
    t1 = ( struct treenode *) malloc(sizeof(struct treenode));
    changeTree(t1);
    printf("%i\n", t1 -> line);
}
int *changeInt(int *x)
{
    *x =  9;
    return x;
}

struct treenode *changeTree(struct treenode *root)
{
    root -> line = 69;
    return root;
}