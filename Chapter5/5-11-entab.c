// Exercise 5-11. Modify the programs entab and detab (written as exercises
// in Chapter 1) to accept a list of tab stops as arguments. Use the default tab
// settings if there are no arguments. □
// Exercise 1-20. Write a program detab that replaces tabs in the input with
// the proper number of blanks to space to the next tab stop. Assume a fixed
// set of tab stops, say every n columns. Should n be a variable or a symbolic
// parameter? □
#include <stdio.h>
int main(int argc, char *argv[])
{
    int c;
    if (argc > 2)
    {
        printf("usuage: ./5-11 \"tabstop\"");
    }
    char tabstop = argc > 1 ? *argv[1] : ' ';
    int space_number = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            while ((c = getchar()) == ' ')
                space_number++;
            int number_tab = space_number / 4;
            space_number = space_number % 4;
            for (int i = 0; i < number_tab; i++)
                putchar(tabstop);
            for (int i = 0; i < space_number; i++)
                putchar(' ');
            putchar(c);
        }
        else
        {
            putchar(c);
        }
    }
    return 0;
}