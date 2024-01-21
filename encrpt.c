#include <stdio.h>
#include <string.h>  
void strrev(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main()
{
char message[] = "HELLO CSI :D";
strrev(message);
char * key = "key";
for(int i = 0; i < strlen(message) && i < strlen(key); i++)
{
message[i] += key[i];
}
printf("%s", message);
}