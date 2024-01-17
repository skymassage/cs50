// Check if a lowercase string's characters are in alphabetical order. If yes, print "Yes". If no, print "No".
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");

    for (int i = 0, length = strlen(word); i < length - 1; i++)
    {
        if (word[i] > word[i + 1])
        {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    return 0;
}