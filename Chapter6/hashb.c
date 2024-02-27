#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getword.h"
struct nlist
{
    /* table entry: */
    struct nlist *next;
    /* next entry in chain */
    char *name;
    /* defined name */
    char *defn;
    /* replacement text */
};
#define HASHSIZE 101
#define MAXWORD 100
static struct nlist *hashtab[HASHSIZE];
/* pointer table */
unsigned hash(char *s);
struct nlist *lookup(char *s);

struct nlist *lookup(char *);
struct nlist *install(char *name, char *defn);
struct nlist *undef(char *name);
#define A 100
int main(void)
{
    char s[MAXWORD];
    int c = 0;
    while((c  = getword(s,MAXWORD)) != EOF)
    {
        if(c)
        {
            if(strcmp(s, "#") == 0)
            {
                while(getword(s, MAXWORD) == 0);
                if(strcmp(s, "define") == 0)
                {
                    while(getword(s, MAXWORD) == 0);
                    char *name = malloc(strlen(s)*sizeof(char)+1);
                    strcpy(name, s);
                    // char name[MAXWORD] = s;
                    while(getword(s, MAXWORD)== 0);
                    printf("%s|%s\n", name, s);
                    fflush(stdout);
                    install(name,s);
                }
                if(strcmp(s, "#undef") == 0)
                {
                    while(getword(s, MAXWORD)== 0);
                    remove(s);
                }
            }
            // printf("%s\n", s);
            
        }
    }
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}
/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    /* found */
    return NULL;
    /* not found */
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL)
    { /* not found */
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
        /* already there */
        free((void *)np->defn);
    /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}