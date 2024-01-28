// Exercise 6-4. Write a program that prints the distinct words in its input sorted
// into decreasing order of frequency of occurrence. Precede each word by its
// count.
//first record them all then sort them in a tree?
char *noise_words[] = {
     "a", "an", "and", "are", "as", "at", "by", "for", "from",
    "in", "in", "is", "it", "of", "on", "or", "that", "the", "this",
    "to", "with"
};

struct treenode
{
    char *word;
    int count;
    struct treenode *next;
};

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getword.h"

#define MAXWORD 100
#define NKEYS (sizeof(noise_words) / sizeof(noise_words[0]))

struct treenode *addtree(struct treenode *root,struct treenode *prev_root , char *word); // int line? or int nline? :thinking:
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
            if ((binsearch(word, noise_words, NKEYS)) == -1)
                root = addtree(root, root ,word); // made the word only n characters.
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
struct treenode *addtree(struct treenode *root,struct treenode *prev_root , char *word) // int line? or int nline? :thinking:
{
    int compare;
    // printf(" %s ", word);
    // 1, 1, 2

    if (root == NULL)
    {
        root = talloc();
        root->count = 1;
        root->word = strdup(word);
        root->next = NULL;
    }
    else if(strcmp(root-> word, word) == 0)
    {
        root -> count++;
    }
    else
    {
        root -> next = addtree(root->next, root ,word);
    }
        
    if(strcmp(root-> word, word) == 0)
    {
        //swap
        if (prev_root != NULL &&root -> count > prev_root -> count) // of not next but prev. Double linked lists ig
        {
            
            prev_root -> count++; //increment the next node's count by 1
            root -> count --;
            char *temp = root -> word;
            root -> word = (prev_root) -> word; 
            (prev_root) -> word = temp;
        }
            
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
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->next);
    }
}