#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // input two same string.
    char *i = get_string("s: ");
    char *j = get_string("t: ");

    if (i == j)  // For strings, "==" means to compare the address of two strings. That's why we call the function "strcmp" in the library "string.h" to compare two strings.
        printf("Same\n");
    else
        printf("Different\n");

    printf("%p\n", i);
    printf("%p\n", j);
}