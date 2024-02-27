// Exercise 7-7. Modify the pattern finding program of Chapter 5 to take its
// input from a set of named files or, if no files are named as arguments, from
// the standard input. Should the file name be printed when a matching line is
// found?
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void findpattern(FILE *fp, char *pattern, char *filename);
int main(int argc, char *argv[])
{
    char *pattern = argv[1];
    long lineno = 0;
    int c, found = 0;
    char *prog = argv[0];
    if(argc < 2)
    {
        printf("usage: %s pattern ./file1 ./file2 ...", prog);
    }
    FILE *fp;
    if (argc == 2)
    {
        fp = stdin;
        char *filename = "your input";
        findpattern(fp, pattern, filename);
    }
    for(int i = 2; i < argc; i++)
    {
        char *filename = argv[i];
        if((fp = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "%s can't open %s\n", prog, filename);
            return 1;
        }
        findpattern(fp, pattern, filename);
    }
}
void findpattern(FILE *fp, char *pattern, char *filename)
{
    char line[MAXLINE];
    while(fgets(line, MAXLINE, fp) != NULL)
    {
        if(strstr(line, pattern) != NULL)
        {
            printf("Found line in %s\n", filename);
            return;
        }
    }
}
