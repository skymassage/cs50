// https://cs50.harvard.edu/x/2023/psets/2/substitution/
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_letter(string s);
bool repeated_characters(string s);
char rotate(char c, string upper, string lower);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (!(strlen(argv[1]) == 26))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            if (!only_letter(argv[1]))
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
            else
            {
                if (repeated_characters(argv[1]))
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    string text = get_string("plaintext:  ");
    string key = argv[1];

    // Make uppercase and lowercase keys for easy encryption.
    char upper_key[26], lower_key[26];
    for (int i = 0; i < 26; i++)
    {
        upper_key[i] = toupper(key[i]);
        lower_key[i] = tolower(key[i]);
    }

    printf("ciphertext: ");

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        printf("%c", rotate(text[i], upper_key, lower_key));
    }

    printf("\n");
    return 0;
}

bool only_letter(string s)
{
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

bool repeated_characters(string s)
{
    // Convert the key to the same case for easier checking. It's OK for uppercase or lowercase.
    char upper[26];
    for (int i = 0; i < 26; i++)
    {
        upper[i] = toupper(s[i]);
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (upper[j] == upper[i])
            {
                return true;
            }
        }
    }

    return false;
}

char rotate(char c, string upper, string lower)
{
    if (isupper(c))
    {
        return upper[c - 'A'];
    }
    else if (islower(c))
    {
        return lower[c - 'a'];
    }
    else
    {
        return c;
    }
}