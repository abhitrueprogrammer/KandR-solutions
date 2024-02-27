#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct nlist {
    char *name;
    char *defn;
    struct nlist *next;
};

#define HASHSIZE 101
#define MAXWORD 100
static struct nlist *hashtab[HASHSIZE]; /*pointer table*/
unsigned hash(char *s);
struct nlist *lookup(char *s);

struct nlist *lookup(char *);
struct nlist *install(char *name, char *defn);
struct nlist *undef(char *name);
int getword(char *word, int lim, FILE * fp);

#define A 100
int main(void)
{
    char s[MAXWORD];
    int c = 0;
    struct nlist *np;
    FILE *ofp = fopen("output.c", "w");

    while((c  = getword(s,MAXWORD, ofp)) != EOF)
    {
        if(c)
        {
            if(strcmp(s, "#") == 0)
            {
                fputs(s, ofp); //putting on s
                getword(s, MAXWORD, ofp);
                //while(getword(s, MAXWORD, fp) == 0);
                if(strcmp(s, "define") == 0)
                {
                    fputs(s, ofp); //putting on define
                    while(getword(s, MAXWORD, ofp) == 0);
                    fputs(s, ofp); //putting on the name
                    char *name = malloc(strlen(s)*sizeof(char)+1);
                    strcpy(name, s);
                    // char name[MAXWORD] = s;
                    while(getword(s, MAXWORD, ofp)== 0);
                    //last word np lookup will handel
                    fflush(stdout);
                    install(name,s);
                }
                if(strcmp(s, "undef") == 0)
                {
                    fputs(s, ofp); //putting on undef
                    while(getword(s, MAXWORD, ofp)== 0);
                    undef(s);
                }
            }
            if(np = lookup(s))
            {
                fputs(np->defn, ofp);
            }
            else
            {
                fputs(s, ofp);
            }

        }
    }
}
struct nlist *undef(char *name)
{
    struct nlist *lst_pointer;
    if((lst_pointer = lookup(name)) != NULL)
    {
        lst_pointer->defn = lst_pointer->next->defn;
        lst_pointer->name = lst_pointer->next->name;
        lst_pointer->next = lst_pointer->next->next;
        //valgrind wouldn't be happy
    }
    else
    {
        return NULL;
    }
}
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    
    if((np = lookup(name)) == NULL) //Not found
    {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np -> name = strdup(name)) == NULL)
        {
            return NULL; //return not found
        }
        hashval = hash(name);
        np -> next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else /*already there*/
        free((void *) np -> defn);
    if((np -> defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}



struct nlist *lookup(char *s)
{
    struct nlist *np;
    
    for(np = hashtab[hash(s)]; np != NULL; np = np -> next)
    {
        if (strcmp(s, np -> name) == 0)
            return np;
    }
    return NULL; // Not found
}
unsigned hash(char *s)
{
    unsigned hashval;

    for(hashval = 0; *s != '\0'; s++)
    {
        hashval = *s + 31 * hashval;
    }
    return hashval% HASHSIZE;
}
