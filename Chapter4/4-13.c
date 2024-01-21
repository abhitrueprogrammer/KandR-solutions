// Exercise 4-13. Write a recursive version of the function reverse(s), which
// reverses the string s in place. □
#include <stdio.h>
#include <string.h>
void reverse(char s[], int low, int high);
int main(void)
{
    char s[] = "abhitruechamp";
    reverse(s,0,strlen(s)-1);
    printf("%s", s);
    return 0;
}
void reverse(char s[], int low, int high)
{
    void swap(char s[], int low, int high);
    if (high <= low)
    {
        return;
    }
    else
    {
        reverse(s, low+1, high -1);
        swap(s, low, high);
    }
}
void swap(char v[], int i, int j)
{
int temp;
temp = v[i];
v[i] = v[j];
v[j] = temp;
}