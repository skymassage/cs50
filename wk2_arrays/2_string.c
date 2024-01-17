#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // string is an array.
    string word = "lin";
    printf("%c %c %c\n", word[0], word[1], word[2]);
    printf("--------------------------------------------\n");

    // Strings can consist of more than a single dimensions.
    string words[2];
    words[0] = "HI!";
    words[1] = "BYE!";
    printf("%s\n", words[0]);
    printf("%c %c %c\n", words[0][0], words[0][1], words[0][2]);
    printf("%s\n", words[1]);
    printf("%c %c %c %c\n", words[1][0], words[1][1], words[1][2], words[1][3]);
    printf("--------------------------------------------\n");

    // Calculate the length of a string.
    string name = get_string("Name? ");
    int n = 0;
    while (name[n] != '\0')  // Every string ends with '\0', call "NUL", so so that the computer knows how many characters are in the string.
    {
        n++;
    }
    printf("The length of the name: %i\n", n);

    // Use the library "string.h" to call the function "strlen" to find the length of a string.
    int length = strlen(name);
    printf("The length of the name: %i\n", length);
    printf("%zu\n", strlen(name)); /* "strlen" doesn't really return an unsigned integer type, it returns a type called "size_t".
                                       "size_t" is an "unsigned int" or "unsigned long", based on your system. Use "%zu" to print it. */
}