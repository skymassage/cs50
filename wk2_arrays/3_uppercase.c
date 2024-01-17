// Convert all lowercase characters to uppercase ones.
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
    // Method 1
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z') //  if (islower(s[i]))
        {
            printf("%c", s[i] - 32);  // According to the ASCII values chart. If the character is lowercase, it subtracts the value 32 from it to convert it to uppercase.
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    */

    // Method 2 (more efficient): call functions from the library ctype.h
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)  // You can declare "n = strlen(s)" in the parentheses to avoid asking the string length every iteration.
    {
        printf("%c", toupper(s[i]));  // convert lowercase to uppercase using the fuction "toupper" from the library "ctype.h".
    }
    printf("\n");
}