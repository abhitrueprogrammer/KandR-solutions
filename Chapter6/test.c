#include <stdio.h>

struct nlist {
    char *name;
    char *defn;
    struct nlist *next;
};
#include <stdio.h>

int main(void)
{
    struct nlist *n;
    printf("%lu\n", sizeof(*n));
}