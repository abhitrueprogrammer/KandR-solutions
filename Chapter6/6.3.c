// Exercise 6-3. Write a cross-referencer that prints a list of all words in a
// document, and, for each word, a list of the line numbers on which it occurs.
// Remove noise words like “the,” “and,” and so on. □
// Exercise 6-2. Write a program that reads a C program and prints in alpha-
// betical order each group of variable names that are identical in the first 6
// characters, but different somewhere thereafter. Don’t count words within
// strings and comments. Make 6 a parameter that can be set from the command
// line. □
const char *noise_words[] = {
     "a", "an", "and", "are", "as", "at", "by", "for", "from",
    "in", "in", "is", "it", "of", "on", "or", "that", "the", "this",
    "to", "with"
};
// creating a singly linked list for this one
struct treenode
{
    int line;
    char *word;
    struct treenode *next;
};

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getword.h"

#define MAXWORD 100
#define NKEYS (sizeof(noise_words) / sizeof(noise_words[0]))

struct treenode *addtree(struct treenode *root, char *word, int l);
int binsearch(char *word, const char *tab[], int n);
char *stralloc(int size);
void treeprint(struct treenode *root);
struct treenode *talloc();

int main(int argc, char *argv)
{
    // printf("||%s||", keytab[6]);
    struct treenode *root;
    char word[MAXWORD];
    int c;
    int l = 2;
    root = NULL;
    while ((c = getword(word, MAXWORD)) != EOF)
    {

        if(c == '\n')
        {
            l++;
        }
        if (isalpha(word[0]))
        {
            if (( binsearch(word, noise_words, NKEYS)) == -1) //make lower(word)
            {
                root = addtree(root, word, l); 
            }

        }
    }
    treeprint(root);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, const char *tab[], int n)
{
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if ((cond = strcmp(tab[mid], word)) < 0)
        {
            low = mid + 1;
        }
        else if (cond > 0)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}
// singly linked list would be better here no?
struct treenode *addtree(struct treenode *root, char *word, int l) // int line? or int nline? :thinking:
{
    int compare;
    // printf(" %s ", word);

    if (root == NULL)
    {
        root = talloc();
        root->line = l;
        root->word = strdup(word);
        root->next = NULL;
    }
    else
    {
        root -> next = addtree(root->next, word, l);
    }
    return root;
}
#include <stdlib.h>
struct treenode *talloc()
{
    struct treenode *p = malloc(sizeof(struct treenode));
    if (p == NULL)
        printf("Lag gaye");
    return p;
}
void treeprint(struct treenode *p)
{
    if (p != NULL)
    {
        printf("%4d %s\n", p->line, p->word);
        treeprint(p->next);
    }
    else
    {
        printf("OOF");
    }
}