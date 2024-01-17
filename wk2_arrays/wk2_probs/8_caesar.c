// https://cs50.harvard.edu/x/2023/psets/2/caesar/
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (!only_digits(argv[1]))
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    string text = get_string("plaintext:  ");
    int key = atoi(argv[1]);

    printf("ciphertext: ");

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        printf("%c", rotate(text[i], key));
    }

    printf("\n");
    return 0;
}

bool only_digits(string s)
{
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        return 'A' + ((c - 'A' + n) % 26);
    }
    else if (islower(c))
    {
        return 'a' + ((c - 'a' + n) % 26);
    }
    else
    {
        return c;
    }
}