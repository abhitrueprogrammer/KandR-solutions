// Exercise 6-2. Write a program that reads a C program and prints in alpha-
// betical order each group of variable names that are identical in the first 6
// characters, but different somewhere thereafter. Don’t count words within
// strings and comments. Make 6 a parameter that can be set from the command
// line. □
char *keytab[] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed", "sizeof",
    "static", "struct", "switch", "typedef", "union", "unsigned", "void",
    "volatile", "while", "_Packed", "_Bool", "_Complex", "_Imaginary"
};

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
struct treenode *talloc();

int main(int argc, char *argv)
{

    // printf("||%s||", keytab[6]);
    struct treenode *root;
    char word[MAXWORD];
    int n = 6; // get from constole
    if(argc > 1)
    {
        n = argv[1];
    }
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))

        {
            char *w;
            int wordLen = strlen(word);
            wordLen =  n - wordLen > 0 ? wordLen: n;
            w = stralloc(wordLen);
            strncpy(w, word, wordLen);
            if ((binsearch(w, keytab, NKEYS)) == -1)
                root = addtree(root, w); // made the word only n characters.
        }

    treeprint(root);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, char *tab[], int n)
{
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((cond = strcmp(tab[mid],word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
struct treenode *addtree(struct treenode *root, char *word)
{
    int compare;
    // printf(" %s ", word);
    if (root == NULL)
    {
        root = talloc();
        root->count = 1;
        root->word = word;
        root->left = NULL;
        root->right = NULL;
    }
    else if (( compare = strcmp(word, root->word)) < 0)
    {
        root -> left = addtree(root->left, word);
    }
    else if (compare > 0)
    {
        root -> right = addtree(root->right, word);
    }
    else
    {
        int abhinavpant;
        int abhinavpant2;
        (root->count)++;
    }
    return root;
}
#include <stdlib.h>
char *stralloc(int size)
{
    // malloc returning nuLLL TWT
    char *p = malloc(size);
    if(p == NULL)
        printf("Lag gaye");
    return p;
}
struct treenode *talloc()
{
    struct treenode *p = malloc(sizeof(struct treenode));
    if(p == NULL)
        printf("Lag gaye");
    return p;
}
void treeprint(struct treenode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}