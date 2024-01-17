// compare two strings by calling function
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool check_phrase(string phrase);

int main(void)
{
    string phrase = get_string("What's the secret phrase? ");
    bool correct = check_phrase(phrase);

    if (correct == true)
    {
        printf("Come on in!\n");
    }
}

bool check_phrase(string phrase)
{
    string password = "Please";

    /* Notice that we cannot utilize "==" to compare two strings like this: "phrase == password".
       We have to call the function "strcmp(str1, str2)", which comes from the "string.h" library.
       If the return is positive: str1 > str2; if the return is negative: str1 < str2
       If the return is 0: str1 is the same as str2 */
    if (strcmp(phrase, password) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}