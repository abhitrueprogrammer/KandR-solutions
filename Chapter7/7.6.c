#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: cmp file1 file2");
        return 1;
    }
    FILE *fp1 =  fopen(argv[1], "r");
    FILE *fp2 =  fopen(argv[2], "r");
    int maxline = 250;
    char line1[maxline];
    char line2[maxline];
    while(fgets(line1, maxline, fp1) != NULL && fgets(line2, maxline, fp2) != NULL)
    {
        if(strcmp(line1, line2))
        {
            printf("line in file 1: %s", line1);
            printf("line in file 2: %s", line2);
            return 1;
        }
    }
    return 0;
}