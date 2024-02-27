#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getword.h"
struct nlist {
    char *name;
    char *defn;
    struct nlist *next;
};

#define HASHSIZE 101
#define MAXWORD 100
// static struct nlist *hashtab[HASHSIZE]; /*pointer table*/
// unsigned hash(char *s);
// struct nlist *lookup(char *s);

// struct nlist *lookup(char *); 
// struct nlist *install(char *name, char *defn);
// struct nlist *undef(char *name);

// int main(void)
// {
//     char s[MAXWORD];
//     while(getword(s,MAXWORD))
//     {
//         printf("%s", s);
//     }

// }
// struct nlist *undef(char *name)
// {
//     struct nlist *lst_pointer;
//     if((lst_pointer = lookup(name)) != NULL)
//     {
//         lst_pointer->defn = lst_pointer->next->defn;
//         lst_pointer->name = lst_pointer->next->name;
//         lst_pointer->next = lst_pointer->next->next;
//         //valgrind wouldn't be happy
//     }
//     else
//     {
//         return NULL;
//     }
// }
// struct nlist *install(char *name, char *defn)
// {
//     struct nlist *np;
//     unsigned hashval;

    
//     if((np = lookup(name)) == NULL) //Not found
//     {
//         np = (struct nlist *) malloc(sizeof(*np));
//         if (np == NULL || (np -> name = strdup(name)) == NULL)
//         {
//             return NULL; //return not found
//         }
//         hashval = hash(name);
//         np -> next = hashtab[hashval];
//         hashtab[hashval] = np;
//     }
//     else /*already there*/
//         free((void *) np -> defn);
//     if((np -> defn = strdup(defn)) == NULL)
//         return NULL;
//     return np;
// }



// struct nlist *lookup(char *s)
// {
//     struct nlist *np;
    
//     for(np = hashtab[hash(s)]; np != NULL; np = np -> next)
//     {
//         if (strcmp(s, np -> name) == 0)
//             return np;
//     }
//     return NULL; // Not found
// }
// unsigned hash(char *s)
// {
//     unsigned hashval;

//     for(hashval = 0; *s != '\0'; s++)
//     {
//         hashval = *s + 31 * hashval;
//     }
//     return hashval;
// }
