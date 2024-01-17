// Write a function to replace vowels with numbers: a becomes 6, e becomes 3, i becomes 1, o becomes 0 and u does not change.
// Your program must accept a single command-line argument, which will be the word that you want to convert.
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("%s\n", replace(argv[1]));
    }
    else
    {
        printf("Usage: %s word\n", argv[0]);
    }
}

string replace(string word)
{
    int i = 0;
    while (word[i] != '\0')  // for (int i = 0, length = strlen(word); i < length; i++)
    {
        switch (word[i])
        {
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
            default:
                break;
        }
        i++;
    }

    return word;
}