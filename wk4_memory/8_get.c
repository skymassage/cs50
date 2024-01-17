#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x);  // "scanf" can get user input and store it in an address. Note that you should use the address of "x" via "&x" to store user input.
    printf("x is %i.\n", x);

    char s[4];  // Note that if we pre-allocate an array of size "4", we can type a three-character word ("\0") and the program functions.
    // char *s;  // This line can't make program function. Nowhere in this program do we allocate the amount of memory required for our string.
    printf("s: ");
    scanf("%s", s);  // Note that we don't need "&" here, because "s" is an address per se.
    printf("s is %s.\n", s);
}